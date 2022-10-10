#include <bits/stdc++.h>

using namespace std;


int main()
{
    set<int> products;
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        for (int lo = 1; lo < digits.size() - 2; ++lo) {
            for (int hi = lo + 1; hi < digits.size() - 1; ++hi) {
                int a = 0, b = 0, c = 0;
                for (int i = 0; i < lo; ++i) {
                    a += digits[i] * pow(10, lo - i - 1);
                }
                for (int i = lo; i < hi; ++i) {
                    b += digits[i] * pow(10, hi - i - 1);
                }
                for (int i = hi; i < digits.size(); ++i) {
                    c += digits[i] * pow(10, digits.size() - i - 1);
                }

                if (a * b == c) {
                    products.insert(c);
                }
            }
        }
    } while (next_permutation(digits.begin(), digits.end()));

    int result = 0;
    for (int c : products) {
        result += c;
    }
    printf("%d\n", result);
}