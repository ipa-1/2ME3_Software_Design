#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

class BoardT
{
	private:
		std::vector <CardStackT> T; // Tableau
		std::vector <CardStackT> F; // Foundation
		CardStackT D; // Deck
		CardStackT W;

	public:
		BoardT(std::vector<CardT> d);
		bool is_valid_tab_mv(CategoryT c, nat n0, nat n1) const;
		bool is_valid_waste_mv(CategoryT c, nat n) const;
		bool is_valid_deck_mv() const;
		void tab_mv(CategoryT c, nat n0, nat n1);
		void waste_mv(CategoryT c, nat n);
		void deck_mv();
		CardStackT get_tab(nat n) const;
		CardStackT get_foundation(nat n) const;
		CardStackT get_deck() const;
		CardStackT get_waste() const;
		bool valid_mv_exists() const;
		bool is_win_state() const;

		bool valid_tab_tab(nat n0, nat n1) const;
		bool is_valid_pos(CategoryT t, nat n) const;
		bool valid_tab_mv() const;
		bool valid_waste_mv() const;
		bool valid_tab_foundation(nat n0, nat n1) const;




};
#endif
