#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a = 0;
	vector<int> v;
	double max1 = -1;
	double max2 = -1;
	double min1 = 0;
	double min2 = 0;
	double max3 = -1;
	double min3 = 0;
	int x = 0;
	int y = 0;
	int z = 0;
	int minp = 0;

	while (cin >> a)
	{
		v.push_back(a);
	}

	if (v.size() == 3)
	{
		x = v[0];
		y = v[1];
		z = v[2];
	}
	else {
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] >= 0)
			{
				if (v[i] >= max1)
				{
					max3 = max2;
					max2 = max1;
					max1 = v[i];
				}
				else if (v[i] >= max2)
				{
					max3 = max2;
					max2 = v[i];
				}
				else if (v[i] >= max3)
				{
					max3 = v[i];
				}
			}
			if (v[i] < 0)
			{
				if (v[i] <= min1)
				{
					min3 = min2;
					min2 = min1;
					min1 = v[i];
				}
				else if (v[i] <= min2)
				{
					min3 = min2;
					min2 = v[i];
				}
				else if (v[i] <= min3)
				{
					min3 = v[i];
				}
			}
		}

		if (max1 == -1 && max2 == -1 && max3 == -1)
		{
			min2 = min1;
			min3 = min1;
			for (int i = 0; i < v.size(); i++)
			{
				if (min3 < v[i])
				{
					min1 = min2;
					min2 = min3;
					min3 = v[i];
				}
				else if (min2 < v[i])
				{
					min1 = min2;
					min2 = v[i];
				}
				else if (min1 < v[i])
				{
					min1 = v[i];
				}
			}
			x = min1;
			y = min2;
			z = min3;
		}
		else if (max1 * max2 * max3 >= min1 * min2 * max1 && max3 != -1)
		{
			x = max1;
			y = max2;
			z = max3;
		}
		else
		{
			x = min1;
			y = min2;
			if (max1 != -1)
				z = max1;
			else z = min3;
		}
	}

	cout << x << " " << y << " " << z;

}

