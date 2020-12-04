#include <bits/stdc++.h>
using namespace std;


int main()
{
    string in = "0123456789";
    int i = 0;
    do {
        ++i;
    } while (i < 1000000 && next_permutation(in.begin(), in.end()));
    cout << in;
}
