#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int tree[MAX]; // initialize: set to 0

// PRE: i < MAX
// RESULT: SUM_j=0 to i (A[j])
// RT: O(log i)
int read(int i = 0) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        // (i & -i) = 0...010...0 with 1 on location
        // of least significant bit of i
        i -= (i & -i);
    }
    return sum;
}

// PRE: i < MAX
// POST: A[i] is increased by v
// RT: O(log i)
void update(int i, int v) {
    while (i <= MAX) {
        tree[i] += v;
        i += (i & -i);
    }
}

// Get largest value with cumsum <= to x;
// for smallest, pass x-1 and add 1 to result
int getind(int x) {
    int idx = 0, mask = MAX;
    while(mask && idx < MAX) {
        int t = idx + mask;
        if (x >= tree[t]) {
            idx = t; x -= tree[t];
        }
        mask >>= 1;
    }
    return idx;
}

int main() {
    return 0;
}