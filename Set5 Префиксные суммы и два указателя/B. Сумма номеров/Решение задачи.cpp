#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	int x = 0;
	int sum = 0;
	vector<int> arr;
	int sets = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr.push_back(x);
	}

	int i = 0;
	int j = 0;

	while (j < n)
	{
		sum = sum + arr[j];
		if (sum == k)
		{
			sets++;
			sum = sum - arr[i];
			i++;
			j++;
		}
		else if (sum > k)
		{
			while (sum > k)
			{
				sum = sum - arr[i];
				i++;
			}
			if (sum == k)
			{
				sets++;
				sum = sum - arr[i];
				i++;
				j++;
			}
			else
			{
				if (sum < k)
				{
					j++;
				}
			}
		}
		else
		{
			j++;
		}
	}

	cout << sets;
}

