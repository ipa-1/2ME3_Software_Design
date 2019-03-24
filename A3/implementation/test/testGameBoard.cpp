// Alice Ip ipa1

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


#include "catch.h"
#include "Stack.h"
#include "GameBoard.h"
#include "CardTypes.h"
#include "CardStack.h"

TEST_CASE("BoardT(): tests for BoardT", "BoardT"){

	std::vector<CardT> d;
	for (RankT rank = ACE; rank <= KING; rank++) {
		for (unsigned int suit = 0; suit < 4; suit++) {
	    	CardT n = { static_cast<SuitT>(suit), rank };
	    	d.push_back(n);
	    	d.push_back(n);
	    }
	}
	std::random_shuffle(d.begin(), d.end());

	BoardT board(d);

	// Winning deck 
	std::vector<CardT> wDeck;

	// T[0]
	wDeck.push_back(CardT {Club, 5});
	wDeck.push_back(CardT {Club, 4});
	wDeck.push_back(CardT {Club, 3});
	wDeck.push_back(CardT {Club, ACE});
	// T[1]
	wDeck.push_back(CardT {Club, 9});
	wDeck.push_back(CardT {Club, 8});
	wDeck.push_back(CardT {Club, 7});
	wDeck.push_back(CardT {Club, 6});	
	// T[2]
	wDeck.push_back(CardT {Club, KING});
	wDeck.push_back(CardT {Club, QUEEN});
	wDeck.push_back(CardT {Club, JACK});
	wDeck.push_back(CardT {Club, 10});
	// T[3]
	wDeck.push_back(CardT {Heart, 6});
	wDeck.push_back(CardT {Heart, 5});
	wDeck.push_back(CardT {Heart, 4});
	wDeck.push_back(CardT {Heart, ACE});
	// T[4]
	wDeck.push_back(CardT {Heart, 9});
	wDeck.push_back(CardT {Heart, 8});
	wDeck.push_back(CardT {Heart, 7});
	wDeck.push_back(CardT {Heart, 3});
	// T[5]
	wDeck.push_back(CardT {Diamond, 5});
	wDeck.push_back(CardT {Diamond, 4});
	wDeck.push_back(CardT {Diamond, 3});
	wDeck.push_back(CardT {Diamond, ACE});
	// T[6]
	wDeck.push_back(CardT {Diamond, 8});
	wDeck.push_back(CardT {Diamond, 7});
	wDeck.push_back(CardT {Diamond, 6});
	wDeck.push_back(CardT {Diamond, 2});
	// T[7]
	wDeck.push_back(CardT {Diamond, QUEEN});
	wDeck.push_back(CardT {Diamond, JACK});
	wDeck.push_back(CardT {Diamond, 10});
	wDeck.push_back(CardT {Diamond, 9});
	// T[8]
	wDeck.push_back(CardT {Spade, 4});
	wDeck.push_back(CardT {Spade, 3});
	wDeck.push_back(CardT {Spade, 2});
	wDeck.push_back(CardT {Diamond, KING});
	// T[9]
	wDeck.push_back(CardT {Spade, 8});
	wDeck.push_back(CardT {Spade, 7});
	wDeck.push_back(CardT {Spade, 6});
	wDeck.push_back(CardT {Spade, 5});

	//Second deck in descending order
    for (unsigned int suit = 0; suit < 4; suit++) {
    	for (RankT rank = KING; rank >= ACE; rank--) {
    		CardT n = { static_cast<SuitT>(suit), rank };
    		wDeck.push_back(n);
    	}
	}

	// Remaining of first deck, rigged to test waste moves and to finish first deck 
	wDeck.push_back(CardT {Spade, KING});
	wDeck.push_back(CardT {Spade, QUEEN});
	wDeck.push_back(CardT {Spade, JACK});
	wDeck.push_back(CardT {Spade, 10});
	wDeck.push_back(CardT {Spade, 9});
	wDeck.push_back(CardT {Heart, KING});
	wDeck.push_back(CardT {Heart, QUEEN});
	wDeck.push_back(CardT {Heart, JACK});
	wDeck.push_back(CardT {Heart, 10});
	wDeck.push_back(CardT {Club, 2});
	wDeck.push_back(CardT {Heart, 2});
	wDeck.push_back(CardT {Spade, ACE});

	//cout << wDeck.size() << endl;
	BoardT board2(wDeck);

//BoardT() constructor
	SECTION( "BoardT(): Empty card sequence to board initializer exception"){
		std::vector<CardT> emptyVector;
		REQUIRE_THROWS_AS(BoardT (emptyVector),std::invalid_argument);
	}
	SECTION( "BoardT(): Checking for two of each card in deck exception"){
		d[103].r = d[102].r;
		d[103].s = d[102.].s;
		d[101].r = d[102].r;
		d[101].s = d[102.].s;
		REQUIRE_THROWS_AS(BoardT (d),std::invalid_argument);
	}

	SECTION( "BoardT(): Checking for empty waste at construction"){
		REQUIRE(board.get_waste().size() == 0);
	}

	SECTION( "BoardT(): Checking for 64 cards in deck at construction"){
		REQUIRE(board.get_deck().size() == 64);
	}

	SECTION( "BoardT(): Checking for empty foundation at construction"){
		REQUIRE(board.get_foundation(0).size() == 0);
		REQUIRE(board.get_foundation(1).size() == 0);
		REQUIRE(board.get_foundation(2).size() == 0);
		REQUIRE(board.get_foundation(3).size() == 0);
		REQUIRE(board.get_foundation(4).size() == 0);
		REQUIRE(board.get_foundation(5).size() == 0);
		REQUIRE(board.get_foundation(6).size() == 0);
		REQUIRE(board.get_foundation(7).size() == 0);
	}

	SECTION( "BoardT(): Checking for 4 cards per tableau at construction"){
		REQUIRE(board.get_tab(0).size() == 4);
		REQUIRE(board.get_tab(1).size() == 4);
		REQUIRE(board.get_tab(2).size() == 4);
		REQUIRE(board.get_tab(3).size() == 4);
		REQUIRE(board.get_tab(4).size() == 4);
		REQUIRE(board.get_tab(5).size() == 4);
		REQUIRE(board.get_tab(6).size() == 4);
		REQUIRE(board.get_tab(7).size() == 4);
		REQUIRE(board.get_tab(8).size() == 4);
		REQUIRE(board.get_tab(9).size() == 4);
	}

// is_win_state
	SECTION( "is_win_state : Checking for win state when not in win state"){
		REQUIRE(board2.is_win_state() == false);
	}

// is_valid_deck_mv
	SECTION( "is_valid_deck_mv: valid deck mv"){
		REQUIRE(board.is_valid_deck_mv() == true);
	}

	SECTION( "is_valid_deck_mv: invalid deck mv"){
		for (int i = 0; i < 64; i++){
			board.deck_mv();
		}
		//cout << board.get_deck().size() << std::endl;
		REQUIRE(board.is_valid_deck_mv() == false);
	}

// deck_mv
	SECTION( "deck_mv: deck move decreases deck size"){
		//cout << board.get_deck().size() << std::endl;
		board.deck_mv();	
		REQUIRE(board.get_deck().size() == 63);
		REQUIRE(board.get_waste().size() == 1);
	}

	SECTION( "deck_mv: invalid deck mv argument exception"){
		for (int i = 0; i < 64; i++){
			board.deck_mv();
		}
		REQUIRE_THROWS_AS(board.deck_mv(),std::invalid_argument);
	}
//tab_mv

	SECTION("tab_mv deck as argument "){
		REQUIRE_THROWS_AS(board.tab_mv(Deck,13, 5),std::invalid_argument);
	}

	SECTION("tab_mv waste as argument "){
		REQUIRE_THROWS_AS(board.tab_mv(Waste,13, 5),std::invalid_argument);
	}

	SECTION("tab_mv correct values in both tabs after move"){
		board2.tab_mv(Tableau,5,6);
		REQUIRE(board2.get_tab(5).top().s == Diamond);
		REQUIRE(board2.get_tab(5).top().r == 3);
		REQUIRE(board2.get_tab(6).top().s == Diamond);
		REQUIRE(board2.get_tab(6).top().r == ACE);
	}
	SECTION("tab_mv correct values in tab and foundation after move"){
		board2.tab_mv(Foundation,0,0);
		REQUIRE(board2.get_tab(0).top().s == Club);
		REQUIRE(board2.get_tab(0).top().r == 3);
		REQUIRE(board2.get_foundation(0).top().s == Club);
		REQUIRE(board2.get_foundation(0).top().r == ACE);
	}		

//waste_mv

	SECTION("waste_mv invalid argument "){
		board.deck_mv();
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation, 19),std::out_of_range);
	}

	SECTION("waste_mv correct values in waste and tab after move"){

		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		board2.deck_mv(); // 2 of hearts on waste
		board2.waste_mv(Tableau,4); // 2 of hearts to tableau index 4
		REQUIRE(board2.get_waste().size() == 0);
		REQUIRE(board2.get_tab(4).top().s == Heart);
		REQUIRE(board2.get_tab(4).top().r == 2);
	}


	SECTION("waste_mv correct values in waste and foundation after move"){

		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		REQUIRE(board2.get_waste().size() == 0);
		REQUIRE(board2.get_foundation(1).top().s == Spade);
		REQUIRE(board2.get_foundation(1).top().r == ACE);
	}

