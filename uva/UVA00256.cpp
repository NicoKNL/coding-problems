#include <bits/stdc++.h>

using namespace std;

void precalculate() {
    printf("vector<string> two = vector<string>{");
    for (int i = 0; i < 100; i++) {
        int a = i / 10;
        int b = i % 10;
        if ((a + b) * (a + b) == i) {
            printf("\"%02d\",", i);
        }
    }
    printf("};\n");

    printf("vector<string> four = vector<string>{");
    for (int i = 0; i < 10000; i++) {
        int a = i / 100;
        int b = i % 100;
        if ((a + b) * (a + b) == i) {
            printf("\"%04d\",", i);
        }
    }
    printf("};\n");

    printf("vector<string> six = vector<string>{");
    for (int i = 0; i < 1000000; i++) {
        int a = i / 1000;
        int b = i % 1000;
        if ((a + b) * (a + b) == i) {
            printf("\"%06d\",", i);
        }
    }
    printf("};\n");

    printf("vector<string> eight = vector<string>{");
    for (int i = 0; i < 100000000; i++) {
        int a = i / 10000;
        int b = i % 10000;
        if ((a + b) * (a + b) == i) {
            printf("\"%08d\",", i);
        }
    }
    printf("};\n");
}

void print(vector<string> in) {
    for (string s : in) {
        printf("%s\n", s.c_str());
    }
}
int main() {
//    precalculate();

    // Pre-calc result
    vector<string> two = vector<string>{"00","01","81",};
    vector<string> four = vector<string>{"0000","0001","2025","3025","9801",};
    vector<string> six = vector<string>{"000000","000001","088209","494209","998001",};
    vector<string> eight = vector<string>{"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001",};
    int n;
    while (cin >> n) {
        if (n == 2) {
            print(two);
        } else if (n == 4) {
            print(four);
        } else if (n == 6) {
            print(six);
        } else { // n == 8
            print(eight);
        }
    }
    return 0;
}