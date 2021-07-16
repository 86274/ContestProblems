#include <iostream>

using namespace std;

double funcXXYY(double b, double e) {
    return e / b;
}

void funcYkxb(double a, double b, double e) {
    if (a == 0 && b == 0)
    {
        cout << 0;
    }
    else if (a == 0)
    {
        cout << 4 << " " << funcXXYY(b, e);
    }
    else if (b == 0)
    {
        cout << 3 << " " << funcXXYY(a, e);
    }
    else
    {
        a = a / b;
        e = e / b;
        cout << 1 << " " << -a << " " << e;
    }
}

int main()
{
    double a, b, c, d, e, f;
    double k = 0;
    double x = 0;
    double y = 0;

    cin >> a >> b >> c >> d >> e >> f;
    cout.precision(10);

    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0)
    {
        cout << 5;
    }
    else if (a == 0 && b == 0)
    {
        if (e == 0)
        {
            funcYkxb(c, d, f);
        }
        else
        {
            cout << 0;
        }
    }
    else if (c == 0 && d == 0)
    {
        if (f == 0)
        {
            funcYkxb(a, b, e);
        }
        else
        {
            cout << 0;
        }
    }
    else if (a == 0 && c == 0)
    {
        if (funcXXYY(d, f) == funcXXYY(b, e))
            cout << 4 << " " << funcXXYY(b, e);
        else
            cout << 0;
    }
    else if (b == 0 && d == 0)
    {
        if (funcXXYY(a, e) == funcXXYY(c, f))
            cout << 3 << " " << funcXXYY(c, f);
        else cout << 0;
    }
    else if (e == 0 && f == 0)
    {
        k = c / a;

        c = c / k;
        d = d / k;
        f = f / k;

        c = c - a;
        d = d - b;
        f = f - e;

        if (d == 0)
        {
            funcYkxb(a, b, e);
        }
        else
        {
            cout << 0;
        }

    }
    else if (a == 0)
    {
        k = (f - d * (e / b)) / c;
        cout << 2 << " " << k << " " << e / b;
    }
    else if (c == 0)
    {
        cout << 2 << " " << (e - b * (f / d)) / a << " " << f / d;
    }
    else if (b == 0)
    {
        cout << 2 << " " << e / a << " " << (f - c * (e / a )) / d;
    }
    else if (d == 0)
    {
        cout << 2 << " " << f / c << " " << (e - a * (f / c)) / b;
    }
    else
    {
        k = c / a;

        c = c / k;
        d = d / k;
        f = f / k;

        c = c - a;
        d = d - b;
        f = f - e;

        if (d == 0)
        {
            if (f == 0)
            {
                funcYkxb(a, b, e);
            }
            else
            {
                cout << 0;
            }
        }
        else
        {
            f = f / d;
            y = f;

            x = (e - b * f) / a;

            cout << 2 << " " << x << " " << y;
        }
    }
}


