#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> target{1, 1, 2, 2, 2, 8};

    for (int i = 0; i < 6; ++i)
    {
        int tmp;
        cin >> tmp;
        cout << target[i] - tmp << " ";
    }

    cout << endl;

    return 0;
}