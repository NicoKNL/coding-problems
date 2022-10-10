#include <bits/stdc++.h>

using namespace std;

vector<int> parseInput()
{
    int n;
    cin >> n;

    vector<int> V(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> V[i];
    }

    return V;
}

vector<int> prefixSum(vector<int> V)
{
    for (int i = 1; i < V.size(); ++i)
        V[i] += V[i - 1];

    return V;
}

int main()
{
    vector<int> V = parseInput();
    int sum = accumulate(V.begin(), V.end(), 0);
    int target;

    if (sum % 3 == 0)
        target = sum / 3;
    else
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> prefix_sum = prefixSum(V);

    vector<int> indices;
    for (int i = 0; i < prefix_sum.size() && indices.size() < 2; ++i)
        if (prefix_sum[i] % target == 0)
            indices.push_back(i + 1);

    if (indices.size() == 2)
        cout << indices[0] << " " << indices[1];
    else
        cout << -1 << endl;

    return 0;
}