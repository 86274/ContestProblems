#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N = 0;
    int x = 0;
    int k = 0;
    vector<int> v;

    while (cin >> x)
    {
        v.push_back(x);
    }

    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i] > v[i -1] && v[i] > v[i + 1])
        {
            k++;
        }
    }

    cout << k;
   
}
