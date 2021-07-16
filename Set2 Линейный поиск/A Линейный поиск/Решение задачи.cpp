#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	string answ = "YES";
	int count = 0;

	while (cin >> count)
	{
		v.push_back(count);
	}

	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] >= v[i + 1])
		{
			answ = "NO";
		}
	}
	cout << answ;
}