#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct Number
{
    long long value;
    long long count;
    long long index;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long C;
    cin >> N >> C;

    unordered_map<long long, Number> M;

    for (long long i = 0; i < N; ++i)
    {
        long long v;
        cin >> v;

        if (M.find(v) == M.end())
        {
            M[v] = {v, 1, i};
        }
        else
        {
            ++M[v].count;
        }
    }

    vector<Number> V;
    for (auto each : M)
    {
        V.push_back(each.second);
    }

    sort(V.begin(), V.end(),
         [](const Number &lhs, const Number &rhs)
         {
             if (lhs.count > rhs.count)
             {
                 return true;
             }
             else if (lhs.count == rhs.count && lhs.index < rhs.index)
             {
                 return true;
             }
             else
             {
                 return false;
             }
         });

    bool first = true;
    for (long long i = 0; i < V.size(); ++i)
    {
        if (V[i].count > 0)
        {
            for (long long ii = 0; ii < V[i].count; ++ii)
            {
                if (first)
                {
                    first = false;
                }
                else
                {
                    cout << " ";
                }
                cout << V[i].value;
            }
        }
    }
    cout << '\n';
}