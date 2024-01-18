#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include"struct.h"

using namespace std;
struct naming;
class Debts
{
private:
    float amnt, amt, amount;// income in account
    string curr;// symbol of currency
    int nmDets;
    string username, nm, line;


public:
    Debts() { amnt = 0; }
    void  Debtss(float amnt, string curr, int nmDets)
    {
        this->amnt = amnt;
        this->curr = curr;
        this->nmDets = nmDets;
    }

    void adddebt(float amt)
    {
        amnt += amt;
    }
    float getDebt() const
    {
        return amnt;
    }
    string getCur()const
    {
        return curr;
    }
    int getamtdets()const
    {
        return nmDets;
    }
    ~Debts()
    {
    }

    void outDets(naming& obj, string usename)
    {
        ifstream read("Debts.txt");  //just in case if debts are in a file
        while (read >> username >> nm >> amt)
        {
            if (username == usename)
            {
                cout << username << ": " << nm << " " << amt << endl;
            }
        }
    }
    void sve(string username, string nm, float amt)
    {
        ofstream write("Debts.txt", ios::app);
        write << username << ": " << nm << " " << amt << endl;
        write.close();
    }
    void update(string ccc, string nme, int num)
    {
        ifstream read("Debts.txt");
        ofstream write("Debts.txt", ios::app);
        while (read >> username >> nm >> amt)
        {
            if (nm == nme)
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
                amt = getDebt();
                amt -= amount;
                Debtss(amt, ccc, num);
                cout << "Input updated debt" << endl;
                cin >> amt;
                write << username << ": " << nme << " " << amt << endl;
                write.close();
                cout << "Debt updated" << endl;
                amt += getDebt();
                Debtss(amt, ccc, num);

            }
        }
    }
};