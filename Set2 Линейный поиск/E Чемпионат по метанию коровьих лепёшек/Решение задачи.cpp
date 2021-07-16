#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    int x = 0;
    int k = 0;
    int maxGavno = 0;
    int maxVasya = 0;
    bool govnodel = 0;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    for (auto it : v)
    {
        if (it > maxGavno)
        {
            maxGavno = it;
        }
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] % 10 == 5 && v[i] > v[i + 1] && govnodel == 1 && v[i] > k)
        {
            k = v[i];
        }
        if (v[i] == maxGavno)
        {
            govnodel = 1;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == k)
        {
            maxVasya = v.size() - i;
        }
    }

    cout << maxVasya;
   
}
