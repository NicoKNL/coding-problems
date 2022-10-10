#include <bits/stdc++.h>

using namespace std;

float reduce(float a) {
    int x = (int) a;
    string s = to_string(x);
    x = 0;
    for (char c: s) {
        x += c - '0';
    }
    if (x >= 10) {
        x = (int) reduce((float) x);
    }
    return (float) x;
}

int main() {
    int valuemap[128] = {0};
    for (int i = 0; i < 26; i++) {
        valuemap[i + 65] = i + 1;
        valuemap[i + 97] = i + 1;
    }

    string a, b;
    float val_a, val_b;
    while (getline(cin, a)) {
        getline(cin, b);
        val_a = 0.0f;
        val_b = 0.0f;
        for (char c: a) {
            val_a += valuemap[c];
        }

        for (char c: b) {
            val_b += valuemap[c];
        }

        val_a = reduce(val_a);
        val_b = reduce(val_b);

        if (val_a < val_b) {
            printf("%.2f %%\n", (val_a / val_b) * 100.0f);
        } else {
            printf("%.2f %%\n", (val_b / val_a) * 100.0f);
        }
    }
    return 0;
}