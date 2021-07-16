#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void search(long int n, long int m, long int t, long int l, long int r, long int& answ)
{
	long int mid = (l + r) / 2;

	if (l <= r)
	{
		long int res;
		if (n % 2 == 0 && l >= n / 2  || l > n / 2 && n % 2 != 0)
		{
			res = n * m;
		}
		else
		{
			res = n * m - (n - 2 * mid) * (m - 2 * mid);
		}
		
		if (res < t)
		{
			answ = mid;
			search(n, m, t, mid + 1, r, answ);
		}
		else if(res > t)
		{
			search(n, m, t, l, mid - 1, answ);
		}
		else
		{
			if (mid % 2 == 0 && mid >= n / 2 || mid > n / 2 && mid % 2 != 0)
			{
				answ = n;
			}
			else
			{
				answ = mid;
			}
		}
	}
}

int main()
{
	long int n, m, t, answ, lvl;
	answ = 0;

	cin >> n >> m >> t;

	if (n > m)
	{
		swap(n, m);
	}
	if (n % 2 == 1)
	{
		lvl = n / 2 + 1;
	}
	else
	{
		lvl = n / 2;
	}

	search(n, m, t, 1  , lvl, answ);

	cout << answ;
}

