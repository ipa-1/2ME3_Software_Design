#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include "CellTypes.h"
#include <string>
#include <vector>

class BoardT {
 private:
 	cellT** B;
 	std::vector<std::vector<int>> B2;
 	int rows;
 	int columns;
  //array
  //std::vector<int> m_t;
  //std::vector<CardStackT> m_f;
  //CardStackT m_d;
  //CardStackT m_w;

 public:
  BoardT(std::string fname);
  void read(std::string fname);
  void write(std::string fname) const;
  cellT** getBoard() const;
  int getRows() const;
  int getColumns() const;
  void BoardT::nextMove();

};

#endif

//using a GridT, which is an array



