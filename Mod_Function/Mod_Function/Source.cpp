/*
Joseph Williamson
Computer Science 1 - Johnson
04/17/17
Mod_Function
This program creates a function to calculate the modulus
without using the % function. Gets the base and
divisor from user, not accepting a zero for divisor
*/

#include<iostream>

using namespace std;

int mod(int base, int divisor); // funtion prototype
void heading();

int main()
{
	int base, divisor, remainder;
	char choice = 'y';

	heading();

	while (choice == 'y' || choice == 'Y')
	{
		cout << "Please enter a base and a divisor: ";
		cin >> base >> divisor;
		cout << "\n";

		while (divisor < 1) // only accepts a non-zero value for divisor
		{
			cout << "The divisor cannot be zero. "
				<< "Enter a non-zero value for divisor: ";
			cin >> divisor;
			cout << "\n";
		}

		remainder = mod(base, divisor); // function call

		cout << base << " mod " << divisor << " = " << remainder << "\n\n";

		cout << "Run again? ";
		cin >> choice;
		cout << "\n";
	}

	system("pause");
	return 0;
}

int mod(int base, int divisor) // function code getting mod without %
{
	int x, Ans = 0, Result, Great;
	
	Great = base - divisor;

	for (x = 1; Ans <= Great; x++)
		Ans = divisor * x;

	Result = base - Ans;

	return Result;
}

void heading()
{
	cout << "Joseph Williamson \n"
		<< "Computer Science 1 - Johnson \n"
		<< "04/17/17 \n"
		<< "Mod_Function \n"
		<< "This program creates a function to calculate the modulus \n"
		<< "without using the % function. Gets the base and \n"
		<< "divisor from user, not accepting a zero for divisor \n\n";
}
