/*
Joseph Williamson
2433-Stringfellow
Program 3 11/14/18
Purpose of this program is to calculate the 
LCM(least common multiple) and 
	GCD(greatest common divisor)
*/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

//prototype to open files
void openFiles(ifstream &infile, ofstream &outfile);
//prototype to close files
void closeFiles(ifstream &infile, ofstream &outfile);
//prototype to find GCD
int GCD(int x, int y);
//prototype to find LCM
int LCM(int x, int y);
//prototype to display heading
void Header(ofstream &outfile, int N);
//prototype to get N test cases
void getN(int &N, ifstream &infile);

int main()
{
	//file names
	ifstream infile;
	ofstream outfile;

	int * tests; //dynamic array for test cases
	int N = 0; //test cases

	//call to get files from user
	openFiles(infile, outfile);

	//call to get N test cases
	getN(N, infile);

	tests = new int[N];//sets to size N

	//header call
	Header(outfile, N);


	//call to close files
	closeFiles(infile, outfile);

	system("pause");
	return 0;
}

//function to print header
void Header(ofstream & outfile, int N)
{
	outfile << "Joseph Williamson \n\n";
	outfile << "Maximum GCD and the minimum LCM Program \n";
	outfile << N << " test cases \n\n";
	outfile << "maxGCD" << setw(20) << "minLCM \n";
}

//function to open files
void openFiles(ifstream &infile, ofstream &outfile)
{
	//names for files
	char inFileName[40];
	char outFileName[40];

	//get infile name from user and open it
	cout << "Enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);

	//get outfile name from user and open it
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

//find the greatest divisor
int GCD(int x, int y)
{
	if (x == 0)
		return y;
	return GCD(y % x, x);
}

//find least common multiple
int LCM(int x, int y)
{

}

//function to get test cases
void getN(int &N, ifstream &infile)
{
	//recieves number of test cases
	infile >> N;
}

//function to close files
void closeFiles(ifstream &infile, ofstream &outfile)
{
	//closes infile
	infile.close();
	//closes outfile
	outfile.close();
}