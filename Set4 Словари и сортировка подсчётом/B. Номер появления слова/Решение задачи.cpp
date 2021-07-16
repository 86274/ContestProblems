#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	pair < string, int> word = { "", 0 };
	map<string, int> dict;
	auto it = dict.begin();

	while (cin >> word.first)
	{
		it = dict.find(word.first);
		if (it == dict.end())
		{
			dict.insert(word);
			cout << 0 << " ";
		}
		else
		{
			it->second++;
			cout << it->second << " ";
		}
	}

}

