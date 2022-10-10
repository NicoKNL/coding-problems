#include <bits/stdc++.h>

using namespace std;
// todo: close, but tricky to understand problem on 2nd testcase
int main() {
    int n;
    cin >> n;
    map<char, int> count;
    vector<string> s(n);
    vector<int> digit_order(10);
    for (int i = 0; i < 10; i++) {
        digit_order[i] = -1;
    }

    long long k = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            if (count.find(s[i].at(j)) != count.end()) {
                count[s[i].at(j)]++;
            } else {
                count[s[i].at(j)] = 1;
            }
            if (digit_order[s[i].at(j) - '0'] == -1) {
                digit_order[s[i].at(j) - '0'] = k;
            }
            k++;
        }
    }


    vector<pair<int, char>> result(count.size());
    int i = 0;
    for (auto entry: count) {
        result[i] = make_pair(entry.second, entry.first);
        i++;
    }

    sort(result.begin(), result.end(), greater<pair<int, char>>());

    for (int i = 0; i < result.size(); i++) {
        auto entry = result[i];
        for (int j = i; j < result.size(); j++) {
            auto entry_b = result[j];
            if (entry.first == entry_b.first) {
                if (digit_order[entry.second - '0'] > digit_order[entry_b.second - '0']) {
                    result[j] = entry;
                    result[i] = entry_b;
                }
            }
        }
    }

    map<char, int> key;
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
        for (int j = 0; j < s[i].size(); j++) {
            sum += key[s[i].at(j)];
        }
        cout << sum << endl;
    }
    return 0;
}

//24
//1 75 2 1 1 75 75 75 75 75 75 2 2 3 4 5 6 7 8 9 10 11 12 10