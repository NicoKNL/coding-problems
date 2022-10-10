#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<vector<int>, int> M;

    int most_popular_count = 0;

    for (int i = 0; i < n; ++i)
    {
        vector<int> courses(5, 0);
        for (int ii = 0; ii < 5; ++ii)
            cin >> courses[ii];

        sort(courses.begin(), courses.end());

        ++M[courses];

        if (M[courses] > most_popular_count)
        {
            most_popular_count = M[courses];
        }
    }

    int total = 0;
    for (auto each : M)
    {
        if (each.second == most_popular_count)
            total += most_popular_count;
    }

    cout << total << endl;

    return 0;
}