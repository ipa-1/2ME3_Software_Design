#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"
#include "Exceptions.h"

class GameBoard
{
	private:
		list <CardStackT> T; // Tableau
		list <CardStackT> F; // Foundation
		CardStackT D; // Deck
		CardStackT w;

	public:
		new BoardT;
		bool is_valid_tab_mv(CategoryT c, nat n0, nat n1) const;
		bool is_valid_waste_mv(CategoryT c, nat n) const;
		bool is_valid_deck_mv() const;
		void tab_mv(CategoryT c, nat n0, nat n1);
		void waste_mv(CategoryT c, nat n);
		void deck_mv();
		CategoryT get_tab() const;
		CategoryT get_foundation() const;
		CategoryT get_deck() const;
		CategoryT get_waste() const;
		bool valid_mv_exists const;
		bool is_win_state const;




}
#endif
