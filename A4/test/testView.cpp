/**
 * \file testView.cpp
 * \author Alice Ip
 * \brief Test for view for Conway's Game of Life
 */
#include <iostream>
#include <stdexcept>

#include "catch.h"
#include "BoardTypes.h"
#include "GameBoard.h"
#include "View.h"

TEST_CASE("tests for View", "[View]") {
  std::cout  << std::endl;

  SECTION("print() ") {
    std::cout<< "Test print 1:"  << std::endl;
    BoardT board("in.txt");
    View view; 
    view.print(board);

  }

  SECTION("print() ") {
    std::cout<< "Test print 2:"  << std::endl;
    BoardT board("in3.txt");
    View view; 
    view.print(board);

  }

}
