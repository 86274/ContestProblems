#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int maxC = 0;
	string s;
	vector<string> maxS;
	pair < string, int> word = { "", 0 };
	unordered_map<string, int> dict;
	auto it = dict.begin();

	while (cin >> word.first)
	{
		it = dict.find(word.first);
		if (it == dict.end())
		{
			dict.insert(word);
			if (maxC == 0)
			{
				maxS.push_back(word.first);
			}
		}
		else
		{
			it->second++;
			if (maxC == it->second)
			{
				maxS.push_back(word.first);
			}
			else if (maxC < it->second)
			{
				maxC = it->second;
				maxS.clear();
				maxS.push_back(word.first);
			}
		}
	}

	s = maxS[0];
	for (int i = 1; i < maxS.size(); i++)
	{
		if (s > maxS[i])
		{
			s = maxS[i];
		}
	}


	cout << s;
}

