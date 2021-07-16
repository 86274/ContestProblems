#include <iostream>
#include <vector>
#include  <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	int sum = 0;
	pair<int, int> cond;
	vector<int> classes;
	map<int, int> price;
	auto it = price.begin();

	cin >> n;
	classes.resize(n);
	for (int i = 0; i < n; i++)
		cin >> classes[i];
	sort(classes.begin(), classes.end());
	
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> cond.second;
		cin >> cond.first;
		it = price.find(cond.first);
		if (it == price.end())
		{
			price.insert(cond);
		} else if (it->second < cond.second)
		{
			it->second = cond.second;
		}	
	}

	int i = 0;
	it = price.begin();
	while (i < n)
	{
		while (it->second < classes[i])
		{
			++it;
		}
		while (i < n && it->second >= classes[i])
		{
			sum += it->first;
			++i;
		}
	}

	cout << sum;
}
