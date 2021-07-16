#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	double max = 0;
	pair<double, double> sizep;
	map < double, double> pir;
	auto it = pir.begin();

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> sizep.first >> sizep.second;
		it = pir.find(sizep.first);
		if (it == pir.end())
		{
			pir.insert(sizep);
		}
		else
		{
			if (it->second < sizep.second)
			{
				it->second = sizep.second;
			}
		}
	}

	for (auto& i : pir)
		max += i.second;

	cout << fixed << setprecision(0) << max;
}

