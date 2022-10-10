#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

void solve()
{
	T N, K;
	cin >> N >> K;

	unordered_map<T, T> M;

	for (int i = 0; i < N; ++i)
	{
		int A;
		int p = 0;

		cin >> A;
		while (A)
		{
			if (A & 1)
				++M[p];

			A = A >> 1;
			++p;
		}
	}

	int result = 0;

	for (auto &each : M)
	{
		T count = each.second;

		result += count / K;
		count -= (count / K) * K;
		if (count)
			++result;
	}

	cout << result << endl;
}

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		solve();
	}

	return 0;
}