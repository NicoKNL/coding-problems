#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int k;
        cin >> k;

        vector<int> V(k, 0);

        for (int i = 0; i < k; ++i)
        {
            cin >> V[i];
        }

        int score = accumulate(V.begin(), V.end(), 0) - (V.size() - 1);
        cout << score << endl;
    }
    return 0;
}