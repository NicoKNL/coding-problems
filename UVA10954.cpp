#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    long tmp;

    while (cin >> n) {
        if (n == 0) break;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            min_heap.push(tmp);
        }

        long cost = 0, sum;
        while (min_heap.size() > 1) {
            sum = 0;
            sum += min_heap.top();
            min_heap.pop();
            sum += min_heap.top();
            min_heap.pop();
            min_heap.push(sum);
            cost += sum;
        }
        cout << cost << endl;
    }
    return 0;
}