#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"struct.h"
#include"Income.h"
#include "Savings.h"
using namespace std;
struct naming;
class Expense
{
    friend class Savings;
    float totalExpense;
    Income In;
    Savings S;
    string username;
    string nam, line;
    float amt, amount;
public:
    Expense() { totalExpense = 0; }
    Expense(float exp) { totalExpense = exp; }
    void Expenses(float exp) { totalExpense = exp; }
    void Expenses(float t, const Income& obj, const Savings& temp) { In = obj; totalExpense = t; S = temp; }
    void sve(string username, string nm, float amt)
    {
        ofstream write("Expense.txt", ios::app);
        write << username << ": " << nm << " " << amt << endl;
        write.close();
    }
    void out(string n)
    {
        ifstream read("Expense.txt");
        while (read >> username >> nam >> amt)
        {
            if (n == username)
            {
                cout << username << ": " << nam << amt << endl;
            }
        }
    }
    void update(naming& obj, string nm)
    {
        struct naming;

        ifstream read("Expense.txt");
        ofstream write("Expense.txt", ios::app);
        while (read >> username >> nam >> amt)
        {
            if (nam == nm)
            {
                while (getline(read, line))
                {
                    string amountStr;
                    stringstream ss(line);
                    string token;
                    while (getline(ss, token, '>')) {}
                    getline(ss, amountStr);
                    amount = stof(amountStr);
                    break;
                }
                amt = getExpense();
                amt -= amount;
                Expenses(amt);

                cout << "Input updated expense" << endl;
                cin >> amt;
                write << username << ": " << nm << " " << amt << endl;
                write.close();
                cout << "Expense updated" << endl;

                addExpense(amt);
            }
        }
    }
    bool addExpense(float E)
    {
        if (E > In.getTotalIncome())
        {
            return false;
        }
        if (E > S.getSavings())
        {
            return false;
        }
        else
        {
            totalExpense = E + totalExpense;
            return true;
        }
    }
    float getExpense() { return totalExpense; }

    ~Expense() {}
};
