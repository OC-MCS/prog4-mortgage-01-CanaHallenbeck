#pragma once
#include <cmath>

//--------------------------------------------------------------------
//									  ^ 12 x YEARS
//				     /	     RATE     \ 
//		    TERM =  (  1  +  -----     )
//					 \  	  12	  /			
//
//--------------------------------------------------------------------
//						      RATE
//					 LOAN  x  ----  x  TERM
// 		 PAYMENT =   	       12
//					 -----------------------
//			 	             TERM - 1
//--------------------------------------------------------------------

class Mortgage
{
private:

	int    years;	 // the length of the loan in years
	double loan,     // the amount of the loan in dollars
		   rate;	 // annual interest rate
	double getTerm() { return pow((1 + rate / 12), (12 * years)); }

public:

	Mortgage();
	void setLoan(double);
	void setRate(double);
	void setYears(int);
	//double getLoan();
	//double getRate();
	//double getYears();
	double getMonthlyPayment()	{ return (loan * rate / 12 * getTerm() ) / (getTerm() - 1); } 
	double getTotalPay()		{ return years * getMonthlyPayment() * 12; } // (12 months in a year) * number of years
};