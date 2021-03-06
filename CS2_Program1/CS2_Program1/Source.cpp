/*
Joseph Williamson
Data Structures - Stringfellow
Program1
*/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

const int rowSIZE = 100;
const int colSIZE = 7;

// Function prototypes with perameters
void openFiles(ifstream&, ofstream&);
void populateArray(ifstream& inFileName, double athletes[rowSIZE][colSIZE], int &numAthletes);
void computeTotals(double athletes[rowSIZE][colSIZE]);
void printResults(double athletes[rowSIZE][colSIZE], int numAthletes);
void computeWinner(int numAthletes, double athletes[rowSIZE][colSIZE]);
void displayWinner(int bestAthlete, double athletes[rowSIZE][colSIZE]);

int main()
{
	double athletes[rowSIZE][colSIZE]; // created array to store values from the file
	int numAthletes=0; // used with the sentinel value to find total number of contestants

	ifstream inFileName; // name of the user file
	ofstream outFileName; // name of outfile if needed

	openFiles(inFileName, outFileName); // function call to retrieve inFileName, outFileName
	populateArray(inFileName, athletes, numAthletes); // function call fill array with file values
	printResults(athletes, numAthletes); // function call to print array
	computeWinner(numAthletes, athletes); // function call to decide the winner

	system("pause");
	return 0;
}

void openFiles(ifstream& infile, ofstream& outfile) // recieves the inFileName
	{
		char inFileName[40];
		char outFileName[40];
		cout << "Enter the input file name: ";
		cin >> inFileName;
		infile.open(inFileName); //open input file
		/*cout << "Enter the output file name: ";
		cin >> outFileName;
		outfile.open(outFileName); */
	}

void populateArray(ifstream& inFileName, double athletes[rowSIZE][colSIZE], int &numAthletes)
{
	double input;
	int i = 0;

	inFileName >> input; // stores values of file into input

	while (input != -1) // checks for sentinel value of -1 to stop
	{
		{
			for (int j = 0; j < colSIZE-1; j++) // fills the array except for total column
			{
				athletes[i][j] = input;
				inFileName >> input;
			}
			i++;
			numAthletes = i; // keeps track of total number of athletes
		}
	}
	computeTotals(athletes); // function call to find their totals and store them
}

void computeTotals(double athletes[rowSIZE][colSIZE]) // finds totals minus the lowest score
{
	double sum;
	double smallest;

	for (int i = 0; i < rowSIZE; i ++)
	{
		sum = 0;
		smallest = athletes[i][1];

		for (int j = 1; j < colSIZE-1; j++)
		{
			if (athletes[i][j] < smallest) // checks for lowest score
			{
				smallest = athletes[i][j];
			}
			sum += athletes[i][j]; // updates total
		}
		sum -= smallest;
		athletes[i][colSIZE-1] = sum;
	}
}

void printResults(double athletes[rowSIZE][colSIZE], int numAthletes) // displays on screen
{
	for (int i = 0; i < numAthletes; i++)
	{
		cout << "Contestant: " << setw(10) << athletes[i][0] << endl;
		cout << "Diving    : " << setw(10) << athletes[i][1] << endl;
		cout << "Gymnastics: " << setw(10) << athletes[i][2] << endl;
		cout << "Boxing    : " << setw(10) << athletes[i][3] << endl;
		cout << "Skating   : " << setw(10) << athletes[i][4] << endl;
		cout << "Posing    : " << setw(10) << athletes[i][5] << endl;
		cout << "TOTAL     : " << setw(10) << athletes[i][6] << endl;
		cout << endl;
	}
	cout << endl;
}

void computeWinner(int numAthletes, double athletes[rowSIZE][colSIZE]) // finds the winner
{
	int bestAthlete = 0;
	double bestScore = athletes[0][7]; // sets initial best to first contestant
	int i=0;

	for (int i = 0; i < numAthletes; i++) // checks each contestant
	{
		if (bestScore < athletes[i][7]) // compares against next contestant
		{
			bestScore = athletes[i][7];
			bestAthlete = i; // stores in int i
		}
	}
	displayWinner(bestAthlete, athletes); // calls to displayWinner
}

void displayWinner(int bestAthlete, double athletes[rowSIZE][colSIZE])
{
	cout << "Athlete of the year! Contestant " << athletes[bestAthlete][0] << " with a TOTAL score of "
		<< athletes[bestAthlete][6] << endl; // showcases the winner
}