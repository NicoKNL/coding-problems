#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.length(); ++i)
    {
        if (((n & 1) && (a[i] == b[i])) || (!(n & 1) && (a[i] != b[i])))
        {
            cout << "Deletion failed" << endl;
            return 0;
        }
    }

    cout << "Deletion succeeded" << endl;
    return 0;
}