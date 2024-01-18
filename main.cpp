#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include"struct.h"
#include"Debts.h"
#include"Income.h"
#include"Expense.h"
#include "Budget.h"
#include"Savings.h"
using namespace std;
//struct naming
//{
//	string username, curr;
//	Income In;
//	Debts D;
//	Budget Bu;
//	Savings S;
//	Expense E;
//};
void savingmajor(naming obj)
{
	ofstream write("majorinfo.txt", ios::app);
	write << obj.username << " " << obj.curr << " " << obj.In.getTotalIncome() << " " << obj.E.getExpense() << " " << obj.Bu.getBudget() << " " << obj.D.getDebt() << " " << obj.S.getSavings() << endl;
	write.close();
}
// login\signup
double loginorsignup()
{
	int options1, options2, t = 0, v = 3;
	string username, directoryusernames, directorypasswords, password;
menu:
	cout << "Press 1 to sign up\nPress 2 to login\nPress 3 to forget password" << endl;
	cin >> options1;
	while (options1 > 3 || options1 < 1)
	{
		cout << "Invalid input" << endl;
		cin >> options1;
	}
	switch (options1)
	{
	case(1):
	{


	username:

		cout << "Input username " << endl;
		cin >> username;
		ofstream write("userdata.txt", ios::app);
		ifstream read("userdata.txt");
		while (read >> directoryusernames >> directorypasswords)
		{
			if (directoryusernames == username)
			{
				t = 1;
				break;
			}
		}
		if (t == 1)
		{
			cout << "Username is already taken." << endl;
			goto username;
		}
		else
		{
			cout << "Input password" << endl;
			cin >> password;
			cout << "Registration is successfull." << endl;

			write << username << " " << password << endl;
			//nminuse = username;

		}
		write.close();
		return 1.1;
		break;

	}
	case(2):
	{
	login:

		cout << "Input username " << endl;
		cin >> username;
		cout << "Input password " << endl;
		cin >> password;
		ifstream read("userdata.txt");
		while (read >> directoryusernames >> directorypasswords)
		{
			if (directoryusernames == username && directorypasswords == password)
			{
				t = 1;
				break;
			}
			if (directoryusernames == username && directorypasswords != password)
			{
				t = 2;
				break;
			}
			if (directoryusernames != username && directorypasswords == password)
			{
				t = 3;
				break;
			}
			if (directoryusernames != username && directorypasswords != password)
			{
				t = 4;
				break;
			}
		}
		read.close();
		if (t == 1)
		{
			cout << "Login successfull" << endl;
			//nminuse = username;

			return 1.2;
		}
		else
		{
			v--;
			cout << "Login error\n" << v << "tries remain" << endl;
			if (v == 0)
			{
				cout << "Forgot Password?" << endl;
				goto sec;
			}
			{
				if (t == 2)
				{
					cout << "Incorrect Password" << endl;
					goto login;
				}
				if (t == 3)
				{
					cout << "Invalid Username" << endl;
					goto login;
				}

			}
			if (t == 4)
			{
				cout << "No such account exist\nPress 1 to goto Menu\nPress 2 to exit" << endl;
				cin >> options2;
				switch (options2)
				{
				case(1):
				{
					goto menu;
					break;
				}
				case(2):
				{
					return 2;
					break;
				}
				while (options2 > 3 || options2 < 1)
				{
					cout << "Invalid input" << endl;
					cin >> options2;
				}
				}
			}
		}
	}
	case(3):
	{
	sec:
		string ps1, ps2;;
	security:
		cout << "Forgot Password?\nInput new Password" << endl;
		cin >> ps1;
		cout << "Input password to confirm" << endl;
		cin >> ps2;
		if (ps1 != ps2)
		{
			cout << "passwords dont match\nTry again" << endl;
			goto sec;
		}
		else
		{
			ofstream write("userdata.txt", ios::app);
			ifstream read("userdata.txt");
			while (read >> directoryusernames >> directorypasswords)
			{

				if (directoryusernames == username)
				{

					write << username << " " << password << endl;
					write.close();
					goto login;
				}

			}
		}
		break;
	}
	}
}
//end of login/signup




string currency()
{
	int optio;
	cout << "Press 1 to choose pkr\nPress 2 to choose american dollars\nPress 3 to choose pound\nPress 4 to choose yuan\nPress 5 to choose euro\nPress 6 to choose dirham" << endl;
	cin >> optio;
	while (optio > 6 || optio < 1)
	{
		cout << "Invalid option.Try again" << endl;
		cin >> optio;
	}
	switch (optio)
	{
	case(1):
	{
		return(" pkr");
		break;
	}
	case(2):
	{
		return(" $");
		break;
	}
	case(3):
	{
		return(" £");
		break;
	}
	case(4):
	{
		return("¥ ");
		break;
	}
	case(5):
	{
		return(" €");
		break;
	}
	case(6):
	{
		return("dirham");
		break;
	}
	}

}

