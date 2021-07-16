#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <list>

using namespace std;

void insert(unordered_map<string, int>& dict, string& buf, pair<string, int>& word, pair<string, int>& max, list<string>& sequence, unordered_set<string>& keyWord) {


	if (!(buf.length() == 1 && buf[0] > 47 && buf[0] < 58))
	{

		auto jt = keyWord.find(buf);
		if (jt == keyWord.end())
		{
			auto it = dict.find(buf);
			if (it == dict.end())
			{
				word.first = buf;
				dict.insert(word);
				if (max.second == 0)
				{
					max = word;
				}
				sequence.push_back(word.first);
			}
			else
			{
				it->second++;
				if (max.second < it->second)
				{
					max = *it;
				}
				else if (max.second == it->second)
				{
					bool k = 1;
					for (auto i = sequence.begin(); i != sequence.end() && k == 1; i++)
					{
						if (max.first == *i)
						{
							k = 0;
						}
						if (it->first == *i)
						{
							max.first = *i;
							k = 0;
						}
					}
				}
			}
		}
	}
	buf.clear();
}

void yesNo(unordered_map<string, int>& dict, string& buf, pair<string, int>& word, pair<string, int>& max, string& enter, list<string>& sequence, unordered_set<string>& keyWord) {
	
		for (int i = 0; i < enter.length(); i++)
		{
			if (buf.empty())
			{
				if (enter[i] > 47 && enter[i] < 58) {
					i++;
					while ((enter[i] > 47 && enter[i] < 58 || enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95) && i < enter.length())
					{
						i++;
					}
				}
			}
			if (enter[i] > 47 && enter[i] < 58 || enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95)
			{
				buf.push_back(enter[i]);
			}
			else
			{
				if (!buf.empty())
				{
					insert(dict, buf, word, max, sequence, keyWord);
				}
			}
		}
		if (!buf.empty())
		{
			insert(dict, buf, word, max, sequence, keyWord);
		}
}

void NoNo(unordered_map<string, int>& dict, string& buf, pair<string, int>& word, pair<string, int>& max, string& enter, list<string>& sequence, unordered_set<string>& keyWord) {
	
		for (int i = 0; i < enter.length(); i++)
		{
			if (buf.empty())
			{
				if (enter[i] > 47 && enter[i] < 58) {
					i++;
					while ((enter[i] > 47 && enter[i] < 58 || enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95) && i < enter.length())
					{
						i++;
					}
				}
			}
			if (enter[i] > 47 && enter[i] < 58 || enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95)
			{
				if (!islower(enter[i]))
				{
					enter[i] = tolower(enter[i]);
				}
				buf.push_back(enter[i]);
			}
			else
			{
				if (!buf.empty())
				{
					insert(dict, buf, word, max, sequence, keyWord);
				}
			}
		}
		if (!buf.empty())
		{
			insert(dict, buf, word, max, sequence, keyWord);
		}
}

void NoYes(unordered_map<string, int>& dict, string& buf, pair<string, int>& word, pair<string, int>& max, string& enter, list<string>& sequence, unordered_set<string>& keyWord) {
	for (int i = 0; i < enter.length(); i++)
	{
		if (enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95 
			|| enter[i] > 47 && enter[i] < 58)
		{
			if (!islower(enter[i]))
			{
				enter[i] = tolower(enter[i]);
			}
			buf.push_back(enter[i]);
		}
		else
		{
			if (!buf.empty())
			{
				insert(dict, buf, word, max, sequence, keyWord);
			}
		}
	}
	if (!buf.empty())
	{
		insert(dict, buf, word, max, sequence, keyWord);
	}
}

void YesYes(unordered_map<string, int>& dict, string& buf, pair<string, int>& word, pair<string, int>& max, string& enter, list<string>& sequence, unordered_set<string>& keyWord) {
	
	for (int i = 0; i < enter.length(); i++)
	{
		if (enter[i] > 64 && enter[i] < 91 || enter[i] > 96 && enter[i] < 123 || enter[i] == 95
			|| enter[i] > 47 && enter[i] < 58)
		{
			buf.push_back(enter[i]);
		}
		else
		{
			if (!buf.empty())
			{
				insert(dict, buf, word, max, sequence, keyWord);
			}
		}
	}
	if (!buf.empty())
	{
		insert(dict, buf, word, max, sequence, keyWord);
	}
}


int main()
{
	int  n;
	string c, d, enter, buf;
	unordered_set<string> keyWord;
	unordered_map<string, int> dict;
	pair<string, int> word = { "", 1 };
	pair<string, int> max = { "", 0 };
	list<string> sequence;
	auto it = dict.begin();

	cin >> n;
	cin >> c >> d;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		if (c == "yes")
		{
			keyWord.insert(enter);
		}
		else
		{
			for (int i = 0; i < enter.length(); i++)
			{
				if (!islower(enter[i]))
				{
					enter[i] = tolower(enter[i]);
				}
			}
			keyWord.insert(enter);
		}
		
	}

	while (cin >> enter)
	{
		if (c == "yes" && d == "no")
		{
			yesNo(dict, buf, word, max, enter, sequence, keyWord);
		}
		else if (c == "no" && d == "no")
		{
			NoNo(dict, buf, word, max, enter, sequence, keyWord);
		}
		else if (c == "yes" && d == "yes")
		{
			YesYes(dict, buf, word, max, enter, sequence, keyWord);
		}
		else if (c == "no" && d == "yes")
		{
			NoYes(dict, buf, word, max, enter, sequence, keyWord);
		}
	} 

	cout << max.first;
}

