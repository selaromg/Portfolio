/*
Gigi Morales
CS-210 Project One: Chada Tech Clocks
07/18/21
*/

#include <iostream>
#include <stdio.h>  // puts, printf
#include <iomanip>
#include <time.h>   // time_t, struct tm, time, localtime, strftime

using namespace std;

void ClearScreen() {
    cout << string(100, '\n');
}

// obtains/returns user input for menu options
int GetUserInput() {
    int userInput;
    cin >> userInput;
    return userInput;
}

void DisplayMenu() {
    char star;
    
    /*
    // creates first star line
    cout.width(30);
    star = cout.fill('*');
    
    cout << "" << endl;
    cout.fill(star);
    ended up removing because after first iteration it would fill the display with stars
    */

    cout << "******************************" << endl;

    // set up of menu options with spacing
    cout << left << "* 1 - Add One Hour";
    cout << right << setw(12) << "*" << endl;

    cout << left << "* 2 - Add One Minute";
    cout << right << setw(10) << "*" << endl;

    cout << left << "* 3 - Add One Second";
    cout << right << setw(10) << "*" << endl;

    cout << left << "* 4 - Exit Program";
    cout << right << setw(12) << "*" << endl;

    // final star line
    //cout << setw(30) << setfill('*') << "" << endl;

    cout << "******************************" << endl;

}

void AddOneHour() {
    time_t rawtime = time(0);
    struct tm *currTime = localtime(&rawtime);
    char buffer [80];

    currTime->tm_hour += 1;

    string stdTime = "*12-Hour Clock*";
    string milTime = "*24-Hour Clock*";

    cout << "**************************       **************************" << endl;
    stdTime.insert(1, 5, ' ');
    stdTime.insert(stdTime.length() - 1, 6, ' ');
    stdTime.append(7, ' ');
    milTime.insert(1, 5, ' ');
    milTime.insert(milTime.length() - 1, 6, ' ');

    cout << stdTime << milTime << endl;
    strftime (buffer, 80, "*\t%I:%M:%S %p\t *\t *\t%H:%M:%S\t  *", currTime);
    puts(buffer);
    cout << "**************************       **************************" << endl;

}

void AddOneMinute() {
    time_t rawtime = time(0);
    struct tm *currTime = localtime(&rawtime);
    char buffer [80];

    currTime->tm_min = currTime->tm_min + 1;

    
    string stdTime = "*12-Hour Clock*";
    string milTime = "*24-Hour Clock*";

    cout << "**************************       **************************" << endl;
    stdTime.insert(1, 5, ' ');
    stdTime.insert(stdTime.length() - 1, 6, ' ');
    stdTime.append(7, ' ');
    milTime.insert(1, 5, ' ');
    milTime.insert(milTime.length() - 1, 6, ' ');

    cout << stdTime << milTime << endl;
    strftime (buffer, 80, "*\t%I:%M:%S %p\t *\t *\t%H:%M:%S\t  *", currTime);
    puts(buffer);

    cout << "**************************       **************************" << endl;

}

void AddOneSecond() {
    time_t rawtime = time(0);
    struct tm *currTime = localtime(&rawtime);
    char buffer [80];

    currTime->tm_sec = currTime->tm_sec + 1;

    
    string stdTime = "*12-Hour Clock*";
    string milTime = "*24-Hour Clock*";

    cout << "**************************       **************************" << endl;
    stdTime.insert(1, 5, ' ');
    stdTime.insert(stdTime.length() - 1, 6, ' ');
    stdTime.append(7, ' ');
    milTime.insert(1, 5, ' ');
    milTime.insert(milTime.length() - 1, 6, ' ');

    cout << stdTime << milTime << endl;
    strftime (buffer, 80, "*\t%I:%M:%S %p\t *\t *\t%H:%M:%S\t  *", currTime);
    puts(buffer);

    cout << "**************************       **************************" << endl;
}

/* original time display function..combined into DisplayTime()
void TimeDisplay() {
    
    // time display
    time_t now = time(0);
    tm *ptr = localtime(&now);
    cout << ptr->tm_hour << ":" << ptr->tm_min << ":" << ptr->tm_sec << endl;
    
//this took a long time to figure out...but displays both 12hr and 24hr local time
   time_t rawtime;
   struct tm *timeinfo;
   char buffer [80];
   time (&rawtime);
   timeinfo = localtime (&rawtime);
   strftime (buffer, 80, "*\t%I:%M:%S %p\t *\t *\t%H:%M:%S\t  *", timeinfo);
   puts(buffer);
}
*/

void DisplayTime() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer [80];


    string stdTime = "*12-Hour Clock*";
    string milTime = "*24-Hour Clock*";

    cout << "**************************       **************************" << endl;

// spacing
    stdTime.insert(1, 5, ' ');
    stdTime.insert(stdTime.length() - 1, 6, ' ');
    stdTime.append(7, ' ');
    milTime.insert(1, 5, ' ');
    milTime.insert(milTime.length() - 1, 6, ' ');

    cout << stdTime << milTime << endl;

//displays current time in both 12hr and 24hr formats
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 80, "*\t%I:%M:%S %p\t *\t *\t%H:%M:%S\t  *", timeinfo);
    puts(buffer);
    cout << "**************************       **************************" << endl;
}



// main menu function -- controls most of program..only call in main
void Menu() {
    ClearScreen();
    DisplayTime();
    cout << "\n\n\t\tPress enter to continue" << endl;
    cin.ignore();
    ClearScreen();
    DisplayMenu();
    switch(GetUserInput()) {
        case 1:
            ClearScreen();
            AddOneHour();
            cout << "\n\n\t\tPress enter to continue" << endl;
            cin.ignore();
            cin.ignore();
            Menu();
            break;
        case 2:
            ClearScreen();
            AddOneMinute();
            cout << "\n\n\t\tPress enter to continue" << endl;
            cin.ignore();
            cin.ignore();
            Menu();
            break;
        case 3:
            ClearScreen();
            AddOneSecond();
            cout << "\n\n\t\tPress enter to continue" << endl;
            cin.ignore();
            cin.ignore();
            Menu();
            break;
        case 4:
            cout << "Ending program" << endl;
            return;
        default:
            cout << "Invalid entry, press enter to try again (1-4)." << endl;
            cin.ignore();
            cin.ignore();
            ClearScreen();
            Menu();
    }
    
}

int main () {
    
    Menu();
    
}
