#include <bits/stdc++.h>

typedef double T;

using namespace std;

void printTable(vector<vector<T>> t)
{
    cout << "========================" << endl;
    for (int i = 1; i < t.size(); ++i)
    {
        for (int ii = 0; ii < t.size(); ++ii)
        {
            cout << t[i][ii] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.precision(20);

    int n;
    cin >> n;

    vector<T> score;
    for (int i = 0; i < n; ++i)
    {
        T s;
        cin >> s;
        score.push_back(s);
    }

    vector<vector<T>> DP;

    for (int stepsize = 0; stepsize < n; ++stepsize)
    {
        vector<T> row;
        for (int i = 0; i < n; ++i)
        {
            row.push_back(-LLONG_MIN);
        }
        DP.push_back(row);
    }

    for (int stepsize = n - 1; stepsize >= 1; --stepsize)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
            {
                DP[stepsize][i] = score[i];
            }
            else
            {
                int offset = 0;
                T best = -LLONG_MIN;

                while (i - (stepsize + offset) >= 0 && stepsize + offset < n)
                {
                    best = max(best, DP[stepsize + offset][i - (stepsize + offset)] + score[i]);
                    ++offset;
                }

                DP[stepsize][i] = best;
            }
        }
    }

    T best = DP[1][n - 1];
    for (int final_stepsize = 1; final_stepsize < n; ++final_stepsize)
    {
        best = max(best, DP[final_stepsize][n - 1]);
    }

    cout << best << endl;

    return 0;
}
