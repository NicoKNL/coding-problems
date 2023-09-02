#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

template <class T>
bool ckmin(T &a, const T &b)
{
    return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b)
{
    return a < b ? a = b, 1 : 0;
}

template <class T>
vector<T> hungarian(const vector<vector<T>> &C)
{
    const int J = (int)size(C), W = (int)size(C[0]);
    assert(J <= W);
    /// job[w] = job assigned to w-th worker, or -1 if no job assigned
    /// note: a W-th worker was added for convenience
    vector<int> job(W + 1, -1);
    vector<T> ys(J), yt(W + 1); /// potentials
    /// -yt[W] will equal the sum of all deltas
    vector<T> answers;
    const T inf = numeric_limits<T>::min();
    for (int j_cur = 0; j_cur < J; ++j_cur)
    { /// assign j_cur-th job
        int w_cur = W;
        job[w_cur] = j_cur;
        /// min reduced cost over edges from Z to worker w
        vector<T> min_to(W + 1, inf);
        vector<int> prv(W + 1, -1); /// previous worker on alternating path
        vector<bool> in_Z(W + 1);   /// whether worker is in Z
        while (job[w_cur] != -1)
        { /// runs at most j_cur + 1 times
            in_Z[w_cur] = true;
            const int j = job[w_cur];
            T delta = inf;
            int w_next;
            for (int w = 0; w < W; ++w)
            {
                if (!in_Z[w])
                {
                    if (ckmin(min_to[w], C[j][w] - ys[j] - yt[w]))
                        prv[w] = w_cur;
                    if (ckmin(delta, min_to[w]))
                        w_next = w;
                }
            }
            /// delta will always be non-negative,
            /// except possibly during the first time this loop runs
            /// if any entries of C[j_cur] are negative
            for (int w = 0; w <= W; ++w)
            {
                if (in_Z[w])
                    ys[job[w]] += delta, yt[w] -= delta;
                else
                    min_to[w] -= delta;
            }
            w_cur = w_next;
        }
        /// update assignments along alternating path
        for (int w; w_cur != -1; w_cur = w)
            job[w_cur] = job[w = prv[w_cur]];
        answers.push_back(-yt[W]);
    }
    return answers;
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    const long long INF = numeric_limits<long long>::min();
    int s = max(n, m);
    vector<vector<long long>> M(s + 1, vector<long long>(s + 1, INF));
    for (int i = 0; i < s + 1; ++i)
    {
        M[i][i] = INF;
        M[0][i] = 0;
        M[i][0] = 0;
    }

    for (int i = 0; i < r; ++i)
    {
        int u, v, value;
        cin >> u >> v >> value;
        M[u][v] = -value;
    }

    vector<long long> result = hungarian(M);
    // cout << result.first << endl;
    int answer = 0;
    int unmatched = 0;
    for (auto &each : result)
    {
        cout << "i " << each << endl;
        // int edge_weight = M[each.first][each.second];
        // if (edge_weight == 0)
        // {
        // unmatched += 1;
        // }
        // else
        // {
        // answer -= edge_weight;
        // }
        // cout << each.first << " , " << each.second << endl;
    }

    // cout << unmatched << " " << answer << endl;
}
