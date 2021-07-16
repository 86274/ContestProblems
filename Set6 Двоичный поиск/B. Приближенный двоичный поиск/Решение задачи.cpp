#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void search(vector<int>& first, int x, int l, int r, int p) {
	if (l <= r)
	{
		int mid = (l + r) / 2;
		if (first[mid] == x)
		{
			cout << x << endl;
		}
		else if (first[mid] > x)
		{
			if (abs(first[mid] - x) < abs(p - x))
			{
				p = first[mid];
			}
			search(first, x, l, mid - 1, p);
		}
		else
		{
			if (abs(first[mid] - x) <= abs(p - x))
			{
				p = first[mid];
			}
			search(first, x, mid + 1, r, p);
		}
	}
	else
		cout << p << endl;
}

int main()
{
	int n, k, x, p;
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

	p = first[(0 + first.size() - 1) / 2];
	for (int i = 0; i < k; i++)
	{
		search(first, second[i], 0, first.size() - 1, p);
	}
}

