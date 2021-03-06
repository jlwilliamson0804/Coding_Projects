// Joseph Williamson
// Computer Science 1 - Johnson
// 2/6/17
// Ticket Sales Project
// This program displays that tickets to the Foreigner concert is going on sale, and asks the user for
// input on the amount of tickets wanted. Then gives a receipt for the cost.

#include <iostream>
#include <iomanip> // allows use of setprecision
using namespace std;

const double Premium = 99.00;
const double P2 = 79.00;
const double P3 = 59.00;
const double CFee = 6.50;

int main()
{
	double Seats1, Seats2, Seats3;

	cout << "Joseph Williamson" << "\n";
	cout << "Computer Science 1 - Johnson" << "\n";
	cout << "2/6/17" << "\n";
	cout << "Ticket Sales Project" << "\n";
	cout << "This program displays that tickets to the Foreigner concert " << 
		"is going on sale, " <<
		"and asks the user for input on the amount of tickets wanted." << 
		" Then gives a receipt for the cost" << "\n\n";

	cout << "Tickets to the Foreigner on February 7, 2017 at Memorial Auditorium in Wichita " <<
		"Falls are now available." << "\n";
	cout << "The online ticket prices are as follows : " << "\n\n";

	cout << "$99.00 Premium" << "\n"; // displays price of premium
	cout << "$79.00 P2" << "\n"; // displays price of P2
	cout << "$59.00 P3" << "\n"; // displays price of P3
	cout << "+$6.50 convenience fee per ticket purchased" << "\n\n"; // displays fee per ticket

	cout << "How many Premium seats would you like?" << "\n"; // asks user for number of Premium seats desired
	cin >> Seats1;
	cout << "How many P2 seats would you like?" << "\n"; // asks user for number of P2 seats desired
	cin >> Seats2;
	cout << "How many P3 seats would you like?" << "\n"; // asks user for number of P3 seats desired
	cin >> Seats3;
	cout << "\n"; // used to space one line

	double Pr_Seats = Premium * Seats1; // calculates cost for Premium seats
	double P2_Seats = P2 * Seats2; // calculates cost for P2 seats
	double P3_Seats = P3 * Seats3; // calculates cost for P3 seats
	double sum = Seats1 + Seats2 + Seats3; // calculates the sum of all seats wanted
	double subtotal = Pr_Seats + P2_Seats + P3_Seats; // calculates subtotal cost for all seats
	double confee = CFee * sum; // calculates convienence fee for the number of seats wanted
	double total = subtotal + confee; // calculates subtotal + convienence fee

	cout << fixed << setprecision(2); // include 2 places after the decimal
	cout << "Your subtotal is:   $" << setw(7) << subtotal << "\n"; // displays the subtotal
	cout << "Convenience Fee is:   $" << setw(7) << confee << "\n"; // displays the total convience fee
	cout << "Your total cost is: $" << setw(7) << total << "\n\n"; // displays the total cost
	
	cout << "Thank you for your purchase!" << "\n";


	system("pause");
	return 0;
}