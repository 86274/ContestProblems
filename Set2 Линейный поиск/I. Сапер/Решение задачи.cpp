#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m, k, p, q;
	vector < vector<int>> pole;

	cin >> n >> m >> k;
	
	pole.resize(n);
	for (int i = 0; i < n; i++)
	{
		pole[i].resize(m);
	}

	for (int i = 0; i < k; i++)
	{
		cin >> p >> q;
		pole[p - 1][q - 1] = '*';
		
		if (p <  n) //вниз
		{
			pole[p][q - 1]++;//снизу
		}
		if (p - 2 >= 0)
		{
			pole[p - 2][q - 1]++; //сверху
		}
		if (q < m)
		{
			pole[p - 1][q]++; //справа
		}
		if (q - 2 >= 0)
		{
			pole[p - 1][q - 2]++; //слева
		}

		if (p < n && q < m) //вниз
		{
			pole[p][q]++;//снизу спрва
		}
		if (p < n && q - 2 >= 0) //вниз
		{
			pole[p][q - 2]++;//снизу слева
		}
		if (p - 2 >= 0 && q < m)
		{
			pole[p - 2][q]++; //сверху справа
		}
		if (p - 2 >= 0 && q - 2 >= 0)
		{
			pole[p - 2][q - 2]++; //сверху слева
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pole[i][j] >= 42)
			{
				cout << "*";
			}
			else
				cout << pole[i][j];
			if (j + 1 == m)
			{
				cout << endl;
			}
			else
				cout << " ";
		}
	}
}

