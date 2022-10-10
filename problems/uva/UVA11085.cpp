#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define loop(i, n) for (int i = 0; i < n; i++)

void backtrack(int c, vi & sol, vvi & solutions) {
    if (c == 8) solutions.push_back(sol);
    else if (c == 0) {
        loop(i, 8) {
            sol[c] = i;
            backtrack(c+1, sol, solutions);
        }
    } else {
        loop(i, 8) {
            sol[c] = i; bool valid = true;
            loop(j, c) {
                if (sol[j] == i) valid = false;
                if (abs(j - c) == abs(sol[j] - sol[c])) valid = false;
            }
            if (valid) backtrack(c+1, sol, solutions);
        }
    }
}

int main() {
    vvi solutions;
    vi sol(8);
    backtrack(0, sol, solutions);

    int tmp;
    int cases = 1;
    while (cin >> tmp) {
        vi queens(8);
        queens[0] = tmp - 1;
        loop(i, 7) {
            cin >> queens[i+1];
            queens[i+1] = queens[i+1] - 1;
        }

        int diff;
        int min_diff = INT_MAX;
        loop(i, 92) {
            vi sol = solutions[i];
            diff = 0;
            loop(j, 8) if(sol[j]!=queens[j]) diff++;;
            min_diff = min(min_diff, diff);
        }
        printf("Case %d: %d\n", cases, min_diff);
        cases++;
    }
    return 0;
}