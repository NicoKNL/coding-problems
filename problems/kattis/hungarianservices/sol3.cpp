#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

/**
 * Kuhn-Munkres / Hungarian
 *
 * GIVEN a n * m cost matrix A (limit: ~40x40)
 * WHERE n <= m (!!!)
 * AND form of matrix equals:
 *  0   0   0   0 <-- row 0 and col 0 is padding for data
 *  0  INF  3   2 <-- costs of matching i to j
 *  0   4  INF  8
 *  0   3   3  INF
 * RETURNS the minimal cost matching between n and m
 * AND the pairs which were matched
 *
 * Note: A can have negative edge weights and T in {double, int-like}
 */
template <class T>
pair<T, vector<pair<int, int>>> hungarian(const vector<vector<T>> &A)
{
    T INF = 1000 * 1000 * 1000; // TODO: update your INF here!
    int n = A.size() - 1, m = A[0].size() - 1;
    vector<T> pot_row(n + 1), pot_col(m + 1);
    vector<int> pairing(m + 1), way(m + 1);

    for (int row = 1; row <= n; ++row)
    {
        pairing[0] = row;
        int cur_col = 0;
        vector<T> max_pot(m + 1, -INF);
        vector<char> used(m + 1, false);
        do
        {
            used[cur_col] = true;
            int current_row_match = pairing[cur_col];
            int col_with_max;
            T delta = INF;

            for (int col = 1; col <= m; ++col)
            {
                if (!used[col])
                {
                    T pot = A[current_row_match][col] + pot_row[current_row_match] + pot_col[col];

                    if (pot > max_pot[col])
                    {
                        max_pot[col] = pot;
                        way[col] = cur_col;
                    }
                    if (max_pot[col] > delta)
                    {
                        delta = max_pot[col];
                        col_with_max = col;
                    }
                }
            }
            for (int col = 0; col <= m; ++col)
                if (used[col])
                    pot_row[pairing[col]] -= delta, pot_col[col] += delta;
                else
                    max_pot[col] += delta;
            cur_col = col_with_max;
        } while (pairing[cur_col] != 0);

        do
        {
            int col_with_max = way[cur_col];
            pairing[cur_col] = pairing[col_with_max];
            cur_col = col_with_max;
        } while (cur_col);
    }

    vector<pair<int, int>> result;
    for (int col = 1; col <= m; ++col)
        result.push_back(make_pair(pairing[col], col));

    return {-pot_col[0], result};
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    int INF = 1000 * 1000 * 1000;
    int s = max(n, m);
    vector<vector<long long>> M(s + 1, vector<long long>(s + 1, -INF));
    for (int i = 0; i < s + 1; ++i)
    {
        M[i][i] = -INF;
        M[0][i] = 0;
        M[i][0] = 0;
    }

    for (int i = 0; i < r; ++i)
    {
        int u, v, value;
        cin >> u >> v >> value;
        M[u][v] = -value;
    }

    pair<int, vector<pair<int, int>>> result = hungarian(M);
    cout << result.first << endl;
    int answer = 0;
    int unmatched = 0;
    for (auto &each : result.second)
    {
        int edge_weight = M[each.first][each.second];
        if (edge_weight == 0)
        {
            unmatched += 1;
        }
        else
        {
            answer -= edge_weight;
        }
        cout << each.first << " , " << each.second << endl;
    }

    cout << unmatched << " " << answer << endl;
}
