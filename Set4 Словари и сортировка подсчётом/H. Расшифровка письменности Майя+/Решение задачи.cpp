#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	int g, s;
	int k = 0;
	int sizeword = 0;
	int countw = 0;
	string word;
	unordered_map<char, int> w;
	unordered_map<char, int> wbuf;
	pair<char, int> buf{ '\0',1 };
	auto it = w.begin();
	auto jt = wbuf.begin();

	cin >> g >> s;

	for (int i = 0; i < g; i++)
	{
		cin >> buf.first;
		it = w.find(buf.first);
		if (it == w.end())
		{
			w.insert(buf);
			sizeword++;
		}
		else
		{
			it->second++;
			sizeword++;
		}
	}

	for (int i = 0; i < s; i++)
	{
		cin >> buf.first;
		it = w.find(buf.first);
		if (it != w.end())
		{
			jt = wbuf.find(buf.first);
			if (jt == wbuf.end())
			{
				wbuf.insert(buf);
				k++;
				word.push_back(buf.first);
			}
			else
			{
				if (it->second > jt->second)
				{
					jt->second++;
					k++;
					word.push_back(buf.first);
				}
				else
				{
					for (int i = 0; i < word.length(); i++)
					{
						if (word[i] == buf.first)
						{
							word.erase(0, i + 1);
							word.push_back(buf.first);
							k = k - i;
							i = word.size();
						}
						else
						{
							jt = wbuf.find(word[i]);
							jt->second--;
							if (jt->second == 0)
							{
								wbuf.erase(word[i]);
							}
						}
					}
				}
			}
			if (k == sizeword)
			{
				countw++;
				k--;
				jt = wbuf.find(word[0]);
				jt->second--;
				if (jt->second == 0)
				{
					wbuf.erase(word[0]);
				}
				word.erase(0, 1);
			}
		}
		else
		{
			k = 0;
			word.clear();
			wbuf.clear();
		}
	}
	cout << countw;
}

