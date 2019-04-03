/**
 * \file CardTypes.h
 * \author Emily Horsman <horsmane@mcmaster.ca>
 * \brief Provides type definitions and enumerations for a game of
 *        Forty Thieves.
 */
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 * \brief Describes the valid types of columns of cards on the board.
 */
enum CategoryT {
  Deck,        ///< The playing deck.
  Waste,       ///< The stack the deck is drawn into.
  Foundation,  ///< The foundations where winning columns are placed.
  Tableau      ///< The playing stacks.
};

/**
 * \brief Describes the possible card suits.
 */
enum cellT {
  ALIVE,
  DEAD,
};

/**
 * \brief Describes the rank of a card.
 */
typedef unsigned short int RankT;

/**
 * \brief Size of the board
 */
#define SIZE    4


/**
 * \brief A playing card with suit and rank.
 */
struct CardT {
  SuitT s;
  RankT r;
};

typedef struct CardT CardT;

#endif
