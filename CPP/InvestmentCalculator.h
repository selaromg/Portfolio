#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <iostream>
#include <vector>
#include "Menu.h"

using namespace std;


class InvestmentCalculator {
    public:
        double InvestmentAfterTime();
        vector<double> YearlyReturn();
        
};

#endif //INVESTMENT_CALCULATOR_H