int  menu()
{
	int opt;
	cout << "Press 1 to Add income\nPress 2 to Manage Budget\nPress 3 to manage expenses\nPress 4 to split expenses\nPress 5 to check debt\nPress 6 to check savings\nPress 7 to go to notes\nPress 0 to exit" << endl;
	cin >> opt;
	while (opt > 7 || opt < 0)
	{
		cout << "Invalid option.Iput again" << endl;
		cin >> opt;
	}
	return opt;
}
int main()
{
	naming obj;
	string nm, op, line;
	int amt, opt;
	float inc, svg, exp, dbt, totexp = 0, totdbt = 0, bug=0;
	bool work = 1;
	double lgsn;
	lgsn = loginorsignup();
	if (lgsn == 2) { work = 0; }
	system("CLS");
	if (lgsn == 1.1)
	{
		obj.curr = currency();
		cout << "Input income" << endl;
		cin >> inc;
		obj.In.addIncome(inc);
		cout << "Input current savings" << endl;
		cin >> svg;
		cout << "Name amount of expenses" << endl;
		cin >> amt;
		for (int i = 0; i > amt; i++)
		{
			cout << "Name expense no." << i + 1 << endl;
			cin >> nm;
			cout << "Input amount consumed in expenses " << endl;
			cin >> exp;
			totexp += exp;
			obj.E.sve(obj.username, nm, exp);
		}

		obj.E = (totexp);
		obj.E.Expenses(totexp, obj.In, obj.S);
		obj.S.addSavings(svg, obj.In, totexp);
		cout << "Input number of Debts" << endl;
		cin >> amt;
		for (int i = 0; i < amt; i++)
		{
			cout << "Name debt no." << i + 1 << endl;
			cin >> nm;
			cout << "Input amount  " << endl;
			cin >> dbt;
			totdbt += dbt;
			obj.D.sve(obj.username, nm, dbt);
		}
		obj.D.Debtss(totdbt, obj.curr, amt);
		cout << "Input Budget" << endl;

		while (obj.Bu.setBudget(bug) == false)
		{
			cout << "Your Budget is beyond your income.Kindly input again" << endl; cin >> bug;
		}

		savingmajor(obj);
	}
	do {
	menu:
		system("CLS");
		opt = menu();
		switch (opt)
		{
		case(0):
		{
			break;
		}
		case(1):
		{
			cout << obj.In.getTotalIncome() << " is your current income\nWould you like to make changes to it?(y/n)" << endl;
			cin >> op;
			while (op != "n" && op != "N" && op != "Y" && op != "y")
			{
				cout << "Invalid input.Try again" << endl;
				cin >> op;
			}
			if (op == "y" || op == "Y")
			{
				cout << "What is your updated income?" << endl;
				cin >> inc;
				obj.In.addIncome(inc);
				cout << "Income updated" << endl;
				savingmajor(obj);
			}
			if (op == "n" || op == "N")
			{
				goto menu;
			}
			break;
		}
		case(2):
		{
			cout << obj.Bu.getBudget() << " is your current budget.Do you want to make changes?(y/n)" << endl;
			cin >> op;
			while (op != "n" && op != "N" && op != "Y" && op != "y")
			{
				cout << "Invalid input.Try again" << endl;
				cin >> op;
			}
			if (op == "y" || op == "Y")
			{
				cout << "What is your updated budget?" << endl;
				cin >> bug;
				if (obj.Bu.setBudget(bug) == false)
				{
					cout << "Your budget is beyond your income. It is better to have a budget within income limit\nInput again" << endl;
					cin >> bug;
				}
				if (obj.Bu.setBudget(bug) == true)
				{
					cout << "Budget updated" << endl;
					savingmajor(obj);

				}

			}
			if (op == "n" || op == "N")
			{
				goto menu;
			}
			break;
		}
		case(3):
		{
			string nmee = obj.username;
			cout << obj.E.getExpense() << " is your total expense a the moment which is subdivided as" << endl;
			obj.E.out(nmee);
			cout << "Do you wish to make changes?(y/n)" << endl;
			cin >> op;
			while (op != "n" && op != "N" && op != "Y" && op != "y")
			{
				cout << "Invalid input.Try again" << endl;
				cin >> op;
			}
			if (op == "y" || op == "Y")
			{
				cout << "Press 1 to add expense\nPress 2 to update current expense" << endl;
				cin >> opt;
				while (opt > 2 || opt < 1)
				{
					cout << "Invalid option.Input again" << endl;
					cin >> bug;
				}
				if (opt == 1)
				{
					cout << "Input number of new expenses" << endl;
					cin >> amt;
					for (int i = 0; i < amt; i++)
					{
						cout << "Input name of new expense number " << i + 1 << endl;
						cin >> nm;
						cout << "input expense" << endl;
						cin >> exp;
						while (obj.E.addExpense(exp) == false)
						{
							cout << "expense beyond means. It is recommended to have expenses less than income and saving\nInput again" << endl;
							cin >> exp;
						}
						obj.E.sve(obj.username, nm, exp);
						savingmajor(obj);
					}
					if (opt == 2)
					{
						 nmee = obj.username;
						obj.E.out(nmee);
						cout << "Input number of expenses to update" << endl;
						cin >> amt;
						for (int i = 0; i < amt; i++)
						{
							cout << "Input name of expense number " << i + 1 << endl;
							cin >> nm;
							obj.E.update(obj, nm);
						}
						savingmajor(obj);

					}
				}

			}
			if (op == "n" || op == "N")
			{
				goto menu;
			}
			break;
		}
		case(4):
		{
			cout << "Input number of people to split expense with" << endl;
			cin >> amt;
			cout << "Input the total expense to split " << endl;
			cin >> exp;
			exp = exp / amt;
			ifstream read("majorinfo.txt");
			for (int i = 0; i < amt; i++)
			{
			splt:
				cout << "Input username of user number " << i + 1 << endl;
				cin >> nm;
				while (getline(read, line))
				{
					if (line.find(nm) != string::npos)
					{
						obj.E.sve(nm, "Expense splitting ft" + obj.username, exp);
						obj.E.addExpense(exp);
						savingmajor(obj);
					}
					else
					{
						cout << "Invalid username.Input again" << endl;
						goto splt;
					}
				}
			}
		}
		case(5):
		{
			cout << obj.D.getDebt() << " is your current debt in " << obj.D.getCur() << ". this is subdivided into" << endl;
			obj.D.outDets(obj, obj.username);
			cout << "Do you wish to make changes?(y/n)" << endl;
			cin >> op;
			while (op != "n" && op != "N" && op != "Y" && op != "y")
			{
				cout << "Invalid input.Try again" << endl;
				cin >> op;
			}
			if (op == "y" || op == "Y")
			{
				cout << "Press 1 to add new debt\nPress 2 to update current debts" << endl;
				cin >> opt;
				while (opt > 2 || opt < 1)
				{
					cout << "Invalid option.Input again" << endl;
					cin >> bug;
				}
				if (opt == 1)
				{
					cout << "Input number of new debts" << endl;
					cin >> amt;
					for (int i = 0; i < amt; i++)
					{
						cout << "Input name of new debt number " << i + 1 << endl;
						cin >> nm;
						cout << "input the amount" << endl;
						cin >> dbt;

						obj.D.sve(obj.username, nm, dbt);
						totdbt = obj.D.getDebt();
						totdbt += dbt;
						obj.D.Debtss(totdbt, obj.curr, amt);
						savingmajor(obj);
					}
					if (opt == 2)
					{
						int count = 0;
						ifstream read("Debts.txt");
						while (read >> obj.username >> nm >> amt)
						{
							count++;
						}
						string name = obj.username;
						obj.D.outDets(obj, name);
						cout << "Input number of debts to update" << endl;
						cin >> amt;
						for (int i = 0; i < amt; i++)
						{
							cout << "Input name of debt number " << i + 1 << endl;
							cin >> nm;
							count += amt;
							string ccc = obj.curr;
							obj.D.update(ccc, nm, count );

						}
						savingmajor(obj);

					}
				}

			}
			if (op == "n" || op == "N")
			{
				goto menu;
			}
			break;

		}
		case(6):
		{
			cout << obj.S.getSavings() << " are your current savings" << endl;
			cout << "Press 1 to add saving\nPress 2 to take out savings" << endl;
			cin >> opt;
			while (opt > 2 || opt < 1)
			{
				cout << "Invalid option. Input again" << endl;
				cin >> opt;
			}
			if (opt == 1)
			{
				cout << "How much are you adding?" << endl;
				cin >> svg;
				svg += obj.S.getSavings();
				exp = obj.E.getExpense();
				obj.S.addSavings(svg, obj.In, exp);
				savingmajor(obj);
				cout << "Savings updated" << endl;
			}
			if (opt == 2)
			{
				cout << "Input amount to withdraw" << endl;
				cin >> svg;
				svg -= obj.S.getSavings();
				svg *= -1;
				exp = obj.E.getExpense();
				obj.S.addSavings(svg, obj.In, exp);
				savingmajor(obj);
				cout << "Savings updated" << endl;

			}
			break;
		}
		case(7):
		{
			string note;

			cout << "Press 1 to add notes\nPress 2 to view notes" << endl;
			cin >> opt;
			while (opt != 1 && opt != 2)
			{
				cout << "Invalid option.Try again" << endl;
				cin >> opt;
			}
			if (opt == 1)
			{
				cout << nm << "'s notes ";
				getline(cin, note);
				ofstream file(nm + "note.txt");
				file << note;
				file.close();
				cout << "Note saved!" << endl;
			}
			if (opt == 2)
			{

				ifstream file(nm + "note.txt");
				file >> note;
				cout << note;
			}
			break;
		}
		}

	} while (work == 1);
	cout << "End" << endl;
	return 0;
}
