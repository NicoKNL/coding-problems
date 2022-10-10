#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int gnomes;
        cin >> gnomes;

        vector<int> V(gnomes, 0);
        for (int i = 0; i < gnomes; ++i)
            cin >> V[i];

        for (int i = 1; i < gnomes - 1; ++i)
        {
            if (V[i] - V[i - 1] != 1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}