#include <bits/stdc++.h>

using namespace std;

int main() {
    long bins[9];
    while (cin >> bins[0] >> bins[1] >> bins[2] >> bins[3] >> bins[4] >> bins[5] >> bins[6] >> bins[7] >> bins[8]) {
        string order = "BCG";
        map<int, char> pos = {
                {0, 'B'},
                {1, 'G'},
                {2, 'C'}
        };
        string best_order;
        unsigned long move_cost = 1000000000000;
        do {
            // calculate cost to move
            int cost = 0;
            for (int i = 0; i < 9; i++) {
                if (order[i/3] != pos[i%3]) {
                    cost += bins[i];
                }
            }
            if (cost < move_cost) {
                move_cost = cost;
                best_order = order;
            }
        } while (next_permutation(order.begin(), order.end()));
        printf("%s %lu\n", best_order.c_str(), move_cost);
    }

    return 0;
}