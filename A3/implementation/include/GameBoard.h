// Alice Ip ipa1

/**
 *  \file GameBoard.h
 *  \brief A class that represents a gameboard with 
 *   interface to "play" the game
 */

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include "CardTypes.h"
#include "CardStack.h"

class BoardT
{
	private:
		/// Sequence of card stacks representing stacks on tableau
		std::vector <CardStackT> T;
		/// Sequence of card stacks representing stacks on foundation
		std::vector <CardStackT> F; 
		/// Card stack representing deck
		CardStackT D;
		/// card stack representing waste
		CardStackT W;

		bool valid_tab_tab(nat n0, nat n1) const;
		bool is_valid_pos(CategoryT t, nat n) const;
		bool valid_tab_mv() const;
		bool valid_waste_mv() const;
		bool valid_tab_foundation(nat n0, nat n1) const;

	public:
	    /**
	     *  \brief Constructor for board
	     *  \param d a vector representing a sequence of cards
	     */
		BoardT(std::vector<CardT> d);

	    /**
	     *  \brief Checks to see if the move from tableau is valid
	     *  \param c destination categoryT
	     *  \param n0 origin tableau position 
	     *  \param n1 destination categoryT position
	     *  \return boolean for validity
	     */
		bool is_valid_tab_mv(CategoryT c, nat n0, nat n1) const;

	    /**
	     *  \brief Checks to see if the move from waste is valid
	     *  \param c destination categoryT
	     *  \param n destination categoryT position
	     *  \return boolean for validity
	     */		
		bool is_valid_waste_mv(CategoryT c, nat n) const;

	    /**
	     *  \brief Checks to see if the mv from deck is valid
	     *  \return boolean for validity
	     */
		bool is_valid_deck_mv() const;

	    /**
	     *  \brief Performs a move from tab to c
	     *  \param c destination categoryT
	     *  \param n0 origin tableau position 
	     *  \param n1 destination categoryT position
	     */
		void tab_mv(CategoryT c, nat n0, nat n1);

	    /**
	     *  \brief Performs a move from waste to c
	     *  \param c destination categoryT
	     *  \param n destination categoryT position
	     */
		void waste_mv(CategoryT c, nat n);

	    /**
	     *  \brief Performs a move from deck to waste
	     */
		void deck_mv();

	    /**
	     *  \brief accesses a tableau card stack
	     *  \param n tableau position
	     *  \return corresponding card stack
	     */	
		CardStackT get_tab(nat n) const;

	    /**
	     *  \brief accesses a foundation card stack
	     *  \param n foundation position
	     *  \return corresponding card stack
	     */	
		CardStackT get_foundation(nat n) const;

	    /**
	     *  \brief accesses the deck card stack
	     *  \return deck card stack
	     */		
		CardStackT get_deck() const;

	    /**
	     *  \brief accesses the waste card stack
	     *  \return waste card stack
	     */		
		CardStackT get_waste() const;

	    /**
	     *  \brief checks if there is a valid tab move, waste move or deck move
	     *  \return boolean indicating whether any move exists
	     */		
		bool valid_mv_exists() const;

	    /**
	     *  \brief checks to see if the gameboard is in a win state
	     *  \return boolean indicating if gameboard is in a win state
	     */		
		bool is_win_state() const;

};
#endif
