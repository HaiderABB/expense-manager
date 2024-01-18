#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include"struct.h"
using namespace std;
struct naming;

class Income {
protected:
    float totalIncome;
public:
    Income() { totalIncome = 0; }
    void addIncome(float totalIncome) { this->totalIncome = totalIncome; }
    float getTotalIncome() { return totalIncome; }
    ~Income() {}
};