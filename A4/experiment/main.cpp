
#include <iostream>
#include "GameBoard.h"
#include "View.h"

int main() {
  std::cout << "'make experiment' will run this main" << std::endl;
  BoardT board("in.txt");

  View view; // instantiating a view, do not do View view();, this does not work
  view.print(board);
  BoardT board2 = board.nextState();
  std::cout << std::endl;

  view.print(board2);
  std::cout<< "Done" << std::endl;
  //board.write("out.txt");
  

  return 0;
}
