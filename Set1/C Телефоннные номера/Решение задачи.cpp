#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int k = 0;
	char buf[12];
	buf[11] = '\0';
	string addVasya = {};
	string phonebook[3];
	int answ[3] = { 1, 1, 1 };

	cin >> addVasya;
	for (auto& i : phonebook)
		cin >> i;

	for (auto& i : addVasya)
	{
		if (i != '+' && i != '-' && i != '(' && i != ')')
		{
			buf[k] = i;
			k++;
		}
	}
	if (k == 7) {
		addVasya = "8495";
		addVasya += buf;
	}
	else
		addVasya = buf;
	memset(buf, '\n', 11);
	k = 0;

	for (int i = 0; i < 3; i++)
	{
		for (auto& j : phonebook[i])
			if (j != '+' && j != '-' && j != '(' && j != ')')
			{
				buf[k] = j;
				k++;
			}
		if (k != 7)
			for (int j = 1; j < 11; j++)
			{
				if (addVasya[j] != buf[j])
				{
					answ[i] = 0;
					j = 11;
				}
			}
		else
		{
			string bufs = "8495";
			bufs += buf;
			for (int j = 1; j < 11; j++)
			{
				if (addVasya[j] != bufs[j])
				{
					answ[i] = 0;
					j = 11;
				}
			}
		}
		memset(buf, '\n', 11);
		k = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		if (answ[i] == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}