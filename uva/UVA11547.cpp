#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--) {
        double answer = 0.0;
        long int i_answer = 0;
        cin >> n;
        answer = floor((((n * 567.0 / 9.0) + 7492.0) * 235.0 / 47.0) - 498.0);
        i_answer = ((long int) answer % 100) / 10;
        cout << abs(i_answer) << endl;
    }

    return 0;
}