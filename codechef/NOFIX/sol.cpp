#include <bits/stdc++.h>

using namespace std;

vector<int> parseInput()
{
    int n;
    cin >> n;

    vector<int> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    return V;
}

int removeFixpoints(const vector<int> &V)
{
    int index = 1;
    int inserts = 0;

    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i] == index)
        {
            ++index;
            ++inserts;
        }
        ++index;
    }

    return inserts;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        vector<int> V = parseInput();
        int operation_count = removeFixpoints(V);

        cout << operation_count << endl;
    }

    return 0;
}