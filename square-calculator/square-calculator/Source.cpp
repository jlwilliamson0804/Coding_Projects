/*
Joseph Williamson
2433-Stringfellow
Program 2 10/15/18
Purpose is to calculate the number
	of square 3 ways
*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

//prototype to open both files
void openFiles(ifstream & infile, ofstream & outfile);
//prototype to solve iteratively
int iterative(int n);
//prototype to solve with recursion
int recursive(int n);
//prototype to solve with closed form
int closedForm(int n);

int main()
{
	//file names
	ifstream infile;
	ofstream outfile;

	int N = 0; //size of square
	

	openFiles(infile, outfile); // call to get files from user

	//display of heading and top line of chart
	outfile << "Joseph Williamson \n\n";
	outfile << "N" << setw(15) << "Iterative" << setw(15)
		<< "Recursive" << setw(15) << "ClosedF" << endl;

	// recieves first value of N
	infile >> N;

	//loop to receive all values of N
	while (!infile.eof())
	{
		//call and display number of squares from each solution
		outfile << N << setw(15) << iterative(N) << setw(15) << recursive(N)
			<< setw(15) << closedForm(N) << endl;
		infile >> N; // update N
	}

	return 0;
}

/*
	Purpose: open input and output file
	Receives: fstreams by reference
	Returns: void
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
Purpose: calculate iteratively
Receives: n the number of squares
Returns: int answer
*/
int iterative(int n)
{
	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		answer += (i*i);
	}

	return answer;
}

/*
Purpose: calculate recursively
Receives: n the number of squares
Returns: int answer
*/
int recursive(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return n*n + recursive(n - 1);
}

/*
Purpose: calculate closed form
Receives: n the number of squares
Returns: int answer
*/
int closedForm(int n)
{
	int ans = 0;
	int count = 1;

	while (count <= n)
	{
		ans += count*count;
		count++;
	}
	return ans;
}