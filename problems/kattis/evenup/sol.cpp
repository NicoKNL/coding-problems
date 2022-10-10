#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n);
    int it = 0;
    int elements = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> V[it];
        ++elements;

        if (it > 0)
        {
            if ((V[it - 1] & 1) == (V[it] & 1))
            {
                --it;
                elements -= 2;
            }
            else
                ++it;
        }
        else
            ++it;
    }

    cout << elements << endl;

    return 0;
}