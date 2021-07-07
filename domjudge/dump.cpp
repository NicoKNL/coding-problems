#include <bits/stdc++.h>

using namespace std;
int N = 12;
int L = 18;
vector<int> lengths {0, 3, 9, 4, 1, 5, 4, 2, 4, 2, 2, 10, 7};

int width(int i, int j) {
    int result = j - i;
    while (i <= j) {
        result += lengths[i];
        i++;
    }
    return result;
}

int cost(int i, int j) {
    int result = L - width(i, j);
    return (int) pow(result, 3);
}

int main() {
    int minimum;
    int current;
    vector<int> T(N+1);

    for (int j = 1; j < N+1; j++) {
        minimum = INT_MAX;
        for (int i = j; i >= 1; i--) {
            if (width(i, j) > L) break;
            current = cost(i, j) + T[i-1];
            if (current < minimum) minimum = current;
        }
        T[j] = minimum;
    }

    for (int i = 0; i < N+1; i++) {
        cout << T[i] << endl;
    }
    return 0;
}