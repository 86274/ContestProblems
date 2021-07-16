#include <iostream>

using namespace std;

int main()
{
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;

    cin >> sideA >> sideB >> sideC;

    if (sideA > 0 && sideB > 0 && sideC > 0) {
        if (sideA > sideB) {
            if (sideA > sideC)
            {
                if (sideC + sideB > sideA)
                    cout << "YES";
                else 
                    cout << "NO";
            }else
                if (sideA + sideB > sideC)
                    cout << "YES";
                else
                    cout << "NO";
        }
        else
        {
            if (sideB > sideC)
            {
                if (sideC + sideA > sideB)
                    cout << "YES";
                else
                    cout << "NO";
            }
            else
                if (sideA + sideB > sideC)
                    cout << "YES";
                else
                    cout << "NO";
        }
    }
    else
        cout << "NO";
}