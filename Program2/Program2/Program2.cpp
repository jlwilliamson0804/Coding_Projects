/*
Joseph Williamson
Comp Sci 2 - Stringfellow
Program 2
This program creates an array of objects, reads a file,
stores the values using set() member functions, finds
the total minus the lowest score, finds the highest total,
and displays the results to a file in a table.
*/

#include "Athletes.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

const int MAXATHLETES = 100; // creates a max number of athletes

// prototype to open files
void openFiles(ifstream & infile, ofstream & outfile);
// prototype to read in data from file, and store in object array
void getAthlete(ifstream & infile, int & numAthletes,
	athletes athletesArray[MAXATHLETES]);
// prototype to find the total of all scores
void updateTotal(athletes athletesArray[MAXATHLETES], int & numAthletes);
// prototype to display all results
void printAthletes(int bestAthlete, athletes athletesArray[MAXATHLETES],
	int & numAthletes, ofstream & outfile);
// prototype to determine the best athlete
void findWinner(athletes athletesArray[MAXATHLETES], int & numAthletes,
	ofstream & outfile);

int main()
{
	ifstream infile;
	ofstream outfile;
	int numAthletes = 0;

	athletes athletesArray[MAXATHLETES]; // created array of objects

	openFiles(infile, outfile); // function call to open files
	getAthlete(infile, numAthletes, athletesArray); // call to read in data
	updateTotal(athletesArray, numAthletes); // call to find totals
	findWinner(athletesArray, numAthletes, outfile); // call to find the best
	
	system("pause");
	return 0;
}

// Purpose: The purpose of openFiles is to open data and outfile.
// Receives: This function recieves location for infile/outfile.
// Returns: This function returns data of infile.
void openFiles(ifstream & infile, ofstream & outfile)
{
	char inFileName[40];
	char outFileName[40];

	//open input file
	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);

	//open out putfile
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

// Purpose: The purpos of getAthlete is to retrieve and store info into 
// an object array.
// Receives: This function receives infile, object array, and number 
// of athletes.
// Returns: This function returns a filled objects array with all
// athlete info except total, also the updated number of athletes.
void getAthlete(ifstream & infile, int & numAthletes,
	athletes athletesArray[MAXATHLETES])
{
	string contestantName;
	double contestantNumber;
	double Dive;
	double Gym;
	double Box;
	double Skate;
	double Pose;
	
	infile >> contestantNumber; // read in first data

	while (!infile.eof()) // end of file loop
	{
		athletesArray[numAthletes].setContestantNumber(contestantNumber); // stores
		infile >> contestantName; // reads second data
		athletesArray[numAthletes].setContestantName(contestantName); // stores
		infile >> Dive; // read third data
		athletesArray[numAthletes].setDiveScore(Dive); // stores
		infile >> Gym; // read fourth data
		athletesArray[numAthletes].setGymScore(Gym); // stores
		infile >> Box; // read fifth data
		athletesArray[numAthletes].setBoxScore(Box); // stores
		infile >> Skate; // read sixth data
		athletesArray[numAthletes].setSkateScore(Skate); // stores
		infile >> Pose; // read seventh data
		athletesArray[numAthletes].setPoseScore(Pose); // stores
		
		numAthletes++; // updates number of athletes
		
		infile >> contestantNumber; // reads in the next data to fill next object
	}
}

// Purpose: The purpose of updateTotal is to find the total score
// minus the lowest score, and store it.
// Receives: object array, and number of athletes
// Returns: Returns the total stored in each athlete object
void updateTotal(athletes athletesArray[MAXATHLETES], int & numAthletes)
{
	double lowestScore = 0; // initialize lowest score to zero
	double Box, Dive, Gym, Pose, Skate;
	double total;

	for (int i = 0; i < numAthletes; i++)
	{
		Box = athletesArray[i].getBoxScore(); // sets scores to a variable
		Dive = athletesArray[i].getDiveScore();
		Gym = athletesArray[i].getGymScore();
		Pose = athletesArray[i].getPoseScore();
		Skate = athletesArray[i].getSkateScore();

		lowestScore = Dive; // initializes lowest to Dive score

		if (Box < Dive) // checks next scores to find lowest
		{
			lowestScore = Box;
		}
		if (Gym < Dive)
		{
			lowestScore = Gym;
		}
		if (Pose < Dive)
		{
			lowestScore = Pose;
		}
		if (Skate < Dive)
		{
			lowestScore = Skate;
		}

		total = Box + Dive + Gym + Pose + Skate; // updates total
		total -= lowestScore; // finds total minus lowest score
		
		athletesArray[i].setTotal(total); // sets total for each athlete
	}
}

// Purpose: The purpose of findWinner is to find the athlete
// with the best total, and call to print all results
// Recieves: athletesArray, numAthletes, outfile
// Returns: findWinner returns the bestAthlete and location
// to access winner.
void findWinner(athletes athletesArray[MAXATHLETES], int & numAthletes,
	ofstream & outfile)
{
	int bestAthlete = 0; // location to access best athlete
	double bestTotal = athletesArray[0].getTotal(); // initial best is 1st athlete
	int i = 0;

	for (int i = 0; i < numAthletes; i++) // loops all athletes findind best
	{
		if (bestTotal < athletesArray[i].getTotal())
		{
			bestTotal = athletesArray[i].getTotal();
			bestAthlete = i; // updates location value
		}
	}
	printAthletes(bestAthlete, athletesArray, numAthletes, outfile); // call
}

// Purpose: The purpose of printAthletes is to create a table 
// and display all results, including: athletes and scores, and best athlete
// Receives: bestAthlete, athletesArray, numAthletes, outfile
// Returns: This function returns a displayed table of all results
// including: athletes and scores, and the best athlete.
void printAthletes(int bestAthlete, athletes athletesArray[MAXATHLETES],
	int & numAthletes, ofstream & outfile)
{
	for (int i = 0; i < numAthletes; i++) // loop to display all athletes and scores
	{
		outfile << "Contestant: " << setw(2) << athletesArray[i].getContestantNumber() <<
			setw(8) << "Name: " << setw(10) << athletesArray[i].getContestantName() <<
			setw(12) << "Diving: " << setw(5) << "Gymnastics: " << setw(5) <<
			"Posing: " << setw(5) << "Boxing: " << setw(5) << "Skating: " <<
			setw(5) << "Total: " << endl;
		outfile << setw(39) << athletesArray[i].getDiveScore() << " " << setw(7)
			<< athletesArray[i].getGymScore() << " " << setw(11) <<
			athletesArray[i].getPoseScore() << " " << setw(7) <<
			athletesArray[i].getBoxScore() << " " << setw(7) <<
			athletesArray[i].getSkateScore() << " " << setw(9) <<
			athletesArray[i].getTotal() << endl << endl;
	}
	outfile << "ATHLETE OF THE YEAR: " << athletesArray[bestAthlete].getContestantName()
		 << ", contestant " << athletesArray[bestAthlete].getContestantNumber() 
		 << " with a TOTAL of " << athletesArray[bestAthlete].getTotal() <<
		endl;
}