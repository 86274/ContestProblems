#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void search(double N, double x, double y, double l, double r, double& answ)
{
	double mid = trunc((l + r) / 2);

	if (l <= r)
	{
		double res = trunc((mid - x) / x) + trunc((mid - x) / y) + (mid >= x);
		if (res >= N)
		{
			answ = mid;
			search(N, x, y, l, mid - 1, answ);
		}
		else
		{
			search(N, x, y, mid + 1, r, answ);
		}
	}
}

int main()
{
	double N, x, y, answ;
	answ = 0;

	cin >> N >> x >> y;

	if (x > y)
	{
		swap(x, y);
	}

	search(N, x, y, 1, N * x, answ);

	cout << fixed << setprecision(0) << answ;
}

