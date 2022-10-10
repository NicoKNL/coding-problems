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

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        vector<int> V = parseInput();
    }

    int a = 2;
    int b = 6;
    cout << (a & b) << endl;

    return 0;
}