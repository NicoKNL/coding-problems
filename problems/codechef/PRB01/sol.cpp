#include <iostream>
#include <vector>

using namespace std;

vector<bool> primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int ii = i * i; ii <= n; ii += i)
            {
                is_prime[ii] = false;
            }
        }
    }

    return is_prime;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    vector<bool> is_prime = primes(100001);

    while (T--)
    {
        int N;
        cin >> N;

        if (is_prime[N])
            cout << "yes\n";
        else
            cout << "no\n";
    }
}