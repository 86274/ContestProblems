#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, p, key;
	vector<int> keyCount;

	cin >> n;
	keyCount.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> keyCount[i];
	}

	cin >> p;

	for (int i = 0; i < p; i++)
	{
		cin >> key;
		keyCount[key]--;
	}

	for (int i = 1; i < keyCount.size(); i++)
		if (keyCount[i] > -1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
}

