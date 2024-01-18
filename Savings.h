#pragma once
#include"Expense.h"
#include <iostream>
#include <string>
#include<fstream>
#include"struct.h"
#include"Income.h"
using namespace std;
struct naming;
class Savings {
    friend class Expense;
    float totalSavings, E;
    Income In;
public:
    Savings() { totalSavings = 0; }
    void addSavings(float t, const Income& obj, float exp) { totalSavings = t; In = obj; E = exp; }
    void calcSavings() { totalSavings = totalSavings - E; }
    void calcSavingsIncome() { totalSavings = totalSavings + In.getTotalIncome(); }
    float getSavings() { return totalSavings; }
    ~Savings() {}
};