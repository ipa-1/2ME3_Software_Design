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
  BoardT(cellT** b);

  void read(std::string fname);
  void write(std::string fname) const;
  cellT** getBoard() const;
  int getRows() const;
  int getColumns() const;
  bool isValidCell(int a, int b) const;
  int neighbourCount(int a, int b) const;
  BoardT nextState();
  bool survives(int a, int b) const;


};

#endif

//using a GridT, which is an array



