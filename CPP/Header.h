#include <iostream>
#include <iomanip>

using namespace std;

class Investment {
public:
	//default constructor
	Investment();

	//mutators
	void setInitialDep() {
		cout << "Initial Investment Amount: $";
		cin >> initialInvestment;
	}
	double getInitialDep() {
		return initialInvestment;
	}
	void setMonthlyDep() {
		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;
	}
	double getMonthlyDep() {
		return monthlyDeposit;
	}
	void setAnnualInt() {
		cout << "Annual Interest: %";
		cin >> annualInterest;
	}
	double getAnnualInt() {
		return annualInterest;
	}
	void setNumYears() {
		cout << "Number of years: ";
		cin >> numYears;
	}
	int getNumYears() {
		return numYears;
	}
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
};

//default constructor declaration
Investment::Investment() {
	initialInvestment = 0;
	monthlyDeposit = 0;
	annualInterest = 0;
	numYears = 0;
}
