/*
Joseph Williamson
Computer Science 1 - Johnson
02/22/17
Catering Service
This program creates a bill due for a catering service depending on user entered
amounts.  It also aligns using iomanip
*/


#include <iostream>
#include <iomanip> // allows use of setw and fixed precision

using namespace std;

int main()
{
	int NumAdult, NumChild;
	double AdultCost, DesCost, RoomFee, TaxRate, Deposit;

	cout << "Joseph Williamson \n";
	cout << "Computer Science 1 - Johnson \n";
	cout << "02/22/17 \n";
	cout << "Catering Service \n";
	cout << "This program creates a bill due for a catering service " <<
		"depending on user entered amounts. It also aligns using iomanip \n\n";

	// The following section asks the user for amounts of each field

	cout << "How many adults? ";
	cin >> NumAdult;
	cout << "How many children? ";
	cin >> NumChild;
	cout << "What is the cost per adult meal? ";
	cin >> AdultCost;
	cout << "What is the cost for a single dessert? ";
	cin >> DesCost;
	cout << "What is the room fee? ";
	cin >> RoomFee;
	cout << "What is the tax rate? ";
	cin >> TaxRate;
	cout << "How much is deposited? ";
	cin >> Deposit;

	cout << "\n"; // spacing

	double ChildCost = AdultCost * 0.60; // calculation for cost of child

	// The following section displays user entered amounts in $ form

	cout << "  **** Catering Service **** " << "\n\n";
	cout << fixed << setprecision(2);
	cout << "Number of adults:     " << setw(7) << NumAdult << "\n";
	cout << "Number of children    " << setw(7) << NumChild << "\n";
	cout << "Cost per adult meal:  " << "$" << setw(7) << AdultCost << "\n";
	cout << "Cost per child meal:  " << "$" << setw(7) << ChildCost << "\n";
	cout << "Cost per dessert:     " << "$" << setw(7) << DesCost << "\n";
	cout << "Room fee:             " << "$" << setw(7) << RoomFee << "\n";
	cout << "Tax rate:             " << "$" << setw(7) << TaxRate << "\n\n";

	// These are calculations for total costs

	double TotalAdult = AdultCost * NumAdult;
	double TotalChild = ChildCost * NumChild;
	double TotalDes = DesCost * (NumAdult + NumChild);
	double TotalFood = TotalAdult + TotalChild + TotalDes;
	double TotalTax = TotalFood * TaxRate;

	// The following section displays totals 

	cout << "Total for adult meals:" << "$" << setw(7) << TotalAdult << "\n";
	cout << "Total for child meals:" << "$" << setw(7) << TotalChild << "\n";
	cout << "Total for dessert:    " << "$" << setw(7) << TotalDes << "\n";
	cout << "Tax amount:           " << "$" << setw(7) << TotalTax << "\n";
	cout << "Room fee:             " << "$" << setw(7) << RoomFee << "\n\n";

	// These are calculations for the subtotal and amount due

	double SubTotal = TotalFood + TotalTax + RoomFee;
	double Balance = SubTotal - Deposit;

	// Displays the subtotal and balance due minus the deposit

	cout << "Subtotal:             " << "$" << setw(7) << SubTotal << "\n";
	cout << "Less deposit:         " << "$" << setw(7) << Deposit << "\n";
	cout << "Balance due:          " << "$" << setw(7) << Balance << "\n\n";


	system("pause");
	return 0;


}