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
	for (RankT rank = KING; rank >= ACE; rank--) {
	    for (unsigned int suit = 0; suit < 4; suit++) {
	    	CardT n = { static_cast<SuitT>(suit), rank };
	    	d.push_back(n);
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
		REQUIRE(board.is_win_state() == false);
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

//get_tab
	SECTION( "get_tab: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_tab(15),std::out_of_range);
	}

//get_foundation
	SECTION( "get_foundation: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_foundation(15),std::out_of_range);
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

//waste_mv

	SECTION("waste_mv invalid argument "){
		board.deck_mv();
		REQUIRE_THROWS_AS(board.is_valid_waste_mv(Foundation, 19),std::out_of_range);
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

//tab_mv

	SECTION("tab_mv deck as argument "){
		REQUIRE_THROWS_AS(board.tab_mv(Deck,13, 5),std::invalid_argument);
	}

	SECTION("tab_mv waste as argument "){
		REQUIRE_THROWS_AS(board.tab_mv(Waste,13, 5),std::invalid_argument);
	}




}