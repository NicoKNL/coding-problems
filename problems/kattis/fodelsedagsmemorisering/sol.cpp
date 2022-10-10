#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> like_map;
    unordered_map<string, string> name_map;

    while (n--)
    {
        string name;
        int like;
        string date;

        cin >> name >> like >> date;

        bool must_insert = false;
        if (like_map.find(date) == like_map.end())
        {
            must_insert = true;
        }
        else
        {
            if (like > like_map[date])
                must_insert = true;
        }

        if (must_insert)
        {
            like_map[date] = like;
            name_map[date] = name;
        }
    }

    vector<string> names;

    for (const auto &each : name_map)
    {
        names.push_back(each.second);
    }

    sort(names.begin(), names.end());

    cout << names.size() << endl;
    for (const auto &name : names)
        cout << name << endl;

    return 0;
}