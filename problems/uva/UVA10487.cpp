#include <iostream>
#include <vector>
#define vi vector<int>

using namespace std;

int main() {
    int n, m, tmp, sum, run=1;
    vi numbers;
    while (cin >> n) {
        if (n == 0) break;
        cout << "Case " << run << ":" << endl;
        numbers.clear();
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            numbers.push_back(tmp);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            sum = 100000000;
            for (int j = 0; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (abs(numbers[j] + numbers[k] - tmp) < abs(sum - tmp)) {
                        sum = numbers[j] + numbers[k];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", tmp, sum);
        }

        run++;
    }
    return 0;
}