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


	if (d.size() != 104)
		throw std::invalid_argument("Card sequence not right size");
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
	return (D.size() > 0);
};


void BoardT::tab_mv(CategoryT c, nat n0, nat n1)
{ 
	if (is_valid_tab_mv(c,n0,n1) == false)
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
		CardT topCard = W.top();
		W = W.pop();
		T[n] = T[n].push(topCard);
	}

	else if (c == Foundation){
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
	if (!(n >= 0 && n <= 9))
		throw std::out_of_range("get_tab tab argument out of range");
	return T[n];
}



CardStackT BoardT::get_foundation(nat n) const
{
	if (!(n >= 0 && n <= 7))
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

