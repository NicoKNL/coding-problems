#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int towers = 0;
    int prev_block = -1;
    for (int i = 0; i < n; ++i)
    {
        int block;
        cin >> block;

        if (block > prev_block)
            ++towers;

        prev_block = block;
    }

    cout << towers << endl;

    return 0;
}