#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void search(vector<int>& first, int x, int l, int r) {
	if (l <= r)
	{
		int mid = (l + r) / 2;
		if (first[mid] == x)
		{
			cout << "YES" << endl;
		}
		else if (first[mid] > x)
		{
			search(first, x, l, mid - 1);
		}
		else
		{
			search(first, x, mid + 1, r);
		}
	}
	else
		cout << "NO" << endl;
}

int main()
{
	int n, k, x;
	vector<int> first;
	vector<int> second;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		first.push_back(x);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> x;
		second.push_back(x);
	}

	sort(first.begin(), first.end());

	for (int i = 0; i < k; i++)
	{
		search(first, second[i], 0, first.size() - 1);
	}
}

