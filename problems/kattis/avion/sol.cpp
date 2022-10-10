#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    vector<int> V;

    for (int i = 0; i < 5; ++i)
    {
        cin >> s;
        for (int ii = 0; ii < s.length() - 2; ++ii)
        {
            if (s[ii] == 'F' && s[ii + 1] == 'B' && s[ii + 2] == 'I')
            {
                V.push_back(i + 1);
                break;
            }
        }
    }

    if (V.size())
    {
        for (int i = 0; i < V.size(); ++i)
        {
            if (i > 0)
                cout << " ";
            cout << V[i];
        }
        cout << endl;
    }
    else
    {
        cout << "HE GOT AWAY!" << endl;
    }
    return 0;
}