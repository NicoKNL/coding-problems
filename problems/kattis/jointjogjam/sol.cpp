#include <bits/stdc++.h>

using namespace std;

struct vec2
{
    double x, y;
};

double dist(vec2 a, vec2 b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    fixed(cout);
    cout.precision(10);

    vec2 k_start, o_start, k_end, o_end;
    cin >> k_start.x >> k_start.y;
    cin >> o_start.x >> o_start.y;
    cin >> k_end.x >> k_end.y;
    cin >> o_end.x >> o_end.y;

    vector<double> distances =
        {
            dist(k_start, o_start),
            dist(k_end, o_end),
        };

    cout << *max_element(distances.begin(), distances.end()) << endl;

    return 0;
}