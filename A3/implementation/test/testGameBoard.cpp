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

	SECTION( "is_win_state : Checking for win state when not in win state"){
		REQUIRE(board.is_win_state() == false);
	}

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

	SECTION( "deck_mv: deck move decreases deck size"){
		//cout << board.get_deck().size() << std::endl;
		board.deck_mv();	
		REQUIRE(board.get_deck().size() == 63);
		REQUIRE(board.get_waste().size() == 1);
	}

	SECTION( "is_valid_deck_mv: invalid deck mv argument exception"){
		for (int i = 0; i < 64; i++){
			board.deck_mv();
		}
		REQUIRE_THROWS_AS(board.deck_mv(),std::invalid_argument);
	}

	SECTION( "get_tab: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_tab(15),std::out_of_range);
	}


	SECTION( "get_foundation: argument out of range exception"){
		REQUIRE_THROWS_AS(board.get_foundation(15),std::out_of_range);
	}

	SECTION( "is_valid_waste_mv waste size 0"){
		REQUIRE(board.is_valid_waste_mv(Tableau,3) == false);
	}



}