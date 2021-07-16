#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <fstream>

using namespace std;

int main()
{
	unordered_set<string> A;
	string buf;
	ifstream f;
	f.open("input.txt");

	while (!f.eof())
	{
		f >> buf;
		if (buf != "")
		{
			A.insert(buf);
		}
	}
	cout << A.size();

	f.close();
}

