#include "Menu.h"
#include "InvestmentCalculator.h"

using namespace std;

// UserInformation set/get function definitions
void UserInformation::setInitialDeposit(double t_deposit) {
    m_deposit = t_deposit;
}

double UserInformation::getInitialDeposit() {
    return m_deposit;
}

void UserInformation::setMonthlyDeposit(double t_monthly) {
    m_monthly = t_monthly;
}

double UserInformation::getMonthlyDeposit() {
    return m_monthly;
}

void UserInformation::setInterestRate(double t_interestRate) {
    m_interestRate = t_interestRate;
}

double UserInformation::getInterestRate() {
    return m_interestRate;
}

void UserInformation::setNumberOfYears(int t_numYears) {
    m_numYears = t_numYears;
}

int UserInformation::getNumberOfYears() {
    return m_numYears;
}
