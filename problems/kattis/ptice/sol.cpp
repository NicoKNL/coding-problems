#include <bits/stdc++.h>

using namespace std;

int getScore(string guesses, string answers)
{
    int score = 0;

    for (int i = 0; i < answers.length(); ++i)
        if (guesses[i] == answers[i])
            ++score;

    return score;
}

int main()
{
    int n;
    string answers;

    cin >> n >> answers;

    string adrian = "ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABC";
    string bruno = "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC";
    string goran = "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABB";

    vector<pair<string, int>> scores = {
        {"Adrian", getScore(adrian, answers)},
        {"Bruno", getScore(bruno, answers)},
        {"Goran", getScore(goran, answers)},
    };

    int maxi = (*max_element(scores.begin(), scores.end(), [](pair<string, int> a, pair<string, int> b)
                             { return a.second < b.second; }))
                   .second;

    cout << maxi << endl;

    for (auto each : scores)
        if (each.second == maxi)
            cout << each.first << endl;

    return 0;
}