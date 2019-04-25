#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {

	int sheetsNumber;
	double long sheetWidth; // x
	double long sheetHeight; // y
	
	string path = "bugtrkIn.txt";
	ifstream fin;
	fin.open(path);

	if (fin.is_open())
	{
		fin >> sheetsNumber && fin >> sheetWidth && fin >> sheetHeight;
	}
	fin.close();
	
	double long minimalSquare;
	int minimalSquareNumber;
	int rawsNumber;
	double long sideLength;

	double long sheetsArea = (sheetsNumber * sheetWidth * sheetHeight); // search S

	if (sheetWidth >= sheetHeight) { // search q
		minimalSquare = pow(sheetWidth, 2);
	}
	else {
		minimalSquare = pow(sheetHeight, 2);
	}

	minimalSquareNumber = ceil(sheetsArea / minimalSquare); // number q
	rawsNumber = ceil(sqrt(minimalSquareNumber)); // R
	sideLength = double(sheetHeight * rawsNumber); // a

	ofstream fout;
	fout.open("bugtrkOut.txt");

	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		fout << fixed << sideLength << endl;
	}
	fout.close();
	
	system("pause");
	return 0;
}
