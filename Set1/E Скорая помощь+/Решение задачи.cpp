#include <iostream>

using namespace std;

int main()
{
    int k1, m, k2, p2, n2;
    int p1 = 0;
    int n1 = 0;
    int kStage = 0;
    int kM = 0;

    cin >> k1 >> m >> k2 >> p2 >> n2;

    if (k1 == 1)
    {
        cout << 1 << " " << 1;
    }
    else  if (n2 > m || k2 < m * (p2 - 1) + n2 || m * (p2 - 1) + n2 < 1) //квартир на один подъезд должно быть не менее этажей и этаж должен быть не более всего этажей
    {
        cout << -1 << " " << -1;
    }
    else {
        int error = 0;
        if (k2 % (n2 + (p2 - 1) * m) != 0) // минимально возможное количество этажей
        {
            kStage = k2 / (n2 + (p2 - 1) * m) + 1;
            if (kStage * (m * (p2 - 1) + n2 - 1) > k2)
            {
                error = 1;
            }
        }
        else
        {
            kStage = k2 / (n2 + (p2 - 1) * m);
            if (kStage * (m * (p2 - 1) + n2 - 1) > k2)
            {
                error = 1;
            }
        }
        if (error == 1)
        {
            cout << -1 << " " << -1;
        }
        else if (n2 == 1 && p2 == 1) //если 1 этаж и 1 подъезд, то неоднозначность
        {
            if (k1 != k2)
            {
                if (k1 < k2)
                {
                    cout << 1 << " " << 1;
                }
                else
                {
                    if (k2 * m >= k1)
                    {
                        cout << 1 << " ";
                    }
                    else
                    {
                        cout << 0 << " ";
                    }

                    if (m == 1)
                    {
                        cout << 1;
                    }
                    else
                    {
                        cout << 0;
                    }
                }
            }
            else
            {
                cout << p2 << " " << n2;
            }
        }
        else if (k1 == k2) {
            cout << p2 << " " << n2;
        }
        else
        {
            if ((m * (p2 - 1) + n2) * (m * (p2 - 1) + n2) > k2 || p2 == k2) {
                if (k2 % (n2 + (p2 - 1) * m) != 0)
                {
                    kStage = k2 / (n2 + (p2 - 1) * m) + 1;
                }
                else
                {
                    kStage = k2 / (n2 + (p2 - 1) * m);
                }
                kM = kStage * m;
                p1 = (k1 - 1) / kM + 1;
                n1 = ((k1 - 1) - kM * (p1 - 1)) / kStage + 1;
                cout << p1 << " " << n1;
            }
            else
            {
                int p12 = 0;
                int n12 = 0;

                if (k2 % (n2 + (p2 - 1) * m) != 0) // минимально возможное количество этажей
                {
                    kStage = k2 / (n2 + (p2 - 1) * m) + 1;
                }
                else
                {
                    kStage = k2 / (n2 + (p2 - 1) * m);
                }
                kM = kStage * m;
                p1 = (k1 - 1) / kM + 1;
                n1 = ((k1 - 1) - kM * (p1 - 1)) / kStage + 1;

                if (k2 % (n2 + (p2 - 1) * m) != 0) // максимальное возможное количество этажей
                {
                    kStage = k2 / (n2 + (p2 - 1) * m) + 2;
                }
                else
                {
                    kStage = k2 / (n2 + (p2 - 1) * m) + 1;
                }
                kM = kStage * m;
                p12 = (k1 - 1) / kM + 1;
                n12 = ((k1 - 1) - kM * (p12 - 1)) / kStage + 1;

                if (p1 == p12 && n1 == n12)
                {
                    cout << p1 << " " << n1;
                }
                else if (p1 == p12 && n1 != n12)
                {
                    cout << p1 << " " << 0;
                }
                else if (p1 != p12 && n1 == n12)
                {
                    cout << 0 << " " << n1;
                }
                else if (p1 != p12 && n1 != n12)
                {
                    cout << p1 << " " << n1;
                }
            }

        }
    }

}


