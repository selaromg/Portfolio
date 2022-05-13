#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Header.h"

using namespace std;


//creates 2-d vector that stores investment return after monthly deposit and interest added as well as interest on that particular sum
vector<vector<double>> calculator(double init, double monthly, double rate, int years) {
	vector<vector<double>> returns(years * 12, vector<double>(2, 0));
	double monthlyRate = (rate * 0.01) / 12;
	returns[0][0] = init;
	returns[0][1] = ((init + monthly) * monthlyRate);
	

	for (int i = 1; i < returns.size(); ++i) {

		returns[i][0] = ((returns[i - 1][0] + monthly) * monthlyRate) + returns[i - 1][0] + monthly;
		returns[i][1] = ((returns[i][0] + monthly) * monthlyRate);
	}

	return returns;
}

void MainMenu() {
	//visual formatting
	for (int i = 0; i < 52; ++i) {
		cout << '*';
	}
	cout << endl;
	for (int i = 0; i < 20; ++i) {
		cout << '*';
	}
	cout << " Data Input ";
	for (int i = 0; i < 20; ++i) {
		cout << '*';
	}
	cout << endl;

	//object construction and data input
	Investment invest;
	invest.setInitialDep();
	invest.setMonthlyDep();
	invest.setAnnualInt();
	invest.setNumYears();


	vector<vector<double>> returns = calculator(invest.getInitialDep(), invest.getMonthlyDep(), invest.getAnnualInt(), invest.getNumYears());

	cout << "Press enter to continue . . .";
	cin.ignore();
	cin.ignore();

	//visual formatting
	cout << "\n\n\n  Balance and Interest With Additional Monthly Deposits  " << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << "\n Month\t" << "\tStarting Balance\t" << "Earned Interest" << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << endl;

	//iterates through 2-d vector
	for (int i = 0; i < returns.size(); ++i) {
		cout << setprecision(2) << fixed << setw(5) << i + 1 << setw(25) << returns[i][0] << setw(25) << returns[i][1] << endl;
	}

	cout << "\nTotal Interest Earned:";

	//calculate total interest earned
	double total = 0;

	for (int i = 0; i < returns.size(); ++i) {
		total += returns[i][1];
	}

	cout << setw(33) << total << endl;

	cout << "Press Enter to continue . . .";
	cin.ignore();
	
	//formatting again
	cout << "\n\n\n  Balance and Interest Without Additional Monthly Deposits  " << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << "\n Month\t" << "\tStarting Balance\t" << "Earned Interest" << endl;
	for (int i = 0; i < 60; ++i) {
		cout << '-';
	}
	cout << endl;

	vector<vector<double>> returns2 = calculator(invest.getInitialDep(), 0, invest.getAnnualInt(), invest.getNumYears());

	for (int i = 0; i < returns2.size(); ++i) {
		cout << setprecision(2) << fixed << setw(5) << i + 1 << setw(25) << returns2[i][0] << setw(25) << returns2[i][1] << endl;
	}

	cout << "\nTotal Interest Earned:";

	total = 0;

	for (int i = 0; i < returns2.size(); ++i) {
		total += returns2[i][1];
	}

	cout << setw(33) << total << endl;


}

int main() {
	char ans;
	while (true) {
		MainMenu();
		cout << "Would you like to calculate again? (y/n)" << endl;
		cin >> ans;
		if (ans != 'y') {
			cout << "Goodbye!";
			break;
		}
	}
}