#include <bits/stdc++.h>

using namespace std;

int main()
{
    int CAP, n_stations;
    cin >> CAP >> n_stations;

    int current = 0;
    for (int i = 0; i < n_stations; ++i)
    {
        int out, in, stay;
        cin >> out >> in >> stay;

        current -= out;
        if (current < 0)
        {
            cout << "impossible" << endl;
            return 0;
        }

        current += in;
        if (current > CAP)
        {
            cout << "impossible" << endl;
            return 0;
        }

        if (current != CAP && stay > 0)
        {
            cout << "impossible" << endl;
            return 0;
        }
    }

    if (current > 0)
    {
        cout << "impossible" << endl;
        return 0;
    }

    cout << "possible" << endl;

    return 0;
}