#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
	int x;
	unordered_set<int> s;
	vector<int> answ;

	while (cin >> x)
	{
		if (s.contains(x))
		{
			answ.push_back(x);
		}
		else
			s.insert(x);
	}

	sort(answ.begin(), answ.end());

	for (auto i : answ)
		cout << i << " ";
}

