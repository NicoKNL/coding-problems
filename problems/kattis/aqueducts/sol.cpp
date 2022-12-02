#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>

using namespace std;

struct Pt
{
    double x, y, z;
};

double get_dist(const Pt &a, const Pt &b)
{
    return sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0) + pow(a.z - b.z, 2.0));
}

const int HILL = 0;
const int TOWN = 1;
const int SPRING = 2;
const int INF = 1e9;

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
    T INF = 1e9; // TODO: update your INF here!
    int n = A.size() - 1, m = A[0].size() - 1;
    vector<T> pot_row(n + 1), pot_col(m + 1);
    vector<int> pairing(m + 1), way(m + 1);

    for (int row = 1; row <= n; ++row)
    {
        pairing[0] = row;
        int cur_col = 0;
        vector<T> min_pot(m + 1, INF);
        vector<char> used(m + 1, false);
        do
        {
            used[cur_col] = true;
            int current_row_match = pairing[cur_col];
            int col_with_min;
            T delta = INF;

            for (int col = 1; col <= m; ++col)
            {
                if (!used[col])
                {
                    T pot = A[current_row_match][col] - pot_row[current_row_match] - pot_col[col];

                    if (pot < min_pot[col])
                    {
                        min_pot[col] = pot;
                        way[col] = cur_col;
                    }
                    if (min_pot[col] < delta)
                    {
                        delta = min_pot[col];
                        col_with_min = col;
                    }
                }
            }
            for (int col = 0; col <= m; ++col)
                if (used[col])
                    pot_row[pairing[col]] += delta, pot_col[col] -= delta;
                else
                    min_pot[col] -= delta;
            cur_col = col_with_min;
        } while (pairing[cur_col] != 0);

        do
        {
            int col_with_min = way[cur_col];
            pairing[cur_col] = pairing[col_with_min];
            cur_col = col_with_min;
        } while (cur_col);
    }

    vector<pair<int, int>> result;
    for (int col = 1; col <= m; ++col)
        result.push_back(make_pair(pairing[col], col));

    return {-pot_col[0], result};
}

int main()
{
    fixed(cout);
    cout.precision(8);

    // Process inputs
    int n_hills, s_springs, t_towns;
    double max_len;
    cin >> n_hills >> s_springs >> t_towns >> max_len;

    // Check if there are not enough springs for the number of towns
    // according to the assignment every spring can only supply one town
    if (t_towns > s_springs)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Parse hills
    vector<Pt> hills(n_hills);
    for (int i = 0; i < n_hills; ++i)
        cin >> hills[i].x >> hills[i].y >> hills[i].z;

    // Parse hill types
    vector<int> hilltype(n_hills, HILL);
    for (int i = 0; i < s_springs; ++i)
    {
        int h;
        cin >> h;
        hilltype[h - 1] = SPRING;
    }

    for (int i = 0; i < t_towns; ++i)
    {
        int h;
        cin >> h;
        hilltype[h - 1] = TOWN;
    }

    // Compute the initial distances between hills
    vector<vector<double>> dist(n_hills, vector<double>(n_hills, INF));
    for (int u = 0; u < n_hills; ++u)
        dist[u][u] = 0.0;

    for (int u = 0; u < n_hills; ++u)
    {
        for (int v = 0; v < n_hills; ++v)
        {
            if (u == v)
                continue;

            if (hills[v].z >= hills[u].z)
                continue;

            double d = get_dist(hills[u], hills[v]);
            if (d <= max_len)
                dist[u][v] = d;
        }
    }

    // Perform all pairs shortests paths
    for (int k = 0; k < n_hills; k++)
        for (int i = 0; i < n_hills; i++)
            for (int j = 0; j < n_hills; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // Test if assignment is possible
    // At this point we know that s_springs >= t_towns
    // Thus there must be at least t_towns reachable from at least t number of springs
    // Otherwise there is no mapping possible: e.g. 1 spring reaches 2 towns and neither of those 2 towns has another spring reaching them
    set<int> springs_reachable_from_towns;
    set<int> towns_reachable_from_springs;
    for (int town = 0; town < n_hills; ++town)
    {
        if (hilltype[town] != TOWN)
            continue;

        for (int spring = 0; spring < n_hills; ++spring)
        {
            if (hilltype[spring] != SPRING)
                continue;

            if (dist[spring][town] < INF)
            {
                springs_reachable_from_towns.insert(spring);
                towns_reachable_from_springs.insert(town);
            }
        }
    }

    if (springs_reachable_from_towns.size() < t_towns || towns_reachable_from_springs.size() < t_towns)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Assign labels to springs and towns
    unordered_map<int, int> spring_ids;
    unordered_map<int, int> town_ids_rev;
    int SID = 1;
    int TID = 1;
    for (int i = 0; i < n_hills; ++i)
    {
        if (hilltype[i] == SPRING)
        {
            for (int town = 0; town < n_hills; ++town)
            {
                if (hilltype[town] == TOWN && dist[i][town] < INF)
                {
                    spring_ids[SID] = i;
                    ++SID;
                    break;
                }
            }
        }

        if (hilltype[i] == TOWN)
        {
            town_ids_rev[i] = TID;
            ++TID;
        }
    }

    // Fill the assignment matrix
    vector<vector<double>> A(TID, vector<double>(SID, 0.0));
    for (auto [sid, spring] : spring_ids)
    {
        for (int town = 0; town < n_hills; ++town)
        {
            if (hilltype[town] != TOWN)
                continue;

            int tid = town_ids_rev[town];
            A[tid][sid] = dist[spring][town];
        }
    }

    auto [min_cost, pairs] = hungarian(A);

    cout << min_cost << endl;

    return 0;
}