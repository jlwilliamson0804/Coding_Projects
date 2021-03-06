/*
Joseph Williamson
Data Structures - Stringfellow
WordSearch
Description:
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

void openFiles(ifstream & infile, ofstream & outfile);
void readData(ifstream & infile, int **&Puzzle, int &row, int &col);
void printPuzzle(int **Puzzle, int row, int col);
void deallocatePuzzle(int **&Puzzle, int row);

int main()
{
	int **Puzzle = NULL;

	int row = 0;
	int col = 0;

	ifstream infile;
	ofstream outfile;

	openFiles(infile, outfile);
	readData(infile, Puzzle, row, col);
	printPuzzle(Puzzle, row, col);

	system("pause");
	return 0;
}

//openFiles
void openFiles(ifstream & infile, ofstream & outfile)
{
	char inFileName[40];
	char outFileName[40];

	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}


//readData
void readData(ifstream& infile, int **&Puzzle, int &row, int &col)
{
	infile >> row;
	infile >> col;

	Puzzle = new int*[row];
	for (int i = 0; i < row; i++)
		Puzzle[i] = new int[col];
}

//wordSearch

//wordMatch

//printPuzzle
void printPuzzle(int **Puzzle, int row, int col)
{
	cout << "Puzzle:" << endl;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cout << Puzzle[i][j];
}

//deallocate
void deallocatePuzzle(int **&Puzzle,int row)
{
	for (int i = 0; i < row; i++)
		delete[] Puzzle[i];
	delete[] Puzzle;
}