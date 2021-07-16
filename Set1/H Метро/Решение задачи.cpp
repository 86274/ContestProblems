#include <iostream>

using namespace std;

int main()
{
	int a, b, p1, p2;
	int min1 = 0;
	int min2 = 0;
	int max1 = 0;
	int max2 = 0;

	cin >> a >> b >> p1 >> p2;

	min1 = p1 + (p1 - 1) * a;
	max1 = p1 + (p1 + 1) * a;
	min2 = p2 + (p2 - 1) * b;
	max2 = p2 + (p2 + 1) * b;

	if (max1 >= min2 && max2 >= min1)
	{
		cout << (min1 > min2 ? min1 : min2);
		cout << " ";
		cout << (max1 < max2 ? max1 : max2);
	}
	else
	{
		cout << -1;
	}
}

