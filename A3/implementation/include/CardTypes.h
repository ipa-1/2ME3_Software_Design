/**
 *  \file CardTypes.h
 *  \author Alice Ip ipa1
 *  \brief header file with all types needed to implement a deck of cards
 */

#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief typedef for a natural number represented by unsigned int
 */
typedef unsigned int nat;

/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

/**
 * \brief Total cards in game
 */
#define TOTAL_CARDS   104

/**
 * \brief All possible card suits
 */
enum SuitT {Heart, Diamond, Club, Spade};

/**
 * \brief Categories of card stacks in the game
 */
enum CategoryT {Tableau, Foundation, Deck, Waste};


/**
 * \brief a tuple type for a card, with a suit and a rank
 */
struct CardT {
	SuitT s;
	RankT r;
};

#endif
