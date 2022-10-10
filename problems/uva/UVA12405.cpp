#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, size;
    cin >> n;
    char cell;
    int testcase = 1;
    while (n--) {
        cin >> size;
        int scarecrows = 0;
        int counter = 0;
        bool in_block = false;
        for (int i = 0; i < size; i++) {
            cin >> cell;
            if (!in_block && cell == '.') {
                scarecrows++;
                in_block = true;
                counter = 1;
            } else if (counter == 2) {
                in_block = false;
            } else {
                counter++;
            }
        }

        printf("Case %d: %d\n", testcase, scarecrows);
        testcase++;
    }
    return 0;
}