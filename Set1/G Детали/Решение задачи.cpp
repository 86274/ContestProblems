#include <iostream>

using namespace std;

int main()
{
	int N, M, K; //масса: сплава, заготовки, детали
	int w = 0; // количество заготовок из сплава
	int z = 0; // количество деталей из одной заготовки
	int details = 0;

	cin >> N >> M >> K;

	while (N >= M)
	{
		w = N / M;
		N = N % M;
		z = M / K;
		if (z > 0) //если хватает массы зоготовки для изготовления детали
		{
			details += w * z;
			N += (M % K) * w;
		}
	}

	cout << details;
}