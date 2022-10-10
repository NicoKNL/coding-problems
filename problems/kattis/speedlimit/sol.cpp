#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while (true)
    {
        cin >> n;
        if (n == -1)
            break;

        int prev_t = 0;
        int result = 0;

        for (int i = 0; i < n; ++i)
        {
            int v, t;
            cin >> v >> t;

            result += (t - prev_t) * v;
            prev_t = t;
        }

        cout << result << " miles" << endl;
    }
    return 0;
}