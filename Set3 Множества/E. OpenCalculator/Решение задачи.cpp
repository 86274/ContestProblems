#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

int main()
{
	int k = 0;
	int x = 0;
	char buf = '\0';
	array<bool, 10> xyz{ 0 };

	for (int i = 0; i < 3; i++)
	{
		cin >> x;
		xyz[x % 10] = 1;
	}

	while (cin >> buf)
	{
		if (xyz[atoi(&buf)] == 0)
		{
			k++;
			xyz[atoi(&buf)] = 1;
		}
	}

	cout << k;
}

