#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> V(N, 0);
    int i = 0;
    while (M--)
    {
        ++V[i];

        i = (i + 1) % N;
    }

    for (int &v : V)
    {
        for (int i = 0; i < v; ++i)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}