#include <bits/stdc++.h>

using namespace std;

double calculateScore(vector<double> V, int skip)
{
    double score = 0.0;

    int offset = 0;
    for (int i = 0; i < V.size(); ++i)
        if (i != skip)
            score += 0.2 * V[i] * pow(0.8, i - offset);
        else
            ++offset;

    return score;
}

int main()
{
    fixed(cout);
    cout.precision(10);

    int n;
    cin >> n;

    vector<double> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    cout << calculateScore(V, -1) << endl;

    vector<double> alt_scores;
    for (int i = 0; i < V.size(); ++i)
        alt_scores.push_back(calculateScore(V, i));

    double new_result = accumulate(alt_scores.begin(), alt_scores.end(), 0.0) / (double)alt_scores.size();
    cout << new_result << endl;

    return 0;
}