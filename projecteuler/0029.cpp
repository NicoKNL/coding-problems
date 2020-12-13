#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<set<int>> count = {{}, {}};
    for (int a = 2; a <= 100; ++a) {
        count.push_back({}); // add new set
        for (int b = 2; b <= 100; ++b) {
            count[a].insert(b);
        }
    }

    for (int a = 2; a <= 100; ++a) {
        int base = a;
        for (int b = 2; b <= 100; ++b) {
            if (b % 3 == 0) { // if even
                base = pow(a, 2);
                if (base > 100) break;
                for (int c = b / 2; c <= 100; ++c) {
                    auto it = count[base].find(c);
                    if (it != count[base].end()) {
                        count[base].erase(it);
                    }
                }
            }
        }
    }

    int result = 0;
    for (set<int> s : count) {
        result += s.size();
    }
    printf("%d\n", result);
}