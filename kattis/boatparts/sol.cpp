#include <bits/stdc++.h>

using namespace std;

int main()
{
    int P, N;
    cin >> P >> N;

    set<string> parts;
    for (int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        parts.insert(tmp);

        if (parts.size() == P)
        {
            cout << (i + 1) << endl;
            return 0;
        }
    }

    cout << "paradox avoided" << endl;
    return 0;
}