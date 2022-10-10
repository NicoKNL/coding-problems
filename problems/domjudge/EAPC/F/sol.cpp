
#include <iostream>

using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;

    double xp = (100 - x) / (100 - y) * y;
    cout.precision(20);
    cout << x / xp << endl;

    return 0;
}