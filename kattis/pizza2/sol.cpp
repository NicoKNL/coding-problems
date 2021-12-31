#include <bits/stdc++.h>

using namespace std;

double circleArea(double radius)
{
    return M_PI * radius * radius;
}

int main()
{
    fixed(cout);
    cout.precision(10);

    int R, C;
    cin >> R >> C;

    double total_area = circleArea(R);
    double cheese_area = circleArea(R - C);
    double percent = cheese_area / total_area * 100.0;

    cout << percent << endl;

    return 0;
}