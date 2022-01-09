#include <bits/stdc++.h>

using namespace std;

struct runner
{
    string name;
    double a;
    double b;
};

int main()
{
    fixed(cout);
    cout.precision(12);

    int n;
    cin >> n;

    vector<runner> V(n, {"", 0, 0});
    for (int i = 0; i < n; ++i)
        cin >> V[i].name >> V[i].a >> V[i].b;

    double best_score = INFINITY;
    vector<string> best_team;

    sort(V.begin(), V.end(),
         [](auto lhs, auto rhs)
         {
             return lhs.b < rhs.b;
         });

    for (int i = 0; i < n; ++i)
    {
        double score = V[i].a;

        vector<int> indices;
        if (i == 0)
            indices = {1, 2, 3};
        else if (i == 1)
            indices = {0, 2, 3};
        else if (i == 2)
            indices = {0, 1, 3};
        else
            indices = {0, 1, 2};

        for (int ii : indices)
            score += V[ii].b;

        if (score < best_score)
        {
            best_score = score;
            best_team = {V[i].name, V[indices[0]].name, V[indices[1]].name, V[indices[2]].name};
        }
    }

    cout << best_score << endl;

    for (string name : best_team)
        cout << name << endl;

    return 0;
}