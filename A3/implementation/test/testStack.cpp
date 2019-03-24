// Alice Ip ipa1

#include <algorithm>
#include <iostream>
#include <vector>

#include "catch.h"
#include "Stack.h"
#include "GameBoard.h"
#include "CardTypes.h"
#include "CardStack.h"

TEST_CASE("tests for Stack", "Stack"){

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

	CardStackT emptyStack({});
	CardStackT allCards(d);

	SECTION( "Popping from an Empty Stack"){
		REQUIRE_THROWS_AS(emptyStack.pop(),std::out_of_range);
	}

	SECTION( "Top from an Empty Stack"){
		REQUIRE_THROWS_AS(emptyStack.top(),std::out_of_range);
	}

	SECTION( "Pop decreases size"){
		allCards = allCards.pop();
		REQUIRE(allCards.size() == 103);
	}

	SECTION( "Push increases size"){
		CardT n = { static_cast<SuitT>(0), ACE };
		allCards = allCards.push(n);
		REQUIRE(allCards.size() == 105);
	}

	SECTION( "Size returns correct size"){
		REQUIRE(allCards.size() == 104);
	}

}