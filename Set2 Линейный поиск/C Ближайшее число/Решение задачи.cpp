#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N = 0;
    int x = 0;
    int minRaznost = 0;
    int y = 0;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cin >> x;

    minRaznost = abs(x - v[0]);
    y = v[0];
    for (int i = 1; i < N; i++)
    {
        if (abs(x - v[i]) < minRaznost)
        {
            minRaznost = abs(x - v[i]);
            y = v[i];
        }
    }

    cout << y;
}
