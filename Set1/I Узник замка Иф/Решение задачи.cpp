#include <iostream>

int main()
{
    int A, B, C, D, E;
    
    std::cin >> A >> B >> C >> D >> E;

    if (A > C)
        std::swap(A, C);
    if (B > C)
        std::swap(B, C);

    if (A <= D && B <= E || A <= E && B <= D)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}

