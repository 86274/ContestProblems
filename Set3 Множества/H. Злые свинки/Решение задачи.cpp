#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int N = 0;
	int x = 0;
	int y = 0;
	unordered_set<int> s;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		s.insert(x);
	}

	cout << s.size();
}

