#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

T mod = 1000000007;

T createPalindrome(T const &input)
{
	T n = input;
	T base = 10;
	T palin = input;

	n /= base;

	while (n > 0)
	{
		palin = palin * base + (n % base);
		n /= base;
	}

	return palin;
}

T modpow(T &a, T &b)
{
	T result = 1;
	a %= mod;

	if (a == 0)
		return 0;

	while (b)
	{
		if (b & 1)
		{
			result = (result * a) % mod;
		}

		b >>= 1;
		a = (a * a) % mod;
	}

	return result;
}

void solve()
{
	T L, R;

	cin >> L >> R;

	T base = createPalindrome(L);
	T exp = 0;

	for (int i = L + 1; i <= R; ++i)
	{
		exp += createPalindrome(i);
	}

	cout << modpow(base, exp) << endl;
}

int main()
{
	T Q;

	cin >> Q;

	while (Q--)
	{
		solve();
	}

	return 0;
}