#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> coins) {
    int sum = coins[0];
    int count = 1;
    for (int i = 1; i < coins.size() - 1; i++) {
        if (sum + coins[i] < coins[i + 1]) {
            sum += coins[i];
            count++;
        }
    }
    if (sum < coins[coins.size() - 1]) {
        count++;
    }
    printf("%d\n", count);
}

int main() {
    int n, d;
    cin >> n;
    while (n--) {
        cin >> d;
        vector<int> coins(d);

        for (int i = 0; i < d; i++) {
            cin >> coins[i];
        }

        solve(coins);
    }
    return 0;
}