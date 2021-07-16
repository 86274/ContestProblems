#include <iostream>

using namespace std;

int main()
{
    int troom = 0;
    int tcond = 0;
    string mode = {};

    cin >> troom >> tcond;
    cin >> mode;

    if (mode == "freeze") {
        if (tcond >= troom)
            cout << troom;
        else
            cout << tcond;
    }
    else
    {
        if (mode == "heat")
        {
            if (tcond <= troom)
                cout << troom;
            else
                cout << tcond;
        }
        else
        {
            if (mode == "auto")
                cout << tcond;
            else
                cout << troom;
        }
    }
 
}