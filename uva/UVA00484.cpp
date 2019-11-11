#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> counter;
    vector<int> distinct;
    int n;
    while (cin >> n) {
        if (n == -666666) break;
        if (counter.find(n) != counter.end()) {
            counter[n]++;
        } else {
            counter[n] = 1;
            distinct.push_back(n);
        }
    }

    for (int i : distinct) {
        printf("%d %d\n", i, counter[i]);
    }
    return 0;
}