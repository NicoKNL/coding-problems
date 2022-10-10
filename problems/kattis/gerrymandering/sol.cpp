#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    int precincts, districts;
    cin >> precincts >> districts;

    vector<pair<int, int>> D(districts + 1, {0, 0});

    while (precincts--)
    {
        int district, A, B;
        cin >> district >> A >> B;

        D[district].first += A;
        D[district].second += B;
    }

    double total_votes = 0;
    double total_wasted_A = 0;
    double total_wasted_B = 0;
    for (int i = 1; i < districts + 1; ++i)
    {
        total_votes += D[i].first;
        total_votes += D[i].second;

        int needed = (int)(floor((double)(D[i].first + D[i].second) / 2.0) + 1.0);
        if (D[i].first > D[i].second)
        {
            total_wasted_A += D[i].first - needed;
            total_wasted_B += D[i].second;
            cout << "A " << D[i].first - needed << " " << D[i].second << endl;
        }
        else
        {
            total_wasted_A += D[i].first;
            total_wasted_B += D[i].second - needed;
            cout << "B " << D[i].first << " " << D[i].second - needed << endl;
        }
    }

    cout << abs(total_wasted_A - total_wasted_B) / total_votes << endl;

    return 0;
}