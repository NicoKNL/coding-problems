#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long T;

void solve()
{
	T g, c;
	cin >> g >> c;

	cout << (c * c) / (2 * g) << endl;
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