#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    fixed(cout);
    cout.precision(4);
    while (n--)
    {
        double b, p;
        cin >> b >> p;

        double lower = 60.0 * (b - 1) / p;
        double bpm = 60.0 * b / p;
        double upper = 60.0 * (b + 1) / p;
        cout << lower << " " << bpm << " " << upper << endl;
    }

    return 0;
}