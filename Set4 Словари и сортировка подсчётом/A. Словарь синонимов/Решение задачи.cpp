#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	int N;
	pair<string, string> sinonyms;
	unordered_map<string, string> dict;
	string key;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> sinonyms.first >> sinonyms.second;
		dict.insert(sinonyms);
		swap(sinonyms.first, sinonyms.second);
		dict.insert(sinonyms);
	}

	cin >> key;

	if (dict.size() > 0)
	{
		auto it = dict.find(key);
		cout << it->second;
	}

}

