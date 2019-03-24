// Alice Ip ipa1

#include <algorithm>
#include <iostream>
#include <vector>

#include "catch.h"
#include "Stack.h"
#include "GameBoard.h"
#include "CardTypes.h"
#include "CardStack.h"

TEST_CASE("tests for BoardT", "BoardT"){

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


}