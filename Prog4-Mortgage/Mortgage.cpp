#include "Mortgage.h"

Mortgage::Mortgage()
{
	setLoan(0.0);
	setRate(0.0);
	setYears(0);
}
void Mortgage::setLoan(double l)
{
	loan = l;
}

void Mortgage::setRate(double r)
{
	rate = r;
}

void Mortgage::setYears(int y)
{
	years = y;
}

//--------------------------
// for testing user input
//--------------------------

//double Mortgage::getLoan() 
//{
//	return loan;
//}
//
//double Mortgage::getRate()
//{
//	return rate;
//}
//
//double Mortgage::getYears()
//{
//	return years;
//}
