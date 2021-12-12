#include <bits/stdc++.h>
using namespace std;

bool nonDecreasing(int n)
{
    int div = 100000;
    int k = 0;

    while (div > 0)
    {
        if (n / div < k)
            return false;
        k = n / div;
        n %= div;
        div /= 10;
    }
    return true;
}

bool doubleButNotTriple(int n)
{
    string s_n = to_string(n);

    char c1 = s_n[0];
    char c2 = s_n[1];
    char c3 = s_n[2];
    char c4 = s_n[3];
    char c5 = s_n[4];
    char c6 = s_n[5];

    return ((c1 == c2 && c2 != c3) || (c1 != c2 && c2 == c3 && c3 != c4) || (c2 != c3 && c3 == c4 && c4 != c5) || (c3 != c4 && c4 == c5 && c5 != c6) || c4 != c5 && c5 == c6);
}

int main()
{
    int valid = 0;
    for (int i = 382345; i <= 843167; ++i)
    {
        if (nonDecreasing(i) && doubleButNotTriple(i))
            ++valid;
    }
    cout << valid << endl;
}
