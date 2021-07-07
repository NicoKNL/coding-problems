#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int d, z, x, y;
	cin >> d >> x >> y >> z;

	int strat1 = 7 * x;
	int strat2 = d * y + (7 - d) * z;

	cout << max(strat1, strat2) << endl;
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