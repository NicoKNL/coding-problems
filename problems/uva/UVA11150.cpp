#include <bits/stdc++.h>

using namespace std;

struct solution {
    int total, empty;
};

solution solve(int coke, int empty) {
    int total = 0;
    while (empty >= 3 || coke > 0) {
        total += coke;
        empty += coke;
        coke = (empty / 3);
        empty -= coke * 3;
    }
    return {total, empty};

}

int main() {
    int n;
    while (cin >> n) {
        solution a = solve(n, 0);
        solution b = solve(n, 1);
        solution c = solve(n, 2);
        int opt = a.total;
        if (b.total > opt && b.empty >= 1) {
            opt = b.total;
        }
        if (c.total > opt && c.empty >= 2) {
            opt = c.total;
        }
        cout << opt << endl;
    }
    return 0;
}