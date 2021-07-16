#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


int main()
{
	map<string, map<string, double>> people;
	pair<string, map<string, double>> fam;
	pair<string, double> products;
	auto it = people.begin();
	auto jt = fam.second.begin();

	while (cin >> fam.first)
	{
		cin >> products.first >> products.second;

		it = people.find(fam.first);
		if (it == people.end())
		{
			fam.second.insert(products);
			people.insert(fam);
		}
		else
		{
			jt = it->second.find(products.first);
			if (jt == it->second.end())
			{
				it->second.insert(products);
			}
			else
			{
				jt->second += products.second;
			}
		}
		fam.second.clear();
	}

	for (auto i : people) {
		cout << i.first << ":" << endl;
		for (auto j : i.second) {
			cout << j.first << " ";
			cout << fixed << setprecision(0) << j.second << endl;		 
		}
	}

}

