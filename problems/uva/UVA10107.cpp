#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, median, nth;
    vector<int> v = {};
    while (cin >> n) {
        v.push_back(n);
        nth = v.size() / 2;
        if (v.size() % 2 == 0) {
            nth_element(v.begin(), v.begin() + nth - 1, v.end());
            median = v.at(nth - 1);
            nth_element(v.begin(), v.begin() + nth, v.end());
            median += v.at(nth);
            median /= 2;
        } else {
            nth_element(v.begin(), v.begin() + nth, v.end());
            median = v.at(nth);
        }
        cout << median << endl;
    }
}