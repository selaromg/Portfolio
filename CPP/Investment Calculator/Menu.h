#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class MainMenu {
    // creates menu display and prompt
public:
    void DisplayMenu();
};

class UserInformation {
// contains following data: init_dep_amount, mon_dep_amount, num_years, int_rate
public:
    // set/get functions for needed user info
    void setInitialDeposit(double t_deposit);
    double getInitialDeposit();
    void setMonthlyDeposit(double t_monthly);
    double getMonthlyDeposit();
    void setInterestRate(double t_interestRate);
    double getInterestRate();
    void setNumberOfYears(int t_numYears);
    int getNumberOfYears();
private:
    // amounts only changeable by class member functions in UserInformation == userinput in said functions
    double m_deposit;
    int m_monthly;
    double m_interestRate;
    int m_numYears;
};



#endif // MENU_H