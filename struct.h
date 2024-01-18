#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include"Debts.h"
#include"Income.h"
#include"Expense.h"
#include "Budget.h"
#include"Savings.h"
using namespace std;
struct naming
{
	string username;
	string curr;
	Income In;
	Debts D;
	Budget Bu;
	Savings S;
	Expense E;
};