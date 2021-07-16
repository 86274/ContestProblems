// Yandex training TypePosled.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool CONSTANT = 1;
    bool ASCENDING = 1;
    bool WEAKLYASCENDING = 1;
    bool DESCENDING = 1;
    bool WEAKLYDESCENDING = 1;
    bool RANDOM = 0;
    int x = 0;
    vector<int> v;

    cin >> x;
    while (x != -2000000000)
    {
        v.push_back(x);
        cin >> x;
    }

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] != v[i + 1])
        {
            CONSTANT = 0;
        }
        if (v[i] > v[i + 1])
        {
            ASCENDING = 0;
            WEAKLYASCENDING = 0;
        }
        if (v[i] < v[i + 1])
        {
            DESCENDING = 0;
            WEAKLYDESCENDING = 0;
        }
        if (v[i] == v[i + 1])
        {
            ASCENDING = 0;
            DESCENDING = 0;
        }
    }

    if (v.size() < 2)
    {
        cout << "RANDOM";
    }
    else if (CONSTANT == 1)
    {
        cout << "CONSTANT";
    }
    else if (ASCENDING == 1)
    {
        cout << "ASCENDING";
    }
    else if (WEAKLYASCENDING == 1)
    {
        cout << "WEAKLY ASCENDING";
    }
    else if (DESCENDING == 1)
    {
        cout << "DESCENDING";
    }
    else if (WEAKLYDESCENDING == 1)
    {
        cout << "WEAKLY DESCENDING";
    }
    else
        cout << "RANDOM";
}
