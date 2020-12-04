#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> sequence_length;
    int max_length = 0;
    long long best_number = 0;

    for (int i = 500000; i < 1000000; ++i) {
        int length = 1;
        long long collatz = i;
        while (collatz != 1) {
            if (collatz & 1) {
                collatz = 3 * collatz + 1;
            } else {
                collatz /= 2;
            }
            if (sequence_length.find(collatz) != sequence_length.end()) {
                length += sequence_length[collatz];
                collatz = 1;
            } else {
                ++length;
            }
        }
        sequence_length[i] = length;
        if (length > max_length) {
            max_length = length;
            best_number = i;
        }
    }
    cout << best_number << " - " << max_length;
}
