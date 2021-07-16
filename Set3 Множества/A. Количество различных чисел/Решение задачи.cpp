#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<bool, 100000> arr{ 0 };
	int x;
	int k = 0;;

	while (cin >> x)
	{
		
			if (arr[x] == 0)
			{
				arr[x] = 1;
				k++;
			}
	}

	cout << k;
}