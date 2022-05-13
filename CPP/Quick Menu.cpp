#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void MenuHeader() {
	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << endl;

	cout << "|" << setw(27) << "Main Menu" << setw(22) << "|" << endl;

	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << endl;
}


void MenuDisplay() {

	int usrChoice;

	MenuHeader();

	cout << "|" << "1. All items purchase info" << setw(23) << "|" << endl;
	cout << "|" << "2. Specific item purchase info" << setw(19) << "|" << endl;
	cout << "|" << "3. Histogram of sales" << setw(28) << "|" << endl;
	cout << "|" << "4. Exit" << setw(42) << "|" << endl;

	for (int i = 0; i < 50; ++i) {
		cout << '-';
	}

	cout << "\n\nEnter option (1-4): ";
	cin >> usrChoice;


	switch (usrChoice) {
	case 1:
		//all items
	case 2:
		//specific item
	case 3:
		//histogram
	case 4:
		break;
	default:
		cout << "Please enter a number 1-4 .. press enter to continue" << endl;
		cin.ignore();
		cin.ignore();
		MenuDisplay();
	}

	//option 1 list items purchased on given day
	//option 2 list number of times given object purchased on given day
	//option 3 histogram
	//option 4 exit
}

void main() {
	MenuDisplay();
}