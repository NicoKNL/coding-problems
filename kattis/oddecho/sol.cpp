#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;

        if ((i + 1) & 1)
            cout << s << endl;
    }
    return 0;
}