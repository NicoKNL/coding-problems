#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

vector<T> PALINDROMES{0};
vector<T> SUM{0};

T mod = 1000000007;

T createPalindrome(T input)
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

void initializePalindromes()
{
	int i = 1;
	while (i <= 100000)
	{
		PALINDROMES.push_back(createPalindrome(i));
		++i;
	}
}

void initializeSum()
{
	int i = 1;
	while (i <= 100000)
	{
		SUM.push_back(SUM[i - 1] + PALINDROMES[i]);
		++i;
	}
}

T modpow(T a, T b)
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

	T base = PALINDROMES[L];
	T exp = SUM[R] - SUM[L];

	cout << modpow(base, exp) << endl;
}

int main()
{
	initializePalindromes();
	// for_each(PALINDROMES.begin(), PALINDROMES.begin() + 500, [](T const &p)
	// 		 { cout << p << endl; });
	initializeSum();

	T Q;

	cin >> Q;

	while (Q--)
	{
		solve();
	}

	return 0;
}