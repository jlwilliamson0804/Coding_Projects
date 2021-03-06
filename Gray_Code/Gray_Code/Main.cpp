/*
Joseph Williamson
Discrete Structures - Stringfellow
9/24/2018
Purpose: to recieve in a data file, and calculate
gray code number and gray code position
*/
#include<iostream>
#include<fstream>

using namespace std;

int computeGrayInt(int m, int j);
int computeGrayPosition(int g);
void openFile(ifstream & infile, ofstream& outfile);

int main()
{
	ifstream infile;
	ofstream outfile;
	int num = 0;
	char call;
	int m, j, g = 0;

	cout << "Joseph Williamson \n";
	openFile(infile, outfile); // call to recieve file

	infile >> num; //infiles how many numbers
	for (int i = 0; i < num; i++)
	{
		infile >> call; //check for A or B
		if (call == 'A')
		{
			infile >> m >> j;
			outfile <<computeGrayInt(m, j) << "\n";
		}
		else if (call == 'B')
		{
			infile >> g;
			computeGrayPosition(g);
		}
		else //in case call is neither A or B
			outfile << "error in data file: must be an A or B \n";
	}

	system("pause");
	return 0;
}

//calculate the gray code k
int computeGrayInt(int m, int j)
{
	int n = m;
	int k = j;
	
	//exclusive or k with k shifted right 1 bit
	k = k ^ (k >> 1);

	return k;
}

int computeGrayPosition(int g)
{
	if (g == 0)
		return 0;
	else
	{
		int k = 0;
		int* bits;
		bits = new int[(log2(g))+1];


	}

}

//open the file given by user
void openFile(ifstream & infile, ofstream & outfile)
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