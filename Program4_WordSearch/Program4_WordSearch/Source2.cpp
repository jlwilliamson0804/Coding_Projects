/*
Joseph Williamson
Data Structures - Stringfellow
WordSearch
This program reads in a puzzle from a file, stores the data, stores in words
to find, searches and matches each word if present in the puzzle, and displays
the appropriate message
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

void openFiles(ifstream & infile, ofstream & outfile);
void readData(ifstream & infile, char **&Puzzle, int &row, int &col);
void printPuzzle(ofstream& outfile, char **Puzzle, int row, int col);
void deallocatePuzzle(char **&Puzzle, int row);
bool wordSearch(ofstream& outfile, const string& word, int wordIndex,
	char **Puzzle, int row, int col, int& startRow, int& startCol,
	char& dir);
bool wordMatch(const string& word, int wordIndex, char **Puzzle,
	int row, int col, int startRow, int startCol, char dir);

int main()
{
	char **Puzzle = NULL; // dynamic 2d array created initially

	int row = 0;
	int col = 0;
	int wordIndex = 0;  //initialized variables used in puzzle/search/match
	int startRow = 0;
	int startCol = 0;
	char dir;

	string word;

	ifstream infile;
	ofstream outfile;

	//call to get file name from the user
	openFiles(infile, outfile);

	//call to read in and store the puzzle
	readData(infile, Puzzle, row, col);

	//call to print the puzzle
	printPuzzle(outfile, Puzzle, row, col);

	//loop to read in each word and search for it in the puzzle
	while (!infile.eof())
	{
		infile >> word;
		outfile << word << endl;
		wordSearch(outfile, word, wordIndex, Puzzle, row, col,
			startRow, startCol, dir);
	}

	//call to deallocate the 2d array
	deallocatePuzzle(Puzzle, row);

	system("pause");
	return 0;
}

/*
Purpose: retrieve a file from the user and outfile name
Receives: a file from user and outfile
Returns: file names
*/
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

/*
Purpose: This function takes the file, reads in number of rows/cols
	the loops to initialize the 2d array
Receives: infile, Puzzle, row, and col
Returns: updated row and col value, and an initialized Puzzle
*/
void readData(ifstream& infile, char **&Puzzle, int &row, int &col)
{
	infile >> row; //infile first number as rows
	infile >> col; //infile second number as columns

	Puzzle = new char*[row]; //sets size of 2d array from main

	for (int i = 0; i < row; i++)
	{
		Puzzle[i] = new char[col];          //loop to initialize entire puzzle
		for (int j = 0; j < col; j++)
		{
			infile >> Puzzle[i][j];
		}
	}
}

