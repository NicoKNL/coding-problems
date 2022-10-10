#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    long long c_back, c_front, c_startstop;
    cin >> c_back >> c_front >> c_startstop;

    string colors;
    string pattern;

    cin >> colors >> pattern;

    unordered_map<char, long long> cost;

    for (char c : colors)
    {
        cost[c] = 0ll;
    }

    for (char c : colors)
    {

        cost[c] = count(pattern.begin(), pattern.end(), c) * c_front;
        // IF color is used, we start and end it at least once
        if (pattern[0] == c)
            cost[c] += c_startstop;
        if (pattern[pattern.size() - 1] == c)
            cost[c] += c_startstop;

        vector<pair<int, int>> gaps;
        pair<int, int> current_gap = {0, 0};
        // rrrrr----rrrrr
        //      s..e
        for (int i = 0; i < pattern.length(); ++i)
        {
            if (pattern[i] == c)
            {
                if (pattern[current_gap.first] != c)
                    gaps.push_back(current_gap);

                current_gap = {i + 1, i + 1};
            }
            else
            {
                current_gap.second = i;
            }
        }

        if (current_gap.first < pattern.length() && (current_gap.second - current_gap.first + 1) != pattern.length())
            gaps.push_back(current_gap);

        // rrrrrgbgbgbgbgbrrrrr

        // abbbbbbbba
        // 012345678

        for (int ii = 0; ii < gaps.size(); ++ii)
        {
            auto gap = gaps[ii];
            // cout << "color: " << c << ", " << gap.first << ":" << gap.second << endl;
            // cout << "cost before: " << cost[c] << "    ";
            if (ii == 0 && gap.first == 0)
            {
                // cout << "1" << endl;
                // ----rrr
                cost[c] += c_startstop;
            }
            else if (ii == gaps.size() - 1 && gap.second == pattern.length() - 1)
            {
                // cout << "2" << endl;
                // rrrrr----
                //      s..e
                cost[c] += c_startstop;
            }
            else
            {
                // cout << "3" << endl;
                // rrrrr----rrrrr
                //      s..e
                cost[c] += min(2 * c_startstop, (gap.second - gap.first + 1) * c_back);
            }
            // cout << "cost after: " << cost[c] << endl;
        }

        cout << cost[c] << endl;
    }

    return 0;
}