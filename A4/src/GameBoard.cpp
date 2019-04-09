//Alice Ip ipa1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using std::cerr;
using std::endl;
using std::ofstream;
#include <cstdlib> // for exit function

using std::vector;
using namespace std;

#include "CellTypes.h"
#include "GameBoard.h"


BoardT::BoardT(string fname) 
:rows(0), columns(0)
{
	read(fname);
};

BoardT::BoardT(cellT** b) 
:rows(0), columns(0)
{};

void BoardT::write(std::string fname) const
{
	//std::cout << fname << std::endl;

	std::ofstream ofile;
	ofile.open(fname);

	if( !ofile ) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }

    std::string line;

	for (int i=0; i<rows; i++){
		for (int j=0; j<columns; j++)
			ofile << B[i][j];
		ofile << endl; 
	}

	ofile.close();	
}

void BoardT::read(std::string fname)
{
	//std::cout << "read start" << std::endl;
	//std::cout << fname << std::endl;

	std::ifstream file;
	file.open(fname);

	int prevColumns = 0;
	std::string line;

	// Identify number of rows and columns
	if (file.is_open()){
		while (getline(file,line)){

			line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
			columns = line.length();

			//std::cout << "length: " << columns << " " << line << std::endl;
			if (rows > 0 && columns != prevColumns){ throw std::invalid_argument("File does not have consistent columns");}
			prevColumns = columns;
			rows+=1;
		}

		file.close();
	}
	else{std::cout << "couldn't be opened" << std::endl;}



	// Create the array to hold file information
	 B = new cellT*[rows];
	for(int i = 0; i < rows; ++i)
    	B[i] = new cellT[columns];

	// Store the information in the file in the gameboard
	file.open(fname);
	int rowIndex = 0;


	if (file.is_open()){
		while (getline(file,line)){

			//std::cout << line << std::endl;
			for (int x = 0; x < columns;x++){
				if (line[x] == 'o')
					B[rowIndex][x] = ALIVE;
				else
					B[rowIndex][x] = DEAD;
				//std::cout << line[x] << std::endl;
			}
			rowIndex+=1;
		}
		file.close();
	}
	else{
		std::cout << "couldn't be opened" << std::endl;
	}

	//std::cout  << std::endl;

	// for (int i = 0; i < rows; i++){
	// 	for (int j = 0; j < columns; j++){
	// 		std::cout << B[i][j];
	// 	}
	// 	std::cout  << std::endl;
	// }
	//std::cout << "read end" << std::endl;
}

cellT** BoardT::getBoard() const
{
	return B;
}

int BoardT::getRows() const
{
	return rows;
}

int BoardT::getColumns() const{
	return columns;
}

bool BoardT::isValidCell(int a, int b) const{
	if (a < 0 || a >= rows || b < 0 || b >= columns)
		return false;
	else
		return true;
}

int BoardT::neighbourCount(int a, int b) const{
	int count = 0;
	for (int i = a-1; i < a+2; i++){
		for (int j = b-1; j < b+2; j++){
			
			if (i == a && j == b){
				//std::cout<<B[i][j];
				continue;
			}
			if (isValidCell(i,j)){
				//std::cout<<B[i][j]  ;
				if (B[i][j] == ALIVE)
					count +=1;
			}
		}
		//std::cout  << std::endl;
	}
	return count;
} 



bool BoardT::survives(int a, int b) const{
	int nCount = neighbourCount(a,b);

	if (B[a][b] == DEAD){
		if (nCount == 3)
			return true;
		else
			return false;
	}
	else{
		if (nCount == 2 || nCount == 3 )
			return true;
		else
			return false;
	}
}

BoardT BoardT::nextState(){

	cellT** N = new cellT*[rows];

	for(int i = 0; i < rows; ++i)
    	N[i] = new cellT[columns];

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			if (survives(i,j))
				N[i][j] = ALIVE;
		}
		//std::cout  << std::endl;
	}

	BoardT newBoard(N);
	return newBoard;
}


