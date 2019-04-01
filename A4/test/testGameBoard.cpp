#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

#include "catch.h"
#include "CardTypes.h"
#include "GameBoard.h"


/**
 * NOTE: To cautious readers! Many of these tests would be cleaner if
 * the equality (==) operator was overloaded for CardT. This has been
 * omitted for accessibility. I encourage those comfortable with C++ to
 * read more about it though :)
 *
 * You can find an example here:
 * https://gitlab.cas.mcmaster.ca/smiths/se2aa4_cs2me3/blob/master/Assignments/PreviousYears/2018/A3/A3Soln/implementation/include/PointADT.h#L21
 */

std::vector<CardT> new_valid_deck() {
  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }

  return d;
}

std::vector<CardT> new_deck_missing_suit() {
  std::vector<CardT> d;
  for (RankT rank = ACE; rank <= KING; rank++) {
    // Note: Deliberately skipping last Suit
    for (unsigned int suit = 0; suit < 3; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }

  return d;
}

std::vector<CardT> new_deck_missing_rank() {
  std::vector<CardT> d;
  // Note: Deliberately skipping KING
  for (RankT rank = ACE; rank < KING; rank++) {
    for (unsigned int suit = 0; suit < 4; suit++) {
      CardT n = { static_cast<SuitT>(suit), rank };
      d.push_back(n);
      d.push_back(n);
    }
  }

  return d;
}

TEST_CASE("tests for GameBoard", "[BoardT]") {

  SECTION("constructor orders two decks into the correct placement, board getters") {
    std::vector<CardT> decks = new_valid_deck();
    std::random_shuffle(decks.begin(), decks.end());
    // Empty foundation and waste
    BoardT board(decks);
    for (int i = 0; i < 8; i++) {
      REQUIRE(board.get_foundation(i).size() == 0);
    }
    REQUIRE(board.get_waste().size() == 0);

    // [40,104) is used for deck
    bool isDeckCorrect = true;
    std::vector<CardT> d = board.get_deck().toSeq();
    for (unsigned int i = 40; i < 104; i++) {
      if (!(d[i - 40].r == decks[i].r && d[i - 40].s == decks[i].s)) {
        isDeckCorrect = false;
        break;
      }
    }
    REQUIRE(isDeckCorrect);

    // [0,40) is used for tableaus, meets tab_deck spec
    bool isTableauCorrect = true;
    for (unsigned int i = 0; i < 10; i++) {
      std::vector<CardT> t = board.get_tab(i).toSeq();
      if (t.size() != 4) {
        isTableauCorrect = false;
        break;
      }

      for (unsigned int j = 0; j < 4; j++) {
        if (!(decks[4 * i + j].r == t[j].r && decks[4 * i + j].s == t[j].s)) {
          isTableauCorrect = false;
          break;
        }
      }
    }
    REQUIRE(isTableauCorrect);
  }

  SECTION("constructor throws invalid_argument for invalid deck") {
    REQUIRE_THROWS_AS(
      BoardT(new_deck_missing_suit()),
      std::invalid_argument
    );
    REQUIRE_THROWS_AS(
      BoardT(new_deck_missing_rank()),
      std::invalid_argument
    );
  }

  SECTION("is_valid_tab_mv throws out_of_range") {
    BoardT board(new_valid_deck());
    REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau, 0, 10), std::out_of_range);
    REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau, 10, 0), std::out_of_range);
    REQUIRE_THROWS_AS(board.is_valid_tab_mv(Foundation, 0, 8), std::out_of_range);
  }

  SECTION("is_valid_tab_mv always false for Deck/Waste") {
    BoardT board(new_valid_deck());
    REQUIRE(!board.is_valid_tab_mv(Deck, 0, 0));
    REQUIRE(!board.is_valid_tab_mv(Waste, 0, 0));
  }

  SECTION("is_valid_tab_mv for tableau to foundation") {
    std::vector<CardT> decks = new_valid_deck();
    // Move Ace of suit 0 to front of tableau
    std::iter_swap(decks.begin() + 0, decks.begin() + 3);
    // Move 2 of suit 0 to front of second tableau
    std::iter_swap(decks.begin() + 8, decks.begin() + 7);
    BoardT board(decks);

    // Can move Ace to empty foundation
    REQUIRE(board.is_valid_tab_mv(Foundation, 0, 0));
    // Cannot move 2 to empty foundation
    REQUIRE(!board.is_valid_tab_mv(Foundation, 1, 0));
  }

  SECTION("is_valid_tab_mv for tableau to tableau, positive valid_mv_exists()") {
    std::vector<CardT> decks = new_valid_deck();
    // Move Ace of suit 0 to front of tableau
    std::iter_swap(decks.begin() + 0, decks.begin() + 3);
    // Move 2 of suit 0 to front of second tableau
    std::iter_swap(decks.begin() + 8, decks.begin() + 7);
    BoardT board(decks);

    // Can move Ace to 2
    REQUIRE(board.is_valid_tab_mv(Tableau, 0, 1));
    // Cannot move 2 to Ace
    REQUIRE(!board.is_valid_tab_mv(Tableau, 1, 0));

    REQUIRE(board.valid_mv_exists());
  }

  SECTION("is_valid_tab_mv for tableau to empty tableau, and stacking on foundation, get_foundation") {
    std::vector<CardT> d;
    // Make the first 8 tableaus hold 4, 3, 2, Ace of same suit
    for (unsigned int suit = 0; suit < 4; suit++) {
      for (int i = 0; i < 2; i++) {
        for (RankT rank = 4; rank >= ACE; rank--) {
          CardT n = { static_cast<SuitT>(suit), rank };
          d.push_back(n);
        }
      }
    }
    // Place the remaining cards
    for (unsigned int suit = 0; suit < 4; suit++) {
      for (RankT rank = 5; rank <= KING; rank++) {
        CardT n = { static_cast<SuitT>(suit), rank };
        d.push_back(n);
        d.push_back(n);
      }
    }

    BoardT board(d);
    // Place an entire tableau on a foundation
    for (unsigned int i = 0; i < 4; i++) {
      board.tab_mv(Foundation, 0, 0);
    }
    // Were we able to stack A, 2, 3, 4 of same suit on to foundation?
    REQUIRE(board.get_tab(0).size() == 0);
    // Can we now put a card from a tableau on to an empty tableau?
    REQUIRE(board.is_valid_tab_mv(Tableau, 1, 0));
    REQUIRE(!board.is_win_state());

    // Test get_foundation
    std::vector<CardT> f = board.get_foundation(0).toSeq();
    bool isCorrect = true;
    for (unsigned int i = 0; i < 4; i++) {
      if (!(f[i].s == 0 && f[i].r == i + 1)) {
        isCorrect = false;
        break;
      }
    }
    REQUIRE(isCorrect);
  }

  SECTION("is_valid_waste_mv throws invalid_argument when empty") {
    std::vector<CardT> decks = new_valid_deck();
    std::random_shuffle(decks.begin(), decks.end());
    BoardT board(decks);
    REQUIRE_THROWS_AS(
      board.is_valid_waste_mv(Foundation, 0),
      std::invalid_argument
    );
  }

  SECTION("is_valid_waste_mv always false for Deck and Waste, deck_mv") {
    std::vector<CardT> decks = new_valid_deck();
    std::random_shuffle(decks.begin(), decks.end());
    BoardT board(decks);

    CardT c = board.get_deck().top();
    board.deck_mv();
    REQUIRE(board.get_deck().size() == 63);
    REQUIRE(board.get_waste().size() == 1);
    REQUIRE(board.get_waste().top().r == c.r);
    REQUIRE(board.get_waste().top().s == c.s);
    REQUIRE(!board.is_valid_waste_mv(Deck, 0));
    REQUIRE(!board.is_valid_waste_mv(Waste, 0));
  }

  SECTION("is_valid_waste_mv throws out_of_range") {
    BoardT board(new_valid_deck());
    board.deck_mv();
    REQUIRE_THROWS_AS(board.is_valid_waste_mv(Tableau, 10), std::out_of_range);
    REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation, 8), std::out_of_range);
  }

  SECTION("is_valid_deck_mv allows us to waste entire deck, get_deck, get_waste") {
    std::vector<CardT> decks = new_valid_deck();
    std::random_shuffle(decks.begin(), decks.end());
    BoardT board(decks);

    std::vector<CardT> deck = board.get_deck().toSeq();
    REQUIRE(board.is_valid_deck_mv());
    bool isCorrect = true;
    for (unsigned int i = 0; i < 64; i++) {
      board.deck_mv();
      if (board.get_deck().size() != 63 - i) {
        isCorrect = false;
        break;
      }
    }
    REQUIRE(isCorrect);
    REQUIRE(!board.is_valid_deck_mv());
    // Trying to play an empty deck should throw an exception
    REQUIRE_THROWS_AS(board.deck_mv(), std::invalid_argument);

    // Ensure the waste is now the reverse of what the deck was
    std::vector<CardT> waste = board.get_waste().toSeq();
    isCorrect = true;
    for (unsigned int i = 0; i < 64; i++) {
      if (!(waste[i].r == deck[63 - i].r && waste[i].s == deck[63 - i].s)) {
        isCorrect = false;
        break;
      }
    }
    REQUIRE(isCorrect);
  }

  SECTION("getters throw out_of_range") {
    BoardT board(new_valid_deck());
    REQUIRE_THROWS_AS(board.get_tab(10), std::out_of_range);
    REQUIRE_THROWS_AS(board.get_foundation(8), std::out_of_range);
  }

  SECTION("valid_mv_exists is false") {
    BoardT board(new_valid_deck());
    for (unsigned int i = 0; i < 64; i++) {
      board.deck_mv();
    }
    REQUIRE(!board.valid_mv_exists());
  }

  SECTION("is_win_state is false") {
    BoardT board(new_valid_deck());
    for (unsigned int i = 0; i < 64; i++) {
      board.deck_mv();
    }
    REQUIRE(!board.is_win_state());
  }

  // Note! The specification design makes it very hard to test this since we
  // must set up a deck that allows us to play all cards and get into a
  // winning state. This is a difficult feat when only using the promised
  // interface!
  SECTION("is_win_state is true") {
    std::vector<CardT> d;
    // Make the first 8 tableaus hold 4, 3, 2, Ace of same suit
    for (unsigned int suit = 0; suit < 4; suit++) {
      for (int i = 0; i < 2; i++) {
        for (RankT rank = 4; rank >= ACE; rank--) {
          CardT n = { static_cast<SuitT>(suit), rank };
          d.push_back(n);
        }
      }
    }
    // Place [5,8] of suit 0 in the remaining two tableaus
    for (unsigned int i = 0; i < 2; i++) {
      for (RankT rank = 8; rank >= 5; rank--) {
        CardT n = { static_cast<SuitT>(0), rank };
        d.push_back(n);
      }
    }
    // Place [King,5] of suit 1-3 in the deck
    for (unsigned int suit = 1; suit < 4; suit++) {
      for (unsigned int i = 0; i < 2; i++) {
        for (RankT rank = KING; rank >= 5; rank--) {
          CardT n = { static_cast<SuitT>(suit), rank };
          d.push_back(n);
        }
      }
    }
    // Place [King,9] of suit 0 in the deck
    for (unsigned int i = 0; i < 2; i++) {
      for (RankT rank = KING; rank > 8; rank--) {
        CardT n = { static_cast<SuitT>(0), rank };
        d.push_back(n);
      }
    }

    BoardT board(d);
    // Play all the [Ace,4] of same suit
    for (unsigned int i = 0; i < 8; i++) {
      for (unsigned int j = 0; j < 4; j++) {
        board.tab_mv(Foundation, i, i);
      }
    }

    for (unsigned int i = 0; i < 2; i++) {
      // Play the remaining two tableaus which, both of suit 0
      for (unsigned int j = 0; j < 4; j++) {
        board.tab_mv(Foundation, i + 8, i);
      }
      // Play all the deck cards which are of suit 0
      for (unsigned int j = 0; j < 5; j++) {
        board.deck_mv();
        board.waste_mv(Foundation, i);
      }
    }

    // Play all the deck cards. At the top of the deck is suit 3, going down.
    for (unsigned int i = 3; i >= 1; i--) {
      for (unsigned int j = 0; j < 2; j++) {
        for (unsigned int k = 0; k < 9; k++) {
          board.deck_mv();
          board.waste_mv(Foundation, (board.get_waste().top().s + 1) * 2 + j - 2);
        }
      }
    }

    REQUIRE(board.is_win_state());
  }

}
