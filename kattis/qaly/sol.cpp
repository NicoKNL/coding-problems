#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.precision(20);

    int N;
    cin >> N;

    double qaly = 0.0;
    while (N--)
    {
        double q, y;
        cin >> q >> y;
        qaly += q * y;
    }

    cout << qaly << endl;

    return 0;
}