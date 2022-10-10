#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> M;

    for (char c : s)
        ++M[c];

    vector<int> evens;
    vector<int> odds;
    for (auto each : M)
    {
        if (each.second % 2 == 0)
            evens.push_back(each.second);
        else
            odds.push_back(each.second);
    }

    sort(odds.begin(), odds.end(), greater<int>());

    int OK = accumulate(evens.begin(), evens.end(), 0);

    if (odds.size())
        OK += odds[0];

    for (int i = 1; i < odds.size(); ++i)
    {
        OK += odds[i] - 1;
    }

    cout << s.length() - OK << endl;

    return 0;
}