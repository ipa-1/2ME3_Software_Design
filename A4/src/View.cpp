//Alice Ip ipa1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using std::vector;
using namespace std;

#include "CellTypes.h"
#include "GameBoard.h"
#include "View.h"


View::View() {};

void View::print(BoardT b) const
{
	cellT** B = b.getBoard();
	//rows = b.size
	int rows = b.getRows();
	//std::cout<< "Rows: " << rows  << std::endl;
	int columns = b.getColumns();
	//std::cout<< "Columns: " << rows  << std::endl;

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			std::cout << B[i][j];
		}
		std::cout  << std::endl;
	}
}