//get_tab
	SECTION( "get_tab: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_tab(15),std::out_of_range);
	}

	SECTION( "get_tab: card in tab are as expected from predefined deck"){
		REQUIRE((board2.get_tab(0).toSeq()[0].r) == 5);
		REQUIRE((board2.get_tab(0).toSeq()[1].r) == 4);
		REQUIRE((board2.get_tab(0).toSeq()[2].r) == 3);
		REQUIRE((board2.get_tab(0).toSeq()[3].r) == ACE);
	}


//get_foundation
	SECTION( "get_foundation: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_foundation(15),std::out_of_range);
	}


//get_deck
	SECTION("get_deck: cards in deck are as expected from predefined deck"){
		REQUIRE((board2.get_deck().toSeq()[63].r) == ACE);
		REQUIRE((board2.get_deck().toSeq()[62].r) == 2);
		REQUIRE((board2.get_deck().toSeq()[61].r) == 2);
	}

//get_waste
	SECTION("get_waste: correct suit and rank of card in waste after deck mv using predefined deck"){
		board2.deck_mv();
		REQUIRE(board2.get_waste().toSeq()[0].r == ACE);
		REQUIRE(board2.get_waste().toSeq()[0].s == Spade);
	}

//is_valid_waste_mv
	SECTION( "is_valid_waste_mv waste size 0"){
		REQUIRE(board.is_valid_waste_mv(Tableau,3) == false);
	}

	SECTION("is_valid_waste_mv out of range tableau exception"){
		board.deck_mv();
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Tableau, 19),std::out_of_range);
	}

	SECTION("is_valid_waste_mv out of range foundation exception"){
		board.deck_mv();
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation, 19),std::out_of_range);
	}

	SECTION("is_valid_waste_mv deck as argument"){
		board.deck_mv();
		REQUIRE(board.is_valid_waste_mv(Deck, 19) == false);
	}

	SECTION("is_valid_waste_mv waste as argument"){
		board.deck_mv();
		REQUIRE(board.is_valid_waste_mv(Waste, 19) == false);
	}

	SECTION("is_valid_waste_mv valid move to empty foundation"){
		board2.deck_mv();
		REQUIRE(board2.is_valid_waste_mv(Foundation, 0) == true);
	}

	SECTION("is_valid_waste_mv valid move to tableau"){
		board2.deck_mv();
		board2.waste_mv(Foundation,0);
		board2.deck_mv();
		//cout << board2.get_waste().toSeq()[0].r << board2.get_waste().toSeq()[0].s <<endl;
		//cout << board2.get_tab(4).toSeq()[3].r << board2.get_tab(4).toSeq()[3].s <<endl;
		REQUIRE(board2.is_valid_waste_mv(Tableau, 4) == true);
	}

	SECTION("is_valid_waste_mv invalid move with non-empty waste"){
		board2.deck_mv();
		//board2.waste_mv(Foundation,0);
		board2.deck_mv();
		board2.deck_mv();
		//cout << board2.get_waste().toSeq()[0].r << board2.get_waste().toSeq()[0].s <<endl;
		//cout << board2.get_tab(4).toSeq()[3].r << board2.get_tab(4).toSeq()[3].s <<endl;
		REQUIRE(board2.is_valid_waste_mv(Tableau, 4) == false);
		REQUIRE(board2.is_valid_waste_mv(Foundation, 4) == false);
	}

	SECTION("is_valid_waste_mv valid move to empty tableau"){
		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		board2.deck_mv(); // 2 of hearts on waste
		board2.waste_mv(Tableau,4); // 2 of hearts to tableau index 4
		board2.tab_mv(Foundation,0,0); // Ace of clubs on foudnation 1
		board2.deck_mv(); // 2 of clubs on waste
		board2.waste_mv(Foundation,0); // 2 of clubs on foundation 1
		board2.tab_mv(Foundation,0,0);
		board2.tab_mv(Foundation,0,0);
		board2.tab_mv(Foundation,0,0);
		board2.deck_mv(); // 10 of hearts on waste

		REQUIRE(board2.is_valid_waste_mv(Tableau, 0) == true);

	}

	SECTION("is_valid_waste_mv valid move to non empty foundation"){
		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		board2.deck_mv(); // 2 of hearts on waste
		board2.waste_mv(Tableau,4); // 2 of hearts to tableau index 4
		board2.tab_mv(Foundation,0,0); // Ace of clubs on foudnation 1
		board2.deck_mv(); // 2 of clubs on waste

		REQUIRE(board2.is_valid_waste_mv(Foundation, 0) == true);

	}

