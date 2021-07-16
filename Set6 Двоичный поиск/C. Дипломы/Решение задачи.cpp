#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void search(double x, double y, double n, double l, double r, double& answ) {
	
	double mid = trunc((l + r) / 2);

	if (l <= r)
	{
		if (trunc(mid / x) * trunc(mid / y) >= n && mid >= x)
		{
			answ = mid;
			search(x, y, n, l, mid - 1, answ);
		}
		else
		{
			search(x, y, n, mid + 1, r, answ);
		}
	}

}

int main()
{
	double x, y, n, l, r;
	double q = 0;
	cin >> x >> y >> n;
	if (y > x)
	{
		swap(y, x);
	}
	l = 0;
	r = x * n;

	search(x, y, n, l, r, q);
	cout << fixed << setprecision(0) << q;
}

