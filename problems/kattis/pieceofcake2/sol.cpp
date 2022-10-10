#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, h, v;
    cin >> n >> h >> v;

    h = max(h, n - h);
    v = max(v, n - v);

    cout << h * v * 4 << endl;

    return 0;
}