//is_valid_tab_mv

	SECTION("is_valid_tab_mv deck as argument "){
		REQUIRE(board.is_valid_tab_mv(Deck,3, 5) == false);
	}

	SECTION("is_valid_tab_mv waste as argument "){
		REQUIRE(board.is_valid_tab_mv(Waste,3, 5) == false);
	}

	SECTION("is_valid_tab_mv invalid position for originating tableau exception "){
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau,13, 5),std::out_of_range);
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Foundation,13, 5),std::out_of_range);
	}

	SECTION("is_valid_tab_mv invalid position for destination exception "){
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Tableau,0, 15),std::out_of_range);
		REQUIRE_THROWS_AS(board.is_valid_tab_mv(Foundation,0, 15),std::out_of_range);
	}

	SECTION("is_valid_tab_mv valid tab to empty foundation move"){
		REQUIRE(board2.is_valid_tab_mv(Foundation,0,0) == true);
	}

	SECTION("is_valid_tab_mv valid tab to non-empty foundation move"){
		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		board2.deck_mv(); // 2 of hearts on waste
		board2.waste_mv(Tableau,4); // 2 of hearts to tableau index 4
		board2.tab_mv(Foundation,0,0); // Ace of clubs on foudnation 1
		board2.deck_mv(); // 2 of clubs on waste
		board2.waste_mv(Foundation,0); // 2 of clubs on foundation 1
		REQUIRE(board2.is_valid_tab_mv(Foundation,0,0) == true);
	}

	SECTION("is_valid_tab_mv valid tab to tab move"){
		REQUIRE(board2.is_valid_tab_mv(Foundation,4,5) == true);
	}

	SECTION("is_valid_tab_mv invalid tab move"){
		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 2
		REQUIRE(board2.is_valid_tab_mv(Foundation,4,1) == false);
		REQUIRE(board2.is_valid_tab_mv(Tableau,0,1) == false);
	}

