#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &V)
{
    for (int i = 0; i < V.size(); ++i)
    {
        if (i > 0)
            os << " ";
        os << V[i];
    }

    return os;
}

void applySortStep(vector<int> &V)
{
}

int main()
{
    vector<int> V(5, 0);

    for (int i = 0; i < 5; ++i)
        cin >> V[i];

    vector<int> V_sorted = {1, 2, 3, 4, 5};

    while (V != V_sorted)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (V[i] > V[i + 1])
            {
                swap(V[i], V[i + 1]);
                cout << V << endl;
            }
        }
    }

    return 0;
}