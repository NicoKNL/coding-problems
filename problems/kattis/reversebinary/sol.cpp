#include <bits/stdc++.h>

using namespace std;

int main()
{
    int in;
    int out = 0;

    cin >> in;

    while (in)
    {
        out <<= 1;
        out += in & 1;
        in >>= 1;
    }

    cout << out << endl;

    return 0;
}