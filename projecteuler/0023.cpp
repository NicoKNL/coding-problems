#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> abundant_numbers;
    for (int i = 0; i <= 28123; ++i) {
        int sum = 0;
        for (int j = 1; j <= i / 2; ++j) {
            if (i % j == 0) sum += j;
        }
        if (sum > i) abundant_numbers.insert(i);
    }

    unsigned long long result = 0;
    unsigned long long maximum = 28123 * (28123 + 1) / 2;
    for (int i = 1; i <= 28123; ++i) {
        for (int a : abundant_numbers) {
            if (a > i) break;
            if (abundant_numbers.find(i - a) != abundant_numbers.end()) {
                result += i;
                break;
            }
        }
    }
    cout << maximum  - result << endl;
}
