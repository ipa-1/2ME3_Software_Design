
#include <iostream>
#include "GameBoard.h"
#include "View.h"

int main() {
  std::cout << "'make experiment' will run this main" << std::endl;
  BoardT board("in.txt");

  View view; // instantiating a view, do not do View view();, this does not work
  view.print(board);
  board.write("out.txt");
  

  return 0;
}
