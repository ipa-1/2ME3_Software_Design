//Alice Ip ipa1

#include "CardTypes.h"
#include "CardStack.h"
#include "GameBoard.h"

BoardT::BoardT() // new BoardT; takes in a seq of CardT
: T({}) 
, F({})
, D (CardStackT({}))
, W (CardStackT({}))
{
	/*foreach(RankT rank in Enum.getValues(typeof(RankT))){
		std::cout << rank;
	}*/

};

//Public Accessors
bool BoardT::is_valid_tab_mv(CategoryT c, nat n0, nat n1) const
{
	if (c == Tableau)
		return true; //valid_tab_tab(n0, n1);
	else if (c == Foundation)
		return true; //valid_tab_foundation(n0, n1);
	else
		return false;
};


bool BoardT::valid_tab_tab(nat n0, nat n1) const{
	if (T[n0].size() > 0){
		if (T[n1].size() > 0){ // check suits are same, and target is one rank smaller
			return (T[n0].top().s == T[n1].top().s) && (T[n0].top().r == (T[n1].top().r + 1));
		}
		else // T[n1].size == 0, target is empty, move is valid
			return true;
	}
	else // origin tableau is empty
		return false;
}

bool BoardT::is_valid_waste_mv(CategoryT c, nat n) const
{
	if (c == Tableau)
		return true;//valid_waste_tab(n);
	else if (c == Foundation)
		return true; //valid_waste_foundation(n);
	else
		return false;
};

bool BoardT::is_valid_deck_mv() const
{
	return this->D.size() > 0;
};


void BoardT::tab_mv(CategoryT c, nat n0, nat n1)
{ 
	if (is_valid_tab_mv(c,n0,n1) == false)
		throw std::invalid_argument("Invalid argument");

	if (c == Tableau){
		CardT topCard = T[n0].top(); // Top of tableau n0
		T[n0].pop();                 // Remove top of tableau n0
		T[n1].push(topCard);         // Put the card on n1
	}

	else if (c == Foundation){
		CardT topCard = T[n0].top();
		T[n0].pop();
		F[n1].push(topCard);		
	}
};


void BoardT::waste_mv(CategoryT c, nat n)
{
	if (!(is_valid_waste_mv(c,n))) // checks if move is valid
		throw std::invalid_argument("Invalid argument");

	if (c == Tableau){
		CardT topCard = W.top();
		W.pop();
		T[n].push(topCard);
	}

	else if (c == Foundation){
		CardT topCard = W.top();
		W.pop();
		F[n].push(topCard);		
	}
};


void BoardT::deck_mv()
{
	CardT topCard = D.top();
	D.pop();
	W.push(topCard);
};

/*
CategoryT BoardT::get_tab(nat n) const
{
	return T[n];
}*/

/*

CategoryT BoardT::get_foundation() const;
{

};

CategoryT BoardT::get_deck() const;
{

};

CategoryT BoardT::get_waste() const;
{

};

bool BoardT::valid_mv_exists() const;
{

};

bool BoardT::is_win_state() const;
{

};*/

//Private Accessors
