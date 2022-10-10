#include <bits/stdc++.h>

typedef long long T;
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cout.precision(20);

    T x, y, r;
    cin >> x >> y >> r;

    T xmin = x - r;
    T xmax = x + r;
    T ymin = y - r;
    T ymax = y + r;

    cout << xmin << " " << ymax << endl;
    cout << xmax << " " << ymax << endl;
    cout << xmax << " " << ymin << endl;
    cout << xmin << " " << ymin << endl;

    return 0;
}
