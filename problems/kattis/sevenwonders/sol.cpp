#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> M;
    set<char> charset;

    for (const auto &c : s)
    {
        ++M[c];
        charset.insert(c);
    }

    int score = 0;

    // add squares;
    score += M['C'] * M['C'] + M['G'] * M['G'] + M['T'] * M['T'];

    // If we have full sets
    if (charset.size() == 3)
    {
        int set_count = INT_MAX;
        for (const auto &each : M)
        {
            set_count = min(set_count, each.second);
        }
        score += 7 * set_count;
    }

    cout << score << endl;

    return 0;
}