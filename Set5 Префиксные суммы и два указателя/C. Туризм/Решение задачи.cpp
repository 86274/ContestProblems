#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, s, f;
	int y = 0;
	int max = 0;
	int min = 0;
	vector<int> mountainRange;
	vector<int> postfix;
	postfix.push_back(0);
	vector<int> sum;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y >> y;
		mountainRange.push_back(y);
	}

	for (int i = 1; i < n; i++)
	{
		if (mountainRange[i] - mountainRange[i - 1] > 0)
		{
			max += mountainRange[i] - mountainRange[i - 1];
			postfix.push_back(max);
		}
		else if (mountainRange[i] - mountainRange[i - 1] < 0)
		{
			min += mountainRange[i] - mountainRange[i - 1];
			postfix.push_back(min);
		}
		else
		{
			postfix.push_back(0);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> f;
		if (s == f)
		{
			sum.push_back(0);
		}
		else {
			if (s < f)
			{
				int j = f - 1;
				int q = s - 1;

				while (postfix[j] < 1 && j > q)
				{
					j--;
				}

				if (j > 0 && j != q)
				{
					if (q != 0)
					{
						while (postfix[q] < 1 && q > 0)
						{
							q--;
						}
					}
					sum.push_back(postfix[j] - postfix[q]);
				}
				else
				{
					sum.push_back(0);
				}
			}
			else
			{
				int j = s - 1;
				int q = f - 1;

				while (postfix[j] > -1 && j > 0)
				{
					j--;
				}
				if (j != 0)
				{
					while (postfix[q] > -1 && q > 0)
					{
						q--;
					}
					sum.push_back(abs(postfix[j] - postfix[q]));
				}
				else
				{
					sum.push_back(0);
				}
			}
		}
	}

	for (auto i : sum)
		cout << i << endl;
}

