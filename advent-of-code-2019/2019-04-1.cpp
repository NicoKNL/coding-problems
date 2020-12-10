#include <bits/stdc++.h>
using namespace std;

bool nonDecreasing(int n)
{
    int div = 100000;
    int k = 0;

    while (div > 0) {
        if (n / div < k) return false;
        k = n / div;
        n %= div;
        div /= 10;
    }
    return true;
}

bool sameNeighbours(int n)
{
    string s_n = to_string(n);
    char c = s_n[0];
    for (int i = 1; i < 6; ++i) {
        if (s_n[i] == c) return true;
        c = s_n[i];
    }
    return false;
}

int main()
{
    int valid = 0;
    for (int i = 382345; i <= 843167; ++i) {
        if (nonDecreasing(i) && sameNeighbours(i)) ++valid;
    }
    cout << valid << endl;
}
