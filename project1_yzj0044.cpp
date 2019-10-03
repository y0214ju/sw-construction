/*************************************************************
project1_yzj0044.cpp
@author YEONSEO JU (yzj0044)
@version 09052019
This program helps to find out how many months to pay off loan printing out table 
In order to write this code I referred Dr.Li's guideline printout
*************************************************************/

#include <iostream>

using namespace std;

int main()
{

   double loan;
   double interestRate;
   double interestRateC;
   double interestTotal = 0;
   double monthlyPaid;
   double balance;
   double balanceC;
   double interest;
   double principal;
   int currentMonth = 0;
      
  //CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   //USER INPUT
   cout << "\nLoan Amount: ";
   cin >> loan;
   
   while (loan <= 0) {
      cout << "enter positive loan value again\n";
      cin >> loan;
   }
   
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   
   while (interestRate <= 0) {
      cout << "enter postivie interest rate value again \n";
      cin >> interestRate;
   }
   
   //GET PROPER INTEREST RATES FOR CALCULATIONS
   interestRate /= 12;
   interestRateC = interestRate / 100;
   cout << "Monthly Payments: ";
   cin >> monthlyPaid;
   
   while (monthlyPaid <= 0| monthlyPaid > loan| monthlyPaid < loan * interestRateC) {
      cout << "enter valid monthly payment again\n";
      cin >> monthlyPaid;
   }
  
   cout << endl;
   
   // AMORTIZATION TABLE
   cout << "*************************************************************************\n"
      << "\tAmortization Table\n"
      << "*************************************************************************\n"
      << "Month\tBalance\t\tPayment\t\tRate\tInterest\tPrincipal\n";
   
   balance = loan;   
   while (balance > 0) {
      if (currentMonth == 0) {
         cout << currentMonth++ << "\t$" << loan;
         cout << "\tN/A\t\tN/A\tN/A\t\tN/A";
      }
      else {
       
         interest = interestRateC * balance;
         principal = monthlyPaid - interest;
         interestTotal = interestTotal + interest;
      
         if(balance * (1 + interestRateC) >= monthlyPaid) {
            balance = balance - principal;
         
            if (balance < 1000) {// to align columns 
               cout << "\n" << currentMonth++ << "\t$" << balance;
               cout << "\t\t$" << monthlyPaid << "\t\t" << interestRate;
               cout << "\t$" << interest << "\t\t$" << principal;
            }
            else{
               cout << "\n" << currentMonth++ << "\t$" << balance;
               cout << "\t$" << monthlyPaid << "\t\t" << interestRate;
               cout << "\t$" << interest << "\t\t$" << principal;
            }
         }
         
         else {
            balanceC = balance;
            balance = balance - principal;
            monthlyPaid = balanceC + interest;
         
            cout << "\n" << currentMonth++ << "\t$0.00";
            cout << "\t\t$" << monthlyPaid << "\t\t" << interestRate;
            cout << "\t$" << interest << "\t\t$" << balanceC; 
         }
      }
   }
   
   cout << "\n************************************************************************\n";
   cout << "\nIt takes " << --currentMonth << " months to pay off "
         << "the loan.\n"
         << "Total interest paid is: $" << interestTotal;
   cout << endl << endl;
   
   return 0;
}
