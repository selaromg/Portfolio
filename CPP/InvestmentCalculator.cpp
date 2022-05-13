#include <iomanip>
#include "InvestmentCalculator.h"
#include "Menu.h"

double InvestmentCalculator::InvestmentAfterTime() {

    double initial = user1.getInitialDeposit();
    double monthly = user1.getMonthlyDeposit();
    double yearlyRate = user1.getInterestRate();
    int numYears = user1.getNumberOfYears();

    double start = initial;
    double interest;
    for (int i = 0; i < numYears; i++) {
        interest = ((start + (monthly * 12)) * (yearlyRate/100));
        start =  interest + (start + (monthly * 12));
        cout << fixed << setprecision(2) << start << " ";
    }
    
    cout << endl;
    return 0;
}

vector<double> InvestmentCalculator::YearlyReturn() {
    vector<double> returns;
    vector<double> intEarned;
    cout << fixed << setprecision(2);

    double initial = user1.getInitialDeposit();
    double monthly = user1.getMonthlyDeposit();
    double yearlyRate = user1.getInterestRate();
    int numYears = user1.getNumberOfYears();

    double start = initial;
    double interest;
    for (int i = 0; i < numYears; i++) {
        interest = ((start + (monthly * 12)) * (yearlyRate/100));
        start =  interest + (start + (monthly * 12));
        returns.push_back(start);
        intEarned.push_back(interest);
    }

    for (int i = 0; i < returns.size(); i++) {
        cout << "Year " << (i + 1)<< ": $" << returns.at(i);
        cout << "\tInterest Earned: $" << intEarned.at(i) << endl;
    }

    return returns;

}


// (initial + (monthly * 12)) yields amount deposited for the year
