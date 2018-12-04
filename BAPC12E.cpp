#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void oneRun()
{
    string s;
    cin >> s;

    int side_length = sqrt(s.length()); // of square
    int row = 0;
    int column = side_length - 1;

    string result = "";
    while (column >= 0) {
        result.push_back(s.at(column + row * side_length));
        row++;
        if (row == side_length) {
            row = 0;
            column--;
        }
    }
    cout << result << endl;

}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}