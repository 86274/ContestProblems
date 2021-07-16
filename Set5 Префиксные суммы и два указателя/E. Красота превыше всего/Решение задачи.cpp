#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	pair<int, int> min = { 0 , 250001 };
	vector<int> var;
	vector<int> segment;
	int counter = 0;
	cin >> n >> k;
	var.resize(k + 1);
	segment.resize(n);
	for (int i = 0; i < n; i++)
		cin >> segment[i];

	int i = 0;
	int j = 0;

	while (j < n && i < n)
	{
		var[segment[j]]++;
		if (var[segment[j]] == 1)
		{
			counter++;
		}

		while (counter == k)
		{
			if (min.second - min.first > j - i)
			{
				min.first = i + 1;
				min.second = j + 1;
			}
			var[segment[i]]--;
			if (var[segment[i]] == 0)
			{
				counter--;
			}
			i++;
		}

		j++;
	}

	cout << min.first << " " << min.second;
}
