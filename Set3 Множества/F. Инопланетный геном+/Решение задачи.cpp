#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

int main()
{
	ifstream f;
	f.open("input.txt");
	int k = 0;
	int count = 0;
	char buf[3] = { 0, 0, 0 };
	unordered_multiset<string> s;

	f >> buf[1];
	while (f.peek() != '\n')
	{
		buf[0] = buf[1];
		f >> buf[1];
		s.insert(buf);
	}

	f >>  buf[1];
	while (f.peek() != '\n')
	{
		buf[0] = buf[1];
		f >> buf[1];
		count = s.count(buf);
		if (count)
		{
			s.erase(buf);
			k += count;
		}
		count = 0;
	}

	cout << k;

	f.close();
}

