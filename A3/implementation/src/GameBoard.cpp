//Alice Ip ipa1

#include "CardTypes.h"
#include "CardStack.h"
#include "GameBoard.h"

BoardT::BoardT() // new BoardT; takes in a seq of CardT
: T(std::vector <CardStackT> ({})) 
, F(std::vector <CardStackT> ({}))
, D (CardStackT({}))
, W (CardStackT({}))
{
	/*foreach(RankT rank in Enum.getValues(typeof(RankT))){
		std::cout << rank;
	}*/

};

//Public Accessors
bool is_valid_tab_mv(CategoryT c, nat n0, nat n1) 
{

	if (c == Tableau)
		return true; //valid_tab_tab(n0, n1);
	else if (c == Foundation)
		return true; //valid_tab_foundation(n0, n1);
	else
		return false;
};

bool is_valid_waste_mv(CategoryT c, nat n) 
{
	if (c == Tableau)
		return true;//valid_waste_tab(n);
	else if (c == Foundation)
		return true; //valid_waste_foundation(n);
	else
		return false;
};

/*
bool BoardT::valid_tab_tab(nat n0, nat n1){
	return true;
}*/
/*
bool BoardT::is_valid_deck_mv() const;
{
	return D.size() > 0;
};

void BoardT::tab_mv(CategoryT c, nat n0, nat n1);
{ // since tableau and foundation are the same type...
	cardT temp =
};

void BoardT::waste_mv(CategoryT c, nat n);
{

};

void BoardT::deck_mv();
{

};

CategoryT BoardT::get_tab() const;
{

};

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

};
*/
//Private Accessors
