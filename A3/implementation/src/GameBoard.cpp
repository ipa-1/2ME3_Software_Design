//Alice Ip ipa1

#include "CardTypes.h"
#include "CardStack.h"
#include "GameBoard.h"
#include <vector>

BoardT::BoardT(std::vector<CardT> d) // new BoardT; takes in a seq of CardT
: T({}) // vector of CardStackT
, F({}) // vector of CardStackT
, D (CardStackT({})) // CardStackT
, W (CardStackT({})) // CardStackT
{

	/*if (d.size() != 104)
		throw std::invalid_argument("Card sequence not right size*/
	int count = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 14; j++ ){
			for (int k = 0; k < 104;k++){
				if (d[k].s == i && d[k].r == j)
					count +=1;
			}
			if (count != 2)
				throw std::invalid_argument("Card sequence not right size");
			count = 0;
		}
	}
	int index;
	CardStackT temp({}); 
	for(int i = 0; i < 10; i++){ // Initializes T
		index = 4*i;
		//CardStackT temp({d[index], d[index+1], d[index+2], d[index+3]});
		
		temp = temp.push(d[index]);
		temp = temp.push(d[index+1]);
		temp = temp.push(d[index+2]);
		temp = temp.push(d[index+3]);
		T.push_back(temp); // pushes the CardStackT into the vector
		temp = temp.pop();
		temp = temp.pop();
		temp = temp.pop();
		temp = temp.pop();

	}
	
	CardStackT temp2({}); 
	for(int i = 0; i < 8; i++){ // Initializes F
		F.push_back(temp2);
	}

	for (int i = 40; i <= 103; i++){ // Initializes D
		D = D.push(d[i]);
	}
};

//Public Accessors

// Checks if the move from tableau to tableau/foundation is valid
bool BoardT::is_valid_tab_mv(CategoryT c, nat n0, nat n1) const 
{

	if (c == Tableau){
		if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Tableau, n1)))
			throw std::out_of_range("is_valid_tab_mv invalid pos tableau");
		return valid_tab_tab(n0, n1);
	}

	else if (c == Foundation){
		if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Foundation, n1)))
			throw std::out_of_range("is_valid_tab_mv invalid pos foundation");
		return valid_tab_foundation(n0,n1); 
	}
	else
		return false;
};

// Checks if there is a valid move from waste to tableau/foundation
bool BoardT::is_valid_waste_mv(CategoryT c, nat n) const
{
	if (W.size() == 0)
		return false;



	if (c == Tableau){
		if (T[n].size() > 0)
			return (W.top().s == T[n].top().s && W.top().r == T[n].top().r+1); //return valid_waste_tab(n);
		else
			return true;
	}
		
	else if (c == Foundation){
		if (F[n].size() > 0)
			return (W.top().s == F[n].top().s && W.top().r == F[n].top().r+1); //return valid_waste_foundation(n);
		else
			return (W.top().r == 1);
	}
	else
		return false;
};

// Checks to see if there is a valid deck move
bool BoardT::is_valid_deck_mv() const
{
	return (D.size() > 0); // Deck move is always valid unless there is nothing in deck
};


void BoardT::tab_mv(CategoryT c, nat n0, nat n1)
{ 
	if (!(is_valid_tab_mv(c,n0,n1)))
		throw std::invalid_argument("Invalid tab_mv argument");

	if (c == Tableau){
		CardT topCard = T[n0].top(); // Top of tableau n0
		T[n0] = T[n0].pop();                 // Remove top of tableau n0
		T[n1] = T[n1].push(topCard);         // Put the card on n1
	}

	else if (c == Foundation){
		CardT topCard = T[n0].top();
		T[n0] = T[n0].pop();
		F[n1] = F[n1].push(topCard);		
	}
};


void BoardT::waste_mv(CategoryT c, nat n)
{
	if (!(is_valid_waste_mv(c,n))) // checks if move is valid
		throw std::invalid_argument("Invalid waste_mv argument");

	if (c == Tableau){
		if(!(is_valid_pos(Tableau, n))) // check that tableau argument is in range
			throw std::out_of_range("waste_mv tableau argument out of range");
		CardT topCard = W.top();
		W = W.pop();
		T[n] = T[n].push(topCard);
	}

	else if (c == Foundation){
		if(!(is_valid_pos(Foundation,n))) // check that foundation argument is in range
			throw std::out_of_range("waste_mv foundation argument out of range");
		CardT topCard = W.top();
		W = W.pop();
		F[n] = F[n].push(topCard);		
	}
};


void BoardT::deck_mv()
{
	if (!(is_valid_deck_mv()))
		throw std::invalid_argument("Invalid deck_mv argument");
	CardT topCard = D.top();
	D = D.pop();
	W = W.push(topCard);
};


CardStackT BoardT::get_tab(nat n) const
{
	if (!(is_valid_pos(Tableau,n)))
		throw std::out_of_range("get_tab tab argument out of range");
	return T[n];
}



CardStackT BoardT::get_foundation(nat n) const
{
	if (!(is_valid_pos(Foundation,n)))
		throw std::out_of_range("get_foundation foundation argument out of range");
	return F[n];
};


CardStackT BoardT::get_deck() const
{
	return D;
};

CardStackT BoardT::get_waste() const
{
	return W;
};


bool BoardT::valid_mv_exists() const
{
	return (valid_tab_mv() || valid_waste_mv() || is_valid_deck_mv());
};

bool BoardT::is_win_state() const
{
	for (int i = 0; i < 8; i++)
		if (!(F[i].size() == 13))
			return false;
	return true;
};

//Private Accessors

bool BoardT::valid_tab_mv() const
{
	for (int i = 0;i < 10;i++){
		if (!(is_valid_pos(Tableau, i))) // For each Tableau, check the origin is valid
			continue;
		for (int j = 0; j < 8; j++){ // For each Foundation, check destination valid, and mv valid
			if (is_valid_pos(Foundation, j) && is_valid_tab_mv(Foundation, i,j))
				return true;
		}
	}

	for (int i = 0;i < 10;i++){
		if (!(is_valid_pos(Tableau, i))) // For each Tableau, check the origin is valid
			continue;
		for (int j = 0; j < 8; j++){ // For each Foundation, check destination valid, and mv valid
			if (is_valid_pos(Foundation, j) && is_valid_tab_mv(Foundation, i,j))
				return true;
		}
	}

	return false; // if it never passed all three tests in either for loop, then no moves available
};

bool BoardT::valid_waste_mv() const
{
	for (int i = 0; i < 8; i++){
		if (is_valid_pos(Foundation, i) && is_valid_waste_mv(Foundation, i))
			return true;
	}
	for (int i = 0; i < 10; i++){
		if (is_valid_pos(Tableau, i) && is_valid_waste_mv(Tableau, i))
			return true;
	}
	return false;

};

bool BoardT::is_valid_pos(CategoryT t, nat n) const
{
	if (t == Tableau)
		return (n >= 0 && n <= 9);
	else if (t == Foundation)
		return (n >= 0 && n <= 7);
	else
		return true;
};

bool BoardT::valid_tab_foundation(nat n0, nat n1) const
{
	if (T[n0].size() > 0){
		if (F[n1].size() > 0)
			return (T[n0].top().s == F[n1].top().s && T[n0].top().r == F[n1].top().r+1);
		else
			return true;
	}
	else
		return false;
}

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
