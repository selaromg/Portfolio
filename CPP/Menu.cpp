#include "Menu.h"
#include "InvestmentCalculator.h"
#include <iomanip> // setprecision
#include <iostream>
#include <string>
using namespace std;

//creates user&investment object for entire program
UserInformation user1;
InvestmentCalculator investment;

void MainMenu::DisplayMenu() {
    double var; //var for user input
    int var1;   //month input var
    
    //opening intro w/ user prompts
    cout << "****************************************************" << endl << "\n Welcome to Airgead Banking Investment Calculator!\n";
    cout << endl << "****************************************************" << endl;


    cout << "\nEnter initial deposit amount: $";
    cin >> var;
    user1.setInitialDeposit(var);

    cout << "Enter monthly deposit amount: $";
    cin >> var;
    user1.setMonthlyDeposit(var);

    cout << "Enter interest rate: ";
    cin >> var;
    user1.setInterestRate(var);

    cout << "Enter number of years: ";
    cin >> var1;
    user1.setNumberOfYears(var1);

    cout << "Press ENTER to continue";
    cin.ignore();
    cin.ignore();
    cout << string(50, '\n');

    cout << "*****************************************************************************************";
    cout << setw(20) << "\nStarting Balance: $" << user1.getInitialDeposit();
    cout << setw(20) << "Monthly Deposit: $" << user1.getMonthlyDeposit();
    cout << setw(20) << "Interest Rate: " << user1.getInterestRate() << "%";
    cout << setw(20) << "Number of Years: " << user1.getNumberOfYears() << endl;
    cout << "*****************************************************************************************" << endl;

    investment.YearlyReturn();
}