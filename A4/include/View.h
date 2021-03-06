/**
 * \file GameBoard.h
 * \author Alice Ip
 * \brief View for viewing a gameboard in Conway's Game of Life
 */
#ifndef A4_VIEW_H_
#define A4_VIEW_H_

#include "BoardTypes.h"
#include <string>
#include <vector>

class View {
 private:

 public:

  /**
   *  \brief Constructor for a view
   */
   View();

  /**
   *  \brief prints out the board
   *  \param b board to be printed out
   */
   void print(BoardT b) const;

};

#endif




