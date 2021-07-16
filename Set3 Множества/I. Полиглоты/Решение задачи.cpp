#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	int N = 0;
	int M = 0;
	string lang;
	unordered_set<string> sAllLang;
	unordered_set<string> sLang;
	unordered_set<string> buf;
	auto it = sAllLang.begin();
	cin >> N;

	cin >> M;
	cin.ignore(1);
	for (int i = 0; i < M; i++)
	{
		getline(cin, lang);
		sAllLang.insert(lang);
	}
	sLang = sAllLang;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> M;
		cin.ignore(1);
		for (int j = 0; j < M; j++)
		{
			getline(cin, lang);
			it = sAllLang.find(lang);
			if (it != sAllLang.end())
			{
				it = sLang.find(lang);
				if (it != sLang.end())
				{
					buf.insert(lang);	
				}
			}
			sAllLang.insert(lang);
		}
		sLang = buf;
		buf.clear();
	}

	cout << sLang.size() << endl;
	for (auto i : sLang)
		cout << i << endl;

	cout << sAllLang.size() << endl;
	for (auto i : sAllLang)
		cout << i << endl;
}

