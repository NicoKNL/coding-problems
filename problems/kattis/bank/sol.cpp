#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;

    vector<vector<int>> V(T + 1, vector<int>());
    while (N--)
    {
        int value, t;
        cin >> value >> t;

        V[t].push_back(value);
    }

    int cash = 0;

    priority_queue<int> Q;

    for (int i = T - 1; i >= 0; --i)
    {
        for (int each : V[i])
            Q.push(each);

        if (!Q.empty())
        {
            cash += Q.top();
            Q.pop();
        }
    }

    cout << cash << endl;

    return 0;
}