/*
Purpose: This function takes the puzzle and the current word,
	gets first letter in the word, and calls wordMatch, if 
	letter matches, match continues, if not Search will then
	move to the next letter in the puzzle. If entire word matches
	it will print where found and in what direction.
Receives: current word from eof loop, index, Puzzle row, col,
	starting row/col, dir.
Returns: A message of if word is found in puzzle or if not
	found with appropriate messages.
*/
bool wordSearch(ofstream& outfile, const string& word, int wordIndex, char
	**Puzzle, int row, int col, int& startRow, int& startCol, char& dir)
{
	bool found = false;
	startRow = 0;
	startCol = 0;

	while (found==false && startRow < row) //nested while loop to run through
	{                                      //puzzle until conditions met

		Puzzle[startRow][startCol]; //starts search at [0][0]
		
		while (found==false && (startCol < col))
		{
			if (wordMatch(word, wordIndex, Puzzle, row, col,
				startRow, startCol, 'A') ==true)
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 
					<< " going " << "Across" << endl;
				found = true;
				return found;
			}
			if (wordMatch(word, wordIndex, Puzzle, row, col,
				startRow, startCol, 'B'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Backwards" << endl;
				found = true;
				return found;
			}
			else if(wordMatch(word, wordIndex, Puzzle, row, col,
				startRow, startCol, 'U'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Up" << endl;
				found = true;
				return found;
			}
			else if(wordMatch(word, wordIndex, Puzzle, row, col,
				startRow, startCol, 'D'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Down" << endl;
				found = true;
				return found;
			}
			else if (wordMatch(word, wordIndex, Puzzle, row, col, startRow,
				startCol, 'l'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Diagonal Down Left" << endl;
				found = true;
				return found;
			}
			else if (wordMatch(word, wordIndex, Puzzle, row, col, startRow,
				startCol, 'r'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Diagonal Down Right" << endl;
				found = true;
				return found;
			}
			else if (wordMatch(word, wordIndex, Puzzle, row, col, startRow,
				startCol, 'R'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Diagonal Up Right" << endl;
				found = true;
				return found;
			}
			else if (wordMatch(word, wordIndex, Puzzle, row, col, startRow,
				startCol, 'L'))
			{
				outfile << "Found at " << startRow+1 << ", " << startCol+1 <<
					" going " << "Diagonal Up Left" << endl;
				found = true;
				return found;
			}

		startCol++; //moves to next col in puzzle

		}

		startCol = 0; //resets cols before updating row
		startRow++;   //goes to next row

	}

	if (found == false) //if not found in the puzzle, prints this message
		outfile << "Not found" << endl;

	return found;
}

/*
Purpose: to compare the position in Puzzle to current index letter of word,
	if passes the base cases and letter matches, performs a recursive call to
	check the next letter in the direction gives
Receives: word, index, Puzzle, row/col, starting row/col, and direction
Returns: a boolean value for found, to Search to display appropriate message
*/
bool wordMatch(const string& word, int wordIndex, char **Puzzle, int row,
	int col, int startRow, int startCol, char dir)
{
	bool found = false; //initialize found

	if (startCol > (col - 1) || startCol < 0) //base case checking col bounds
		return found;
	else if (startRow > (row - 1) || startRow < 0) //base case for row bounds
		return found;
	else if (wordIndex > (word.length() - 1)) //base case for longer index
		return found;
	else if (Puzzle[startRow][startCol] != word.at(wordIndex)) //current letter
		return found;
	else if (Puzzle[startRow][startCol] == (word.at(wordIndex)) &&
		wordIndex == word.length()-1)
	{
		found = true;      //if letter matches and its the last letter
		return found;      //in word return true
	}

	//recursive calls updating index, starting row/col depending on direction
	else if (dir == 'A')
		wordMatch(word, wordIndex + 1, Puzzle, row, col, startRow, startCol+1,
			dir);
	else if (dir == 'B')
		wordMatch(word, wordIndex+1, Puzzle, row, col, startRow, startCol-1,
			dir);
	else if (dir == 'U')
		wordMatch(word, wordIndex+1, Puzzle, row, col, startRow-1, startCol,
			dir);
	else if(dir == 'D')
		wordMatch(word, wordIndex+1, Puzzle, row, col, startRow+1, startCol,
			dir);
	else if (dir == 'R')
		wordMatch(word, wordIndex + 1, Puzzle, row, col, startRow - 1,
			startCol+1, dir);
	else if (dir == 'r')
		wordMatch(word, wordIndex + 1, Puzzle, row, col, startRow + 1,
			startCol+1, dir);
	else if (dir == 'L')
		wordMatch(word, wordIndex + 1, Puzzle, row, col, startRow - 1,
			startCol-1, dir);
	else if (dir == 'l')
		wordMatch(word, wordIndex + 1, Puzzle, row, col, startRow + 1,
			startCol-1, dir);
}

/*
Purpose: to display the Puzzle
Receives: Puzzle, row/col
Returns: a displayed Puzzle
*/
void printPuzzle(ofstream& outfile, char **Puzzle, int row, int col)
{
	outfile << "Puzzle: " << row << "," << col << endl;
	for (int i = 0; i < row; i++)
	{
		outfile << endl;
		for (int j = 0; j < col; j++)
			outfile << Puzzle[i][j];
	}
	outfile << endl << endl;
	outfile << "Words to find:" << endl << endl;
}

/*
Purpose: to deallocate the 2d array Puzzle
Receives: Puzzle, row
Returns: A deallocated Puzzle
*/
void deallocatePuzzle(char **&Puzzle, int row)
{
	for (int i = 0; i < row; i++)
		delete[] Puzzle[i];
	delete[] Puzzle;
}