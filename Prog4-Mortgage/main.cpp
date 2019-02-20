//---------------------------------------------------------------------------------------------
// Cana Hallenbeck
// Due Wednesday, February 20th - Spring 2019
// Prog II assignment 4 -- Mortgage
// Desc : { A program that (using classes) determines the monthly payment on a home mortgage.
//			class returns monthly payment amount and the total amount paid to the bank at the
//			end of the loan period; main gets user input and displays total(s) }
//---------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include "Mortgage.h"
using namespace std;
bool parseInt(string, int&);
bool parseFloat(string, float&);
int main()
{

	Mortgage MortgagePayment; // --->  (instance of mortagage class)
							  //       lets user set loan, intr. rate, and 
							  //       amnt of years; returns monthly payment
							  //	   and total payment to bank
	
	string yAns,	 // ------------>  to hold string ver. of year input for parse
		   lAns,     // ------------>  to hold string ver. of loan input for parse
		   rAns;	 // ------------>  to hold string ver. of rate input for parse
	float loan,		 // ------------>  The amount of the loan in dollars
		  rate;		 // ------------>  The annual interest rate
	int   years,	 // ------------>  Number of years involved in the loan
		  count = 0; // ------------>  amount of times through while loop;
				     //			       if > than 0, display error message

	cout << endl
		<< ":: MORTGAGE PAYMENT CALCULATOR ::\n\n";
	
	do
	{
		if (count > 0)
		{
			cout << "\n :: INVALID INPUT!"
				<< "\n    One or more of your "
				<< "\n    entries is invalid!"
				<< "\n\n--------------------------------------------\n"
				<< "\n   Remember : Years must be greater than 1"
				<< "\n   Loan amount Must be greater than 0"
				<< "\n   Interest rate must be greater than 0"
				<< "\n\n--------------------------------------------\n\n";
		}

		cout << " || Length in Years of Loan Payments : ";
		cin >> yAns;
		cout << " || Loan Amount : $ ";
		cin >> lAns;
		cout << " || Annual Interest Rate : ";
		cin >> rAns;

		count++;

	} while (!parseInt(yAns, years) || years < 1 || !parseFloat(lAns, loan) || loan < 0 || !parseFloat(rAns, rate) || rate < 0);
	
	
	MortgagePayment.setYears(years);
	MortgagePayment.setLoan(loan);
	MortgagePayment.setRate(rate);

	cout << "\n\n--------------------------------------------\n\n"
		 << fixed << showpoint << setprecision(2)
		 << " * Monthly Payments  : $ " << setw(7)
		 << MortgagePayment.getMonthlyPayment() << endl
		 << "\n * Total Amount Paid "
		 << "\n         to the Bank : $ " << setw(7)
		 << MortgagePayment.getTotalPay() 
		 << "\n\n--------------------------------------------\n\n";

	return 0;
}
bool parseInt(string ansAttmpt, int & ans)
{
	//---------------------------------------------------------------------------------------------
	//	PARSE INT - a function that accepts a string, converts to an int ( or throws an exception )
	//				 and returns a bool with true if an int, or false if not
	//	RECEIVES : ansAttmpt ( a string containing what the user input to check whether or not an 
	//			   int ), ans ( an integer passed by reference, converted from the string entered )
	//  RETURNS : valid - a bool that = true if int or false if not int
	//---------------------------------------------------------------------------------------------

	int num; // to hold converted string -> int
	bool valid = true;
	try
	{
		num = stoi(ansAttmpt);
		ans = num;
	}
	catch (const std::exception&)
	{
		valid = false;
	}

	return valid;
}
bool parseFloat(string ansAttmpt, float & ans)
{
	//---------------------------------------------------------------------------------------------
	//	PARSE FLOAT -- a function that accepts a string, converts to a float ( or throws an 
	//                 exception ) and returns a bool with true if a float, or false if not
	//	RECEIVES : ansAttmpt ( a string containing what the user input to check whether or not a 
	//			   float ), ans ( a float passed by reference, converted from the string entered )
	//  RETURNS : valid - a bool that = true if float or false if not float
	//---------------------------------------------------------------------------------------------

	float num; // to hold converted string -> float
	bool valid = true;
	try
	{
		num = stof(ansAttmpt);
		ans = num;
	}
	catch (const std::exception&)
	{
		valid = false;
	}

	return valid;
}