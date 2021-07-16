#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a = 0;
    vector<int> v;
	double max1 = 0;
	double max2 = 0;
	double min1 = 0;
	double min2 = 0;
	int x = 0;
	int y = 0;
	int minp = 0;

	while (cin >> a)
	{
		v.push_back(a);
	}

	if (v.size() == 2)
	{
		x = v[0];
		y = v[1];
	}
	else {
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > 0)
			{
				if (v[i] > max1)
				{
					max2 = max1;
					max1 = v[i];
				}
				else if (v[i] > max2)
				{
					max2 = v[i];
				}
			}
			if (v[i] < 0)
			{
				if (v[i] < min1)
				{
					min2 = min1;
					min1 = v[i];
				}
				else if (v[i] < min2)
				{
					min2 = v[i];
				}
			}
		}

		if (max1 * max2 > abs(min1) * abs(min2))
		{
			x = max1;
			y = max2;
		}
		else
		{
			x = min1;
			y = min2;
		}
	}
	
	if (x > y)
	{
		cout << y << " " << x;
	}
	else
	{
		cout << x << " " << y;
	}

}

