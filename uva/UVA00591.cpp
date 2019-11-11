#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define loop(i, n) for (int i = 0; i < n; i++)
// todo: hand in
int main() {
    int n;
    int cases = 1;
    while (cin >> n) {
        if (n == 0) break;
        vi bricks(n);
        int sum = 0;
        loop(i, n) {
            cin >> bricks[i];
            sum += bricks[i];
        }

        int avg = sum / n;
        int move = 0;
        loop(i, n) {
            if (bricks[i] > avg) move += bricks[i] - avg;
        }
        printf("Set #%d\n", cases);
        printf("The minimum number of moves is %d.\n\n", move);
        cases++;
    }
    return 0;
}