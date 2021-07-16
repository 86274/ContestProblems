#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unordered_multimap<string, string> dict;
	//unordered_set<char> small = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g','h','j', 'k', 'l','z','x','c','v','b','n','m' };
	string buf;
	string accent;
	pair<string, string> word;
	int err = 0;
	int N;
	int k = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> buf;
		accent = buf;
		for (int i = 0; i < buf.length(); i++)
		{
			if (!islower(buf[i]))
			{
				buf[i] = tolower(buf[i]);
			}
		}
		word.first = buf;
		word.second = accent;
		dict.insert(word);
	}

	while (cin >> buf)
	{
		accent = buf;
		for (int i = 0; i < buf.length(); i++)
		{
			if (!islower(buf[i]))
			{
				buf[i] = tolower(buf[i]);
			}
		}
		auto range = dict.equal_range(buf);

		if (range.first != dict.end())
		{
			for (auto it = range.first; it != range.second; it++)
			{
				if (accent == it->second)
				{
					k++;
				}
			}
			if (k == 0)
			{
				err++;
			}
		}
		else
		{
			for (int i = 0; i < accent.length(); i++)
			{
				if (accent[i] > 64 && accent[i] < 91)
				{
					k++;
					if (k > 1)
					{
						err++;
						i = accent.length();
					}
				}
			}
			if (k == 0)
			{
				err++;
			}
			
		}
		k = 0;
	}
	cout << err;
}

