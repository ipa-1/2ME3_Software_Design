#include <iostream>
#include <stdexcept>

#include "catch.h"
#include "BoardTypes.h"
#include "GameBoard.h"
#include "View.h"

TEST_CASE("tests for GameBoard", "[BoardT]") {

  SECTION("read(): read file incorrect") {
    REQUIRE_THROWS_AS(BoardT ("in2.txt"),std::invalid_argument);
  }

  SECTION("read(): Verification that cells are ALIVE or DEAD in state variables as expected from file") {
    BoardT board("in.txt");
    REQUIRE(board.getCell(0,0) == DEAD);
    REQUIRE(board.getCell(0,1) == ALIVE);
    REQUIRE(board.getCell(0,2) == DEAD);
    REQUIRE(board.getCell(1,0) == DEAD);
    REQUIRE(board.getCell(1,1) == ALIVE);
    REQUIRE(board.getCell(1,2) == ALIVE);
    REQUIRE(board.getCell(2,0) == ALIVE);
    REQUIRE(board.getCell(2,1) == ALIVE);
    REQUIRE(board.getCell(2,2) == ALIVE);
  }

  SECTION("read(): Verification that rows and columns are as expected from file") {
    BoardT board("in.txt");
    REQUIRE(board.getRows() == 3);
    REQUIRE(board.getColumns() == 3);
  }

  SECTION("read(): Reading empty file") {
    REQUIRE_THROWS_AS(BoardT ("in4.txt"),std::invalid_argument);
  }

  SECTION("write(): Checking that after writing, if the same file is read, the cellT values are the same"){
    BoardT board("in.txt");
    board.write("out2.txt");
    BoardT board2("out2.txt");
    REQUIRE(board2.getCell(0,0) == DEAD);
    REQUIRE(board2.getCell(0,1) == ALIVE);
    REQUIRE(board2.getCell(0,2) == DEAD);
    REQUIRE(board2.getCell(1,0) == DEAD);
    REQUIRE(board2.getCell(1,1) == ALIVE);
    REQUIRE(board2.getCell(1,2) == ALIVE);
    REQUIRE(board2.getCell(2,0) == ALIVE);
    REQUIRE(board2.getCell(2,1) == ALIVE);
    REQUIRE(board2.getCell(2,2) == ALIVE);
  }

  SECTION("write(): Checking that after writing, size of row and column are the same"){
    BoardT board("in.txt");
    board.write("out2.txt");
    BoardT board2("out2.txt");
    REQUIRE(board2.getRows() == 3);
    REQUIRE(board2.getColumns() == 3);
  }


  // SECTION("isValidCell(): Out of bounds: Corner"){
  //   BoardT board("in.txt");
  //   REQUIRE(board.isValidCell(-1,-1) == false);
  //   REQUIRE(board.isValidCell(-1,3) == false);
  //   REQUIRE(board.isValidCell(3,-1) == false);
  //   REQUIRE(board.isValidCell(3,3) == false);

  // }

  // SECTION("isValidCell(): Out of bounds: Side"){
  //   BoardT board("in.txt");
  //   REQUIRE(board.isValidCell(-1,1) == false);
  //   REQUIRE(board.isValidCell(0,-1) == false);
  //   REQUIRE(board.isValidCell(0,3) == false);
  //   REQUIRE(board.isValidCell(3,1) == false);

  // }

  // SECTION("isValidCell(): In bounds: Corner"){
  //   BoardT board("in.txt");
  //   REQUIRE(board.isValidCell(0,0) == true);
  //   REQUIRE(board.isValidCell(0,2) == true);
  //   REQUIRE(board.isValidCell(2,0) == true);
  //   REQUIRE(board.isValidCell(2,2) == true);

  // }

  // SECTION("isValidCell(): In bounds: Side"){
  //   BoardT board("in.txt");
  //   REQUIRE(board.isValidCell(1,0) == true);
  //   REQUIRE(board.isValidCell(1,2) == true);
  //   REQUIRE(board.isValidCell(0,1) == true);
  //   REQUIRE(board.isValidCell(2,1) == true);

  // }

  //   SECTION("isValidCell(): In bounds: Center"){
  //   BoardT board("in.txt");
  //   REQUIRE(board.isValidCell(1,1) == true);
  // }

  // SECTION("neighbourCount(): Successful count"){
  //   BoardT board("in.txt");
  //   //View view; // instantiating a view, do not do View view();, this does not work
  //   //view.print(board);
  //   //std::cout  << std::endl;
  //   REQUIRE(board.neighbourCount(1,1) == 5);
  // }

  // SECTION("neighbourCount(): Corner cell"){
  //   BoardT board("in.txt");
  //   //View view; // instantiating a view, do not do View view();, this does not work
  //   //view.print(board);
  //   //std::cout  << std::endl;
  //   REQUIRE(board.neighbourCount(0,0) == 2);
  // }

  // SECTION("survives(): live cell fewer than two live neighbours"){
  //   BoardT board("in3.txt");
  //   REQUIRE(board.survives(3,1) == false);
  // }

  // SECTION("survives(): live cell with two neighbours"){
  //   BoardT board("in3.txt");

  //   REQUIRE(board.survives(1,3) == true);
  // }

  // SECTION("survives(): live cell with three neighbours"){
  //   BoardT board("in3.txt");
  //   REQUIRE(board.survives(1,0) == true);
  // }

  // SECTION("survives(): live cell with more than three neighbours"){
  //   BoardT board("in3.txt");

  //   REQUIRE(board.survives(0,2) == false);
  // }

  // SECTION("survives(): dead cell with exactly three neighbours"){
  //   BoardT board("in3.txt");
  //   REQUIRE(board.survives(0,0) == true);
  // }

  SECTION("nextState(): Row and column sizes of next state are consistent"){
    BoardT board("in.txt");
    BoardT board2 = board.nextState();

    REQUIRE(board.getColumns() == board2.getColumns());
    REQUIRE(board.getRows() == board2.getRows());
  }  

  SECTION("nextState(): ALIVE and DEAD are as expected in next state"){
    BoardT board("in.txt");
    BoardT board2 = board.nextState();

    REQUIRE(board2.getCell(0,0) == DEAD);
    REQUIRE(board2.getCell(0,1) == ALIVE);
    REQUIRE(board2.getCell(0,2) == ALIVE);
    REQUIRE(board2.getCell(1,0) == DEAD);
    REQUIRE(board2.getCell(1,1) == DEAD);
    REQUIRE(board2.getCell(1,2) == DEAD);
    REQUIRE(board2.getCell(2,0) == ALIVE);
    REQUIRE(board2.getCell(2,1) == DEAD);
    REQUIRE(board2.getCell(2,2) == ALIVE);
  }

}
