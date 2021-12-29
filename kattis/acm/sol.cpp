#include <bits/stdc++.h>

using namespace std;

int main()
{

    int time;
    char problem;
    string result;

    unordered_map<char, int> attempts;
    set<pair<char, int>> OKs;

    while (cin >> time)
    {
        if (time == -1)
            break;

        cin >> problem;
        cin >> result;

        if (result == "right")
            OKs.insert({problem, time});

        ++attempts[problem];
    }

    int score = 0;

    for (auto problem : OKs)
    {
        score += problem.second;
        score += (attempts[problem.first] - 1) * 20;
    }

    cout << OKs.size() << " " << score << endl;

    return 0;
}