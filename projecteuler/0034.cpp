#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long> fact = {1};
    for (int i = 1; i < 10; ++i) {
        fact.push_back(fact[i-1] * i);
    }

    for (auto f : fact) {
        cout << f << " , ";
    }
    cout << endl;
    int result = 0;

    for (int i = 10; i < 1000000; ++i) {
        int sum = 0;
        int tmp = i;
        while (tmp > 0) {
            sum += fact[tmp % 10];
            tmp /= 10;
        }

        if (sum == i) {
            printf("%d\n", sum);
            result += sum;
        }
    }
    printf("%d\n", result);
}