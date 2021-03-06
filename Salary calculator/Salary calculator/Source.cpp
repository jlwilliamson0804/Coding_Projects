/*
Joseph Williamson
Computer Science 1-Johnson
03/27/17
This program calculates the salary, starting at $0.01 and doubling
everyday, depending on the amount of days worked. Creates a table
showing each day then the total.
*/

#include<iostream>
#include<iomanip> // allows use of setw()

using namespace std;

int main()
{
	int Days, x;
	double Pay = 0.01, Sum = 0.0;

	cout << "Joseph Williamson \n" // header
		<< "Computer Science 1 - Johnson \n"
		<< "03/27/17 \n"
		<< "This program calculates the salary, starting at $0.01 \n"
		<< "and doubling everyday, depending on the amount of \n"
		<< "days worked. Creates a table showing each day then a total \n\n";

	cout << "Enter the number of days worked: ";
	cin >> Days;
	cout << "\n";

	while (Days < 1) // loop doesn't accept days worked less than 1
	{
		cout << "Please enter a real amount of days worked!" << "\n";
		cin >> Days;
	}

	cout << setw(6) << "Day" << setw(19) << "Pay" << "\n";
	cout << "-----------------------------------" << "\n";

	for (x = 1; x <= Days; x++) // loop creating table from user entered number of Days
	{
		cout << fixed << setprecision(2);
		cout << setw(5) << x << setw(22) << Pay << "\n";
		Sum += Pay; // accumulator
		Pay = Pay * 2;
	}

	cout << "\n";
	cout << setw(7) << "TOTAL" << setw(9) << "$" << setw(10) << Sum << "\n\n";

	system("pause");
	return 0;
}