#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    double tuner = 0;
    double max = 4000;
    double min = 30;
    double f = 0;
    double fPrev = 0;
    double r = 0;
    string s;
    cout.precision(10);
    cin >> n >> tuner;
    fPrev = tuner;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> f >> s;
        r = fPrev - f;
        if (r != 0)
        {

            if (s == "closer")
            {
                if (r > 0)
                {
                    if (max > f + r / 2 && min < f + r / 2)
                    {
                        max = f + r / 2;
                    }
                }
                else
                {
                    if (min < f + r / 2 && max > f + r / 2)
                    {
                        min = f + r / 2;
                    }
                }

            }
            else {
                if (r > 0)
                {
                    if (min < f + r / 2 && max > f + r / 2)
                    {
                        min = f + r / 2;
                    }
                }
                else
                {
                    if (max > f + r / 2 && min < f + r / 2)
                    {
                        max = f + r / 2;
                    }
                }
            }
            fPrev = f;
        }
    }
    cout << min << " " << max;
}

