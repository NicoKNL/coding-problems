#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> M;
    int count = 0;
    for (int i = 0; i < n && count < 12; ++i)
    {
        string uni, team;
        cin >> uni >> team;

        if (M.find(uni) == M.end())
        {
            ++M[uni];
            ++count;
            cout << uni << " " << team << endl;
        }
    }

    return 0;
}