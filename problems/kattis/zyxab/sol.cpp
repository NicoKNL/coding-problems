#include <bits/stdc++.h>

using namespace std;

bool containsDoubleChar(string s)
{
    unordered_map<char, int> M;

    for (char c : s)
    {
        ++M[c];

        if (M[c] > 1)
            return true;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    vector<string> candidates;
    while (n--)
    {
        string tmp;
        cin >> tmp;

        if (tmp.length() < 5)
            continue;

        if (containsDoubleChar(tmp))
            continue;

        candidates.push_back(tmp);
    }

    sort(candidates.begin(), candidates.end(), [](const string &a, const string &b) -> bool
         {
             if (a.length() < b.length())
                 return true;
             else
                 return (a.length() <= b.length() && a > b);
         });

    if (candidates.size())
        cout << candidates[0] << endl;
    else
        cout << "neibb!" << endl;

    return 0;
}