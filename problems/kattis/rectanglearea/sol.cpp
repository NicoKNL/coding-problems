#include <iostream>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double area = abs(x1 - x2) * abs(y1 - y2);
    cout.precision(10);
    cout << area << endl;
}