#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;

        if (s == "mumble")
            continue;

        int value = stoi(s);

        if (value != i)
        {
            cout << "something is fishy" << endl;
            return 0;
        }
    }

    cout << "makes sense" << endl;

    return 0;
}