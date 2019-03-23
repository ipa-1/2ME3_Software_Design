/**
 * \file CardTypes.h
 * \author Alice Ip ipa1
 * \brief
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

enum SuitT {Heart, Diamond, Club, Spade};
enum CategoryT {Tableau, Foundation, Deck, Waste};


struct CardT {
	SuitT s;
	RankT r;
};

#endif
