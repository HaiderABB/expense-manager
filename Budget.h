#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include"struct.h"
#include"Income.h"
using namespace std;
struct naming;
class Budget : public Income {
protected:
    float amountForBudget;
public:
    Budget() { amountForBudget = totalIncome; }
    bool setBudget(float B) {
        if (B > totalIncome)
        {
            return false;
        }
        else
        {
            amountForBudget = B;
            return true;
        }
    }
    float getBudget()
    {
        return amountForBudget;
    }
    ~Budget() {}
};
