#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

unordered_map<string, bool> m;
vi digits;
vi sol;
vvi sums;
int counter;

int N, T;

void evalSol() {
    string s;
    int sum = 0;
    for (int x : sol) {
        sum += x;
        s += to_string(x);
    }

    if (sum == T && m.find(s) == m.end()) {
        counter++;
        m[s] = true;
        sums.push_back(sol);
    }
}

void solve(int i, int choose, int out_of) {
    if (choose == 0) {
        evalSol();
        return;
    } else if (i >= N) {
        return;
    }

    sol[out_of - choose] = digits[i];
    solve(i + 1, choose - 1, out_of);
    solve(i + 1, choose, out_of);
}

int main() {
    while (cin >> T >> N) {
        if (T == 0 && N == 0) break;
        digits.assign(N, 0);
        loop(i, N) cin >> digits[i];

        while (digits.size() > 0 && digits[0] > T) {
            digits.erase(digits.begin());
            N--;
        }

        sums = vvi();
        m = unordered_map<string, bool>();

        counter = 0;
        printf("Sums of %d:\n", T);
        for (int choose = 1; choose <= N; choose++) {
            sol.assign(choose, 0);
            solve(0, choose, choose);
        }
        if (counter == 0) {
            printf("NONE\n");
        } else {
            sort(sums.begin(), sums.end(), greater<vi>());
            for (vi sum : sums) {
                for (int i = 0; i < sum.size(); i++) {
                    if (i > 0) cout << "+";
                    cout << sum[i];
                }
                cout << endl;
            }

        }
    }
    return 0;
}