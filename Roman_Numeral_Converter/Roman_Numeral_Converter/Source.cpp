/*
Joseph Williamson
Computer Science 1 - Johnson
03/07/17
Roman Numeral Converter
This program takes input from the user and converts
it using switch statements.
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int Num;
	string NewNum;
	bool valid = false;

	cout << "Joseph Williamson \n" //header
		<< "Computer Science 1 - Johnson \n"
		<< "03/07/17 \n"
		<< "Roman Numeral Converter \n"
		<< "This program takes input from the user \n"
		<< "and converts it using switch statements \n\n";

	cout << "Welcome to Joseph's Roman Numeral Converter!! \n\n"; // introduction
	cout << "Please enter a number between 1 and 10. ";
	

	while (valid == 0) // starts the loop
	{
		cin >> Num;

		switch (Num)
		{
		case 1:
			NewNum = "I";
			valid = true;
			break; // exits the switch statement

		case 2:
			NewNum = "II";
			valid = true;
			break;

		case 3:
			NewNum = "III";
			valid = true;
			break;

		case 4:
			NewNum = "IV";
			valid = true;
			break;

		case 5:
			NewNum = "V";
			valid = true;
			break;

		case 6:
			NewNum = "VI";
			valid = true;
			break;

		case 7:

			NewNum = "VII";
			valid = true;
			break;

		case 8:
			NewNum = "VIII";
			valid = true;
			break;

		case 9:
			NewNum = "IX";
			valid = true;
			break;

		case 10:
			NewNum = "X";
			valid = true;
			break;

		default: // anything outside of the range and this will display
			cout << "Please try again, enter a number between 1 and 10. ";
			valid = false;
			break;
		}

	}

	cout << "\n";
	cout << "Your converted number is " << NewNum << "\n\n";

	system("pause");
	return 0;
}