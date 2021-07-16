#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	int x = 0;
	int min = 0;
	vector<int> shirtColor;
	vector<int> pantsColor;
	pair<int, int> answ = { 0, 0 };

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		shirtColor.push_back(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		pantsColor.push_back(x);
	}

	if (shirtColor[n - 1] <= pantsColor[0])
	{
		answ.first = shirtColor[n - 1];
		answ.second = pantsColor[0];
	}
	else if (shirtColor[0] >= pantsColor[m - 1])
	{
		answ.first = shirtColor[0];
		answ.second = pantsColor[m - 1];
	}
	else
	{
		min = abs(shirtColor[0] - pantsColor[0]);
		answ.first = shirtColor[0];
		answ.second = pantsColor[0];
		int i = 0, j = 0;
		while (i < n && j < m)
		{
			if (shirtColor[i] == pantsColor[j])
			{
				answ.first = shirtColor[i];
				answ.second = pantsColor[j];
				i = n;
			}
			else if (shirtColor[i] < pantsColor[j])
			{
				if (abs(shirtColor[i] - pantsColor[j]) < min)
				{
					answ.first = shirtColor[i];
					answ.second = pantsColor[j];
					min = abs(shirtColor[i] - pantsColor[j]);
				}
				i++;
			}
			else
			{
				if (abs(shirtColor[i] - pantsColor[j]) < min)
				{
					answ.first = shirtColor[i];
					answ.second = pantsColor[j];
					min = abs(shirtColor[i] - pantsColor[j]);
				}
				j++;
			}
		}
	}

	cout << answ.first << " " << answ.second;

}