//valid_mv_exists
	SECTION("valid_mv_exists is true when there is a valid move using predefined deck"){
		REQUIRE(board2.valid_mv_exists() == true);
	}

//is_win_state
	SECTION("is_win_state is true when at win state"){
		board2.deck_mv(); // Ace of spades on waste
		board2.waste_mv(Foundation,1); // Ace of spades on foundation 1
		board2.deck_mv(); // 2 of hearts on waste

		board2.tab_mv(Foundation,0,0); // Ace of clubs on foudnation 0
		board2.tab_mv(Foundation,3,2); // Ace of hearts on foudnation 2
		board2.waste_mv(Foundation,2); // 2 of hearts to foundation 2

		board2.deck_mv(); // 2 of clubs on waste
		board2.waste_mv(Foundation,0); // 2 of clubs on foundation 1

		// clear out tableau 1 into foundation 0
		board2.tab_mv(Foundation,0,0);
		board2.tab_mv(Foundation,0,0);
		board2.tab_mv(Foundation,0,0);
		// clear out tableau 1 and 2 into foundation 0
		board2.tab_mv(Foundation,1,0);
		board2.tab_mv(Foundation,1,0);
		board2.tab_mv(Foundation,1,0);
		board2.tab_mv(Foundation,1,0);
		board2.tab_mv(Foundation,2,0);
		board2.tab_mv(Foundation,2,0);
		board2.tab_mv(Foundation,2,0);
		board2.tab_mv(Foundation,2,0);

		// clear out hearts into foundation 2
		board2.tab_mv(Foundation,4,2);
		board2.tab_mv(Foundation,3,2);
		board2.tab_mv(Foundation,3,2);
		board2.tab_mv(Foundation,3,2);
		board2.tab_mv(Foundation,4,2);
		board2.tab_mv(Foundation,4,2);
		board2.tab_mv(Foundation,4,2);
		// clear out hearts in deck into foundation 2
		board2.deck_mv(); // 10 of hearts
		board2.waste_mv(Foundation,2);
		board2.deck_mv(); // Jack of hearts
		board2.waste_mv(Foundation,2);
		board2.deck_mv(); // Queen of hearts
		board2.waste_mv(Foundation,2);
		board2.deck_mv(); // King of hearts
		board2.waste_mv(Foundation,2);

		// clear out diamonds into foundation 3
		board2.tab_mv(Foundation,5,3);
		board2.tab_mv(Foundation,6,3);
		board2.tab_mv(Foundation,5,3);
		board2.tab_mv(Foundation,5,3);

		board2.tab_mv(Foundation,5,3);
		board2.tab_mv(Foundation,6,3);
		board2.tab_mv(Foundation,6,3);
		board2.tab_mv(Foundation,6,3);

		board2.tab_mv(Foundation,7,3);
		board2.tab_mv(Foundation,7,3);
		board2.tab_mv(Foundation,7,3);
		board2.tab_mv(Foundation,7,3);

		board2.tab_mv(Foundation,8,3);

		// clear out remaining tableau into foundation 1
		board2.tab_mv(Foundation,8,1);
		board2.tab_mv(Foundation,8,1);
		board2.tab_mv(Foundation,8,1);

		board2.tab_mv(Foundation,9,1);
		board2.tab_mv(Foundation,9,1);
		board2.tab_mv(Foundation,9,1);
		board2.tab_mv(Foundation,9,1);
		// clear out remaining first deck in the deck
		board2.deck_mv(); 
		board2.waste_mv(Foundation,1);
		board2.deck_mv(); 
		board2.waste_mv(Foundation,1);
		board2.deck_mv(); 
		board2.waste_mv(Foundation,1);
		board2.deck_mv(); 
		board2.waste_mv(Foundation,1);
		board2.deck_mv(); 
		board2.waste_mv(Foundation,1);
		// first deck in proper place in game

		// remaining deck in proper order is placed into foundations 4-7
		for (int j = 0; j < 4; j++){
			for (int i = 0; i < 13; i++){
				board2.deck_mv();
				//cout << board2.get_waste().top().s <<" "<< board2.get_waste().top().r << endl;
				board2.waste_mv(Foundation,4+j);
			}
		}

	REQUIRE(board2.is_win_state() == true);
	REQUIRE(board2.valid_mv_exists() == false);

	}



}