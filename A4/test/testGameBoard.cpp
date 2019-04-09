#include <iostream>
#include <stdexcept>

#include "catch.h"
#include "CellTypes.h"
#include "GameBoard.h"


/**
 * NOTE: To cautious readers! Many of these tests would be cleaner if
 * the equality (==) operator was overloaded for CardT. This has been
 * omitted for accessibility. I encourage those comfortable with C++ to
 * read more about it though :)
 *
 * You can find an example here:
 * https://gitlab.cas.mcmaster.ca/smiths/se2aa4_cs2me3/blob/master/Assignments/PreviousYears/2018/A3/A3Soln/implementation/include/PointADT.h#L21
 */


TEST_CASE("tests for GameBoard", "[BoardT]") {

  SECTION("BoardT(): read file incorrect") {

    //BoardT board("in2.txt");
    REQUIRE_THROWS_AS(BoardT ("in2.txt"),std::invalid_argument);
  }

  //   SECTION( "BoardT(): Empty card sequence to board initializer exception"){
  //   std::vector<CardT> emptyVector;
  //   REQUIRE_THROWS_AS(BoardT (emptyVector),std::invalid_argument);
  // }


  

}
