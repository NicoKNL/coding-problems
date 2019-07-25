#include <bits/stdc++.h>

using namespace std;

int main() {
    int buildings[20000] = {0};
    int left, height, right;
    while (cin >> left >> height >> right) {
        for (int i = left; i < right; i++) {
            if (height > buildings[i]) {
                buildings[i] = height;
            }
        }
    }

    bool empty_output = true;
    bool new_building = true;
    int current_height = 0;
    for (int i = 0; i < 20000; i++) {
        if (new_building && buildings[i] != 0) {
            current_height = buildings[i];
            if (empty_output) {
                printf("%d %d", i, buildings[i]);
                empty_output = false;
            } else {
                printf(" %d %d", i, buildings[i]);
            }
            if (new_building) {
                new_building = false;
            }
        } else if (buildings[i] != current_height) {
            current_height = buildings[i];
            printf(" %d %d", i, buildings[i]);
            if (current_height == 0) {
                new_building = true;
            }
        }
    }
    printf("\n");
    return 0;
}