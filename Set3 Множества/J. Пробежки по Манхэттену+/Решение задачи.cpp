#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void funcDot(pair<int, int> coordinate, int d, vector<pair<int, int>>& dots) {

	pair<int, int> buf;
	dots.clear();
	for (int x = coordinate.first - d; x <=coordinate.first + d; x++)
	{
		for (int y = coordinate.second - (d - abs((coordinate.first) - (x))); y <= coordinate.second + (d - abs((coordinate.first) - (x))); y++)
		{
			buf = { x, y };
			dots.push_back(buf);
		}
	}
}

void okdots(int t, vector<pair<int, int>>& dots, vector<pair<int, int>>& prevDots)
{
	vector<pair<int, int>> buf;
	for (int i = 0; i < dots.size(); i++)
	{
		for (int j = 0; j < prevDots.size(); j++)
		{

			if (abs(dots[i].first - prevDots[j].first) + abs(dots[i].second - prevDots[j].second) <=t)
			{
				buf.push_back(dots[i]);
				j = prevDots.size();
			}
		}
	}
	prevDots = buf;
}

int main()
{
	int t, d, n;
	vector<pair<int, int>> prevDots;
	vector<pair<int, int>> dots;
	pair<int, int> coordinate = { 0, 0 };
	prevDots.push_back(coordinate);
	
	cin >> t >> d >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> coordinate.first >> coordinate.second;
		funcDot(coordinate, d, dots);
		okdots(t, dots, prevDots);
	}
	
	cout << prevDots.size() << endl;
	for (auto i : prevDots)
		cout << i.first << " " << i.second << endl;
	
}

