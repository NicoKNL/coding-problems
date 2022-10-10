#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> V(N);
    unordered_set<long long> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
        S.insert(V[i]);
    }

    if (S.size() < 2)
    {
        cout << "impossible" << endl;
    }
    else if (S.size() < 3 && V.size() < 3)
    {
        cout << "impossible" << endl;
    }
    else
    {
        sort(V.begin(), V.end());

        int b;
        long long needle = V[0];

        for (int i = 1; i < V.size(); ++i)
        {
            if (V[i] != needle)
            {
                b = i;
                break;
            }
        }

        swap(V[0], V[b]);

        for (auto each : V)
        {
            cout << each << endl;
        }
    }

    return 0;
}