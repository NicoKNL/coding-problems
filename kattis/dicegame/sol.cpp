#include <bits/stdc++.h>

using namespace std;

double expectedValue(int lo, int hi)
{
    int count = hi - lo + 1;
    int sum = 0;

    for (int i = lo; i <= hi; ++i)
    {
        sum += i;
    }

    return (double)sum / (double)count;
}

int main()
{
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int c1, d1, c2, d2;
    cin >> c1 >> d1 >> c2 >> d2;

    double ev_gunnar = expectedValue(a1, b1) + expectedValue(a2, b2);
    double ev_emma = expectedValue(c1, d1) + expectedValue(c2, d2);

    if (ev_gunnar > ev_emma)
        cout << "Gunnar" << endl;
    else if (ev_gunnar < ev_emma)
        cout << "Emma" << endl;
    else
        cout << "Tie" << endl;

    return 0;
}