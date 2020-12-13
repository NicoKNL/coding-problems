#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<long long> pascal = {1, 1};
    int depth = 1;

    while (depth != 40) {
        list<long long> next_pascal;
        next_pascal.push_front(1);
        auto it = pascal.begin();
        long long a = *it;
        long long b;
        while (it != pascal.end()) {
            ++it;
            if (it == pascal.end()) {
                break;
            }
            b = *it;
            next_pascal.push_back(a + b);
            a = b;
        }
        next_pascal.push_back(1);
        pascal = next_pascal;
        depth++;
    }

    long long result = 1;
    for (long long n : pascal) {
        result = max(result, n);
    }
    cout << result;

}
