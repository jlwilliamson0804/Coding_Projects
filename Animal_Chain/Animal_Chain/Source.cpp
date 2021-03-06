/*
Joseph Williamson
Computer Science 1 - Johnson
05/04/17
This program creates 2 arrays using two text files, 
and determines if an animal eats another. Then prints the results.
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

const int SIZE = 7;

void heading(); // prototypes
void getAnimals(string a[SIZE]);
void getMatrix(int m[SIZE][SIZE]);
void printReport(string a[SIZE], int m[SIZE][SIZE]);

int main()
{
	heading();
	string animal[SIZE];
	int matrix[SIZE][SIZE];
	getAnimals(animal);
	getMatrix(matrix);
	printReport(animal, matrix);

	system("pause");
	return 0;
}

void heading() // heading function
{
	cout << "Joseph Williamson \n"
		<< "computer science 1 - Johnson \n"
		<< "05/04/17 \n"
		<< "This program creates 2 arrays using two text files, and determines \n"
		<< "if an animal eats another. Then prints the results \n\n";
}

void getAnimals(string a[SIZE]) // function to put animal names in a string array
{
	ifstream infile;
	infile.open("animals.txt");
	string animal;

	if (!infile) // checks to see if infile could open
	{
		cerr << "Error: The infile did not open. \n";
		system("pause");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		infile >> a[i];
	}
}

void getMatrix(int m[SIZE][SIZE]) // function to fill 2d array with int
{
	ifstream infile;
	infile.open("matrix.txt");
	string matrix;

	if (!infile) // checks to see if infile could open
	{
		cerr << "Error: The infile did not open. \n";
		system("pause");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			infile >> m[i][j];
		}
	}
}

void printReport(string a[SIZE], int m[SIZE][SIZE]) // uses both arrays to print results
{
	ifstream infile;
	infile.open("animals.txt");
	infile.open("matrix.txt");
	string animal;
	string matrix;

	for (int i = 0; i < SIZE; i++)
	{
		int sum = 0;

		for (int j = 0; j < SIZE; j++)
		{
			sum += m[i][j];
		}
		cout << "The " << a[i] << " eats " << sum << " animals " << "\n";
	}
}