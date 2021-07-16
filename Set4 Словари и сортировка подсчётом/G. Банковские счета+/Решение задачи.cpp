#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class client
{
public:
	client();
	~client();

	void deposit(double);
	void withdraw(double);
	void income(double);
	double getBalance();
	void setBalance();

private:
	double sum;

};

client::client()
{
	sum = 0;
}

client::~client()
{
}

void client::deposit(double x)
{
	sum += x;
}

void client::withdraw(double x)
{
	sum -= x;
}

void client::income(double p)
{
	if (sum > 0)
	{
		sum += trunc(sum * (p / 100));
	}
	
}

double client::getBalance()
{
	return sum;
}

void client::setBalance()
{
	sum = 0;
}

void deposit(unordered_map<string, client>& bank, pair<string, client>& fam, double sum) {
	auto it = bank.find(fam.first);
	if (it == bank.end())
	{
		fam.second.deposit(sum);
		bank.insert(fam);
		fam.second.setBalance();
	}
	else
	{
		it->second.deposit(sum);
	}
}

void withdraw(unordered_map<string, client>& bank, pair<string, client>& fam, double sum) {
	auto it = bank.find(fam.first);
	if (it == bank.end())
	{
		fam.second.withdraw(sum);
		bank.insert(fam);
		fam.second.setBalance();
	}
	else
	{
		it->second.withdraw(sum);
	}
}

void balance(unordered_map<string, client>& bank, string& fam) {
	auto it = bank.find(fam);
	if (it == bank.end())
	{
		cout << "ERROR\n";
	}
	else
	{
		cout << fixed << setprecision(0) << it->second.getBalance() << endl;
	}
}

void transfer(unordered_map<string, client>& bank, pair<string, client>& fam) {
	double sum;
	string name;
	cin >> fam.first >> name >> sum;
	
	withdraw(bank, fam, sum);
	fam.first = name;
	deposit(bank, fam, sum);
}

void income(unordered_map<string, client>& bank) {
	double p;
	cin >> p;

	for (auto& i : bank) {
		i.second.income(p);
	}
}

int main()
{
	double sum;
	string name;
	string func;
	unordered_map<string, client> bank;
	pair<string, client> fam;

	while (cin >> func)
	{
		
		if (func == "DEPOSIT")
		{
			cin >> fam.first;
			cin >> sum;
			deposit(bank, fam, sum);
		}
		else if (func == "WITHDRAW")
		{
			cin >> fam.first;
			cin >> sum;
			withdraw(bank, fam, sum);
		}
		else if (func == "BALANCE")
		{
			cin >> name;
			balance(bank, name);
		}
		else if (func == "TRANSFER")
		{
			transfer(bank, fam);
		}
		else if (func == "INCOME")
		{
			income(bank);
		}
	}
}

