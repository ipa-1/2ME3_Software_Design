#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include "CellTypes.h"
#include <string>
#include <vector>

class BoardT {
 private:

 	 /**
	 * 2D array that holds the state of cells on the board
	 */
 	cellT** B;

 	 /**
	 * variable to hold number of rows in gameboard
	 */
 	int rows;

 	 /**
	 * variable to hold number of columns in gameboard
	 */
 	int columns;

 public:

	/**
	 *  \brief Constructor for board that takes a file name
	 *  \param fname name of file holding initial state
	 */
  	BoardT(std::string fname);

	/**
	 *  \brief Constructor for board that takes an array, row and column
	 *  \param b array holding state of board
	 *  \param r number of rows in array
	 *  \param c number of columns in array
	 */
  	BoardT(cellT** b, int r, int c);

	/**
	 *  \brief Reads a txt file and initializes the state of the gameboard
	 *  \param fname name of the file to be read
	 */
  	void read(std::string fname);

	/**
	 *  \brief writes state of gameboard to a file
	 *  \param fname name of the file to write state of gameboard
	 */
  	void write(std::string fname) const;

  	/**
	 *  \brief Accessor for the number of rows
	 *  \returns an int indicating the number of rows in the gameboard
	 */	
  	int getRows() const;

  	/**
	 *  \brief Accessor for the number of columns
	 *  \returns an int indicating the number of columns in the gameboard
	 */							
  	int getColumns() const;

  	 /**
	 *  \brief Computes the next gameboard state
	 *  \returns a gameboard with the next state
	 */				
  	BoardT nextState();

  	 /**
	 *  \brief Checks if the cell at the given row and column is a valid cell in the gameboard
	 *  \param a row number
	 *  \param b column number
	 *  \returns an boolean indicating if valid cell
	 */				
  	bool isValidCell(int a, int b) const;

  	 /**
	 *  \brief Counts the number of neighbours to given cell that are alive
	 *  \param a row number
	 *  \param b column number
	 *  \returns int indicating number of alive neighbours
	 */	
  	int neighbourCount(int a, int b) const;

  	 /**
	 *  \brief Checks if the cell at the given row and column is alive in next state
	 *  \param a row number
	 *  \param b column number
	 *  \returns an boolean indicating if cell is alive in next state
	 */	
  	bool survives(int a, int b) const;

  	 /**
	 *  \brief Accesses the cell at the given row and column
	 *  \param a row number
	 *  \param b column number
	 *  \returns an cell value
	 */	
  	cellT getCell(int a, int b) const;        

};

#endif




