#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s)
{
    vector<string> result;

    while (s.find('-') != string::npos)
    {
        int i = s.find('-');
        result.push_back(s.substr(0, i));
        s = s.substr(i + 1);
    }

    result.push_back(s);

    return result;
}

unsigned long long rankOf(string s)
{
    vector<string> ranks = split(s);
    // for (auto each : ranks)
    // {
    //     cout << each << endl;
    // }
    reverse(ranks.begin(), ranks.end());

    string rank = "1111111111";
    for (int i = 0; i < ranks.size(); ++i)
    {
        if (ranks[i] == "upper")
            rank[i] = '2';
        if (ranks[i] == "middle")
            rank[i] = '1';
        if (ranks[i] == "lower")
            rank[i] = '0';
    }
    // cout << "rank: " << rank << endl;
    return stol(rank);
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        vector<pair<unsigned long long, string>> V;

        while (n--)
        {
            string name, _class, _;
            cin >> name >> _class >> _;
            // cout << "n: " << name << " " << _class << " " << _ << ";" << endl;
            V.push_back({rankOf(_class), name.substr(0, name.length() - 1)});
        }

        sort(V.begin(), V.end(), [](pair<unsigned long long, string> a, pair<unsigned long long, string> b)
             {
                 if (a.first > b.first)
                     return true;
                 else if (a.first == b.first && a.second < b.second)
                     return true;
                 else
                     return false;
             });

        for (auto each : V)
        {
            cout << each.second << endl;
        }
        cout << "==============================" << endl;
    }

    return 0;
}