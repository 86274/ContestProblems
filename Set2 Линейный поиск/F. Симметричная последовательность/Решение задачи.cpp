#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    int x = 0;
    int M = 0;
    vector<int> v;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0, j = N - 1; i < j ; i++, j--)
    {
        if (v[i] != v[j])
        {
            M += N - j;
            j = N;
        }
    }

    cout << M << endl;
    for (int i = M - 1; i >= 0 ; i--)
    {
        cout << v[i] << " ";
    }
}
