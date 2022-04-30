#include <bits/stdc++.h>

using namespace std;

bool canBePicked(const vector<vector<int>> &V, int r, int c)
{
    // Check above - cannot block diagonally
    if (r > 0)
        if (V[r - 1][1 - c] == INT32_MAX)
            return false;

    // Check side - cannot block full row
    if (V[r][1 - c] == INT32_MAX)
        return false;

    // Check below -- cannot block diagnoally
    if (r < V.size() - 1)
        if (V[r + 1][1 - c] == INT32_MAX)
            return false;

    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> V(n, vector<int>(2));

    for (int i = 0; i < n; ++i)
        cin >> V[i][0] >> V[i][1];

    for (int i = 0; i < k; ++i)
    {
        int best_row;
        int best_col;
        int best_val = INT32_MAX;

        for (int r = 0; r < n; ++r)
            for (int c = 0; c < 2; ++c)
                if (canBePicked(V, r, c))
                    if (V[r][c] < best_val)
                    {
                        best_val = V[r][c];
                        best_row = r;
                        best_col = c;
                    }

        V[best_row][best_col] = INT32_MAX;
    }

    int value = 0;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < 2; ++c)
            if (V[r][c] != INT32_MAX)
                value += V[r][c];

    cout << value << endl;

    return 0;
}