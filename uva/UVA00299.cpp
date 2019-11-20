#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        vi carriages(c);
        loop(i, c) cin >> carriages[i];
        int count = 0;
        loop(i, c) {
            if (carriages[i] != i + 1) {
                for (int j = i + 1; j < c; j++) {
                    if (carriages[j] == i + 1) {
                        while (carriages[i] != i + 1) {
                            count++;
                            swap(carriages[j], carriages[j-1]);
                            j--;
                        }
                    }
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}