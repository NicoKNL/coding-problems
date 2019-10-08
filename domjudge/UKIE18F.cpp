#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> count;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (count.find(s[i]) != count.end()) {
            count[s[i]]++;
        } else {
            count[s[i]] = 1;
        }
    }

    vector<pair<int, int>> result(n);
    for (auto entry: count) {
        result.push_back(make_pair(entry.second, entry.first));
    }

    sort(result.begin(), result.end());
    map<int, int> key;
    int fib = 1;
    int prev_fib = 0;
    int fib_tmp = fib;
    for (auto entry : result) {
        key[entry.second] = fib_tmp;
        fib_tmp--;
        if (fib_tmp == 0) {
            fib_tmp = fib + prev_fib;
            prev_fib = fib;
            fib = fib_tmp;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += key[s[i]];
        cout << sum << endl;
    }
    return 0;
}