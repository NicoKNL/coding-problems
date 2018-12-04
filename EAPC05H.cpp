#include <iostream>
#include <algorithm>

using namespace std;

struct Stone {
    int time;
    int mass;
    int value;
};


void oneRun()
{
    int N, T, M; // Number of stones, Time limit for pickup, Mass limit for pickup
    cin >> N >> T >> M;

    Stone stones[N];

    for (int i = 0; i < N; i++) {
        cin >> stones[i].time >> stones[i].mass >> stones[i].value;
    }

    int value_table[N+1][T+1][M+1]; // Number - Time - Mass
    for (int i = 0; i < N + 1; i++) { // Per row
        for (int time = 0; time < T + 1; time++) {
            for (int mass = 0; mass < M + 1; mass++) {
                if (i == 0) {
                    value_table[i][time][mass] = 0;
                } else {
                    Stone stone = stones[i - 1]; // First rock @ index 0
                    int lookback_time = time - stone.time;
                    int lookback_mass = mass - stone.mass;
                    if (lookback_time >= 0 && lookback_mass >= 0) {
                        value_table[i][time][mass] = max(stone.value + value_table[i-1][lookback_time][lookback_mass], value_table[i-1][time][mass]);
                    } else {
                        value_table[i][time][mass] = value_table[i-1][time][mass];
                    }
                }
            }
        }
    }
    cout << (value_table[N][T][M]) << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}