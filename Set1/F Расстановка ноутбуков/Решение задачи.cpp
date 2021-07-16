#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 2> noteA;
	array<int, 2> noteB;
	int maxSide[2][1] = { 0, 0 };
	int s[2];

	cin >> noteA[0] >> noteA[1];
	cin >> noteB[0] >> noteB[1];

	if (noteA[1] > noteA[0])
	{
		swap(noteA[1], noteA[0]);
	}

	if (noteB[1] > noteB[0])
	{
		swap(noteB[1], noteB[0]);
	}

	if (noteA[0] > noteB[0])
	{
		s[0] = noteA[0];
		s[1] = noteA[1];

		if (noteA[1] >= noteB[0] && noteA[1] >= noteB[1])
			s[0] += noteB[1];
		else
			s[1] += noteB[1];
	}
	else
	{
		s[0] = noteB[0];
		s[1] = noteB[1];

		if (noteB[1] >= noteA[0] && noteB[1] >= noteA[1])
			s[0] += noteA[1];
		else
			s[1] += noteA[1];
	}

	cout << s[0] << " " << s[1];
}