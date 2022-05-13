#include "UserInformation.cpp"
#include "Menu.cpp"
#include <windows.h>
#include <iostream>
#include <string>
using namespace std;





int main() {
    MainMenu menu1;
    bool cont = true;
    
    while (cont) {
        menu1.DisplayMenu();
        string ans;

        cout << "\n\nWould you like to recalculate (Y/N)? ";
        cin >> ans;
        if (ans != "y" && ans != "Y") {
            cout << "\nThank you for using the Airgead Banking Invesment Calculator!";
            cont = false;
        } else {
            cout << string(50, '\n');
        }
    };
    return 0;
}
