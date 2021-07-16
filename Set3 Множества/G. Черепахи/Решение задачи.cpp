#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	int k = 0;
	int N = 0;
	int x = 0;
	int y = 0;
	vector<bool> v;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (x > -1 && y > -1)
		{
			if (N - x == 1 + y)
			{
				if (v[0 + y] != 1)
				{
					v[0 + y] = 1;
					k++;
				}
			}
		}
	}

	cout << k;

}

