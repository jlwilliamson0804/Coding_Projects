#include <iostream>
#include <fstream>
#include "SortedList.h"

using namespace std;

const int MAX = 26;

void openFiles(ifstream & infile, ofstream & outfile);
void populateArray(ifstream & infile, ofstream & outfile, SortedList MyArray[MAX]);
void printList(SortedList & l);


int main()
{

	SortedList MyArray[MAX];
	
	ifstream infile;
	ofstream outfile;

	openFiles(infile, outfile);
	populateArray(infile, outfile, MyArray);



	system("pause");
	return 0;
}

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

void populateArray(ifstream & infile, ofstream & outfile, SortedList MyArray[MAX])
{
	
}

void printList(SortedList & l)
{
	string word;
	int freq;

	l.resetList();
	while (!l.atEnd())
	{
		l.retrieveNextword(word, freq);
		cout << word << "  " << freq << endl;
	}
}
