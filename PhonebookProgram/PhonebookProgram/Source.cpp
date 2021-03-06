/*
Joseph Williamson
Data Structures - Stringfellow
10/18/17
Description: This program receives a file from the user,
stores data in an array of objects, displays unsorted,
sorts by name and display, then sorts by number and display
*/

#include "PhoneEntry.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

//sets max number of objects
const int MAXENTRY = 100;

// prototypes
void openFiles(ifstream & infile, ofstream & outfile);
void getEntry(ifstream & infile, ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY]);
void displayData(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N);
void nameSort(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N);
void numSort(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N);

int main()
{
	ifstream infile;
	ofstream outfile;

	//array of objects
	PhoneEntry PhoneBook[MAXENTRY];

	PhoneEntry *ArrayPtR = &PhoneBook[MAXENTRY]; // Ptr to array of objects

	int N = 0; // keep track first number in file

	openFiles(infile, outfile);
	getEntry(infile, outfile, PhoneBook);
	
	delete ArrayPtR; // deletes Ptr to array

	system("pause");
	return 0;
}

/*
openFiles purpose is to read in the file names
given by the user, and stores them
*/
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

/*
getEntry purpose is to read in the data from the file,
store it's info into an array of objects and the number
of entries. It then calls to display the data
*/
void getEntry(ifstream & infile, ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY])
{
	int N;
	string PersonName;
	string PersonNum;

	infile >> N;
	for(int i = 0; i < N; i++)
	{
		// stores data
		infile >> PersonName;
		infile >> PersonNum;

		// calls object member to set the data
		PhoneBook[i].setPersonName(PersonName);
		PhoneBook[i].setPersonNum(PersonNum);
	}

	// call to displayData
	displayData(outfile, PhoneBook, N);

}

/*
The purpose of displayData is to outfile the data
unsorted, and call to nameSort
*/
void displayData(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N)
{
	outfile << endl;
	outfile << "Welcome to the Phone Entry Program! \n\n";
	outfile << "Unsorted Entries \n";
	outfile << "Name" << setw(15) << "Number" << endl;
	for (int i = 0; i < N; i++)
	{
		outfile << setw(13) << left << PhoneBook[i].getPersonName()
			<< PhoneBook[i].getPersonNum() << endl;
	}

	// call to nameSort
	nameSort(outfile, PhoneBook, N);
}

/*
Purpose of nameSort is to recieve in the unsorted data
and sort by selection sort by name, display that,
and call numSort
*/
void nameSort(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N)
{
	int mindex;
	
	for (int i = 0; i < N - 1; i++)
	{
		mindex = i;

		//find index of min element in unsorted array
		for (int j = i + 1; j < N; j++)
		{
			if (PhoneBook[j].getPersonName().compare(PhoneBook[mindex].getPersonName()) < 0)
				mindex = j;
		}

		//swap 1st unsorted element with minimum element
		PhoneBook[i].swapEntry(PhoneBook[mindex]);
	}

	outfile << endl;
	outfile << "List sorted by Name" << endl;
	
	for (int i = 0; i < N; i++)
	{
		outfile << setw(13) << left << PhoneBook[i].getPersonName()
			<< PhoneBook[i].getPersonNum() << endl;
	}

	// call to numSort
	numSort(outfile, PhoneBook, N);

}

/*
The purpose of numSort is to recieve the data and sort by 
insertion sort, by number, and display the data
*/
void numSort(ofstream & outfile, PhoneEntry PhoneBook[MAXENTRY], int N)
{
		bool found;
		int j;

		//put each element in unsorted array in proper position
		for (int i = 1; i < N; i++)
		{
			//find proper place for a[i] relative to a[0]..a[i]
			found = false;
			j = i;
			while ((j > 0) && !found)
			{
				//swap and decrement j
				if (PhoneBook[j].getPersonNum().compare(PhoneBook[j - 1].getPersonNum())<0)
				{
					PhoneBook[j].swapEntry(PhoneBook[j - 1]);
				j = j - 1;
				}
				else
					found = true;
			}
		}

		outfile << endl;
		outfile << "List sorted by Number" << endl;
		
		for (int i = 0; i < N; i++)
		{
			outfile << setw(13) << left << PhoneBook[i].getPersonName()
				<< PhoneBook[i].getPersonNum() << endl;
		}

}
