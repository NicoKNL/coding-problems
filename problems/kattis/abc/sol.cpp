#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> ABC(3, 0);
    cin >> ABC[0];
    cin >> ABC[1];
    cin >> ABC[2];

    sort(ABC.begin(), ABC.end());

    unordered_map<char, int> M;
    M['A'] = ABC[0];
    M['B'] = ABC[1];
    M['C'] = ABC[2];

    for (int i = 0; i < 3; ++i)
    {
        if (i > 0)
            cout << " ";
        char c;
        cin >> c;
        cout << M[c];
    }
    cout << endl;

    return 0;
}