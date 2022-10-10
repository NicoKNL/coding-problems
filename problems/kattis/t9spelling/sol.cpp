#include <bits/stdc++.h>

using namespace std;

int main()
{
    // clang-format off
    unordered_map<char, pair<int, int>> M = {
        {'a', {2, 1}}, {'b', {2, 2}}, {'c', {2, 3}},
        {'d', {3, 1}}, {'e', {3, 2}}, {'f', {3, 3}},
        {'g', {4, 1}}, {'h', {4, 2}}, {'i', {4, 3}},
        {'j', {5, 1}}, {'k', {5, 2}}, {'l', {5, 3}},
        {'m', {6, 1}}, {'n', {6, 2}}, {'o', {6, 3}},
        {'p', {7, 1}}, {'q', {7, 2}}, {'r', {7, 3}}, {'s', {7, 4}},
        {'t', {8, 1}}, {'u', {8, 2}}, {'v', {8, 3}},
        {'w', {9, 1}}, {'x', {9, 2}}, {'y', {9, 3}}, {'z', {9, 4}},
        {' ', {0, 1}}
    };

    //clang-format on
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);

        string result = "";
        int prev = -1;

        for (char c : line) {
            int t9char = M[c].first;
            int times = M[c].second;

            if (prev == t9char) result += ' ';

            while (times--) result += to_string(t9char);

            prev = t9char;
        }

        printf("Case #%d: %s\n", i, result.c_str());
    }
    return 0;
}