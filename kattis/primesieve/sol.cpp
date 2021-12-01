#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p)
    {
        if (is_prime[p])
        {
            for (int i = 2 * p; i <= n; i += p)
            {
                is_prime[i] = false;
            }
        }
    }

    int count = accumulate(is_prime.begin(), is_prime.end(), 0);
    cout << count << endl;

    int q;
    cin >> q;

    while (q--)
    {
        int p;
        cin >> p;
        cout << is_prime[p] << endl;
    }
}