#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> V;
    while (cin >> n)
    {
        cout << "n < " << n << endl;
        V.push_back(n);
    }

    for (int day = 1; day <= 80; ++day)
    {
        vector<int> append;
        for (int i = 0; i < V.size(); ++i)
        {
            if (V[i] == 0)
            {
                V[i] = 6;
                append.push_back(8);
            }
            else
            {
                --V[i];
            }
        }

        V.insert(V.end(), append.begin(), append.end());
    }

    cout << V.size() << endl;

    return 0;
}