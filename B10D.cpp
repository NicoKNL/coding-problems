#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void oneRun()
{
    int n;
    cin >> n;
    int ropes = 0;
    ropes += n / 2; // All ropes that connect from m to 2*m where n/2 < m <= n;

    if (n % 2 == 1) {
        ropes += 2; // +2 because n is odd
        n--;
    }

    int lowest_fitting_odd = (n - 1) / 3;
    ropes += (n - lowest_fitting_odd) / 2;
    cout << ropes << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}