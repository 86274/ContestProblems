#include <iostream>
#include  <vector>
#include <iomanip>

using namespace std;

void search(vector<int> L, int K, int l, int r, int& answ)
{
	if (l <= r)
	{
		const int mid = (l + r) / 2;
		int sum = 0;

		for (auto i : L)
		{
			sum += i / mid;
		}

		if (sum >= K)
		{
			answ = mid;
			search(L, K, mid + 1, r, answ);
		}
		else
		{
			search(L, K, l, mid - 1, answ);
		}
	}
}

int main()
{
	int N, K, x;
	int max = 0;
	int answ = 0;
	vector<int> L;

	cin >> N >>  K;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (max < x)
		{
			max = x;
		}
		L.push_back(x);
	}

	search(L, K, 1, max, answ);

	cout << answ;
}

