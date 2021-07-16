#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

int main()
{
	int x, An, Bm;
	unordered_set<int> A;
	vector<int> Anya;
	vector<int> B;
	vector<int> AB;

	cin >> An >> Bm;

	for (int i = 0; i < An; i++)
	{
		cin >> x;
		A.insert(x);
	}

	for (int i = 0; i < Bm; i++)
	{
		cin >> x;
		if (A.contains(x) == 1)
		{
			AB.push_back(x);
		}
		else
		{
			B.push_back(x);
		}
	}

	for (auto i : AB)
	{
		A.erase(i);
	}

	for (auto i : A)
	{
		Anya.push_back(i);
	}

	sort(Anya.begin(), Anya.end());
	sort(B.begin(), B.end());
	sort(AB.begin(), AB.end());

	cout << AB.size() << endl;
	for (auto i : AB) {
		cout << i << " ";
	}
	cout << endl;

	cout << Anya.size() << endl;
	for (auto i : Anya) {
		cout << i << " ";
	}
	cout << endl;

	cout << B.size() << endl;
	for (auto i : B) {
		cout << i << " ";
	}

}

