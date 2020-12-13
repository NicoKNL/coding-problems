#include <bits/stdc++.h>

using namespace std;

//0.57314245

int main()
{
    default_random_engine generator;
    uniform_int_distribution<int> four(1, 4);
    uniform_int_distribution<int> six(1, 6);

//    pair<long long, long long> count = {1, 1}; // (Peter, Collin})
    pair<long long, long long> count = {660833246, 410582942}; // (Peter, Collin})
//    long long equals = 0;
    long long equals = 81583814;
    double prev = 0.0;
    double current = 1.0;
    while (abs(current - prev) > 0.0000000001) {
        prev = current;
        for (int i = 0; i < 1000000; ++i) { // 10 rolls
            int sum_peter = 0;
            int sum_collin = 0;
            for (int j = 0; j < 9; ++j) {
                sum_peter += four(generator);
            }
            for (int j = 0; j < 6; ++j) {
                sum_collin += six(generator);
            }
            if (sum_peter == sum_collin) {
                ++equals;
            } else if (sum_peter > sum_collin) {
                ++count.first;
            } else {
                ++count.second;
            }
        }
        current = (double) count.first / (double) (count.first + count.second + equals);
        printf("%0.8lf : %lld : %lld : %lld\n", current, count.first, count.second, equals);
    }
}