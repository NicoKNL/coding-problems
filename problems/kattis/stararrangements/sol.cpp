#include <bits/stdc++.h>

using namespace std;

bool match(int i, int s)
{
    while (s > 0)
    {
        s -= i;

        if (s == 0)
            break;

        s -= (i - 1);
    }

    return s == 0;
}

int main()
{
    int s;
    cin >> s;

    set<pair<int, int>> opts;

    for (int i = 2; i <= s - 1; ++i)
    {
        if (match(i, s))
            opts.insert({i, i - 1});

        if (s % i == 0)
            opts.insert({i, i});
    }

    cout << s << ":" << endl;

    for (auto opt : opts)
        if ((opt.first == 1 && opt.second == s) || (opt.first == s && opt.second == 1))
            continue;
        else
            cout << opt.first << "," << opt.second << endl;

    return 0;
}