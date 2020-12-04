#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int cmd, x;
        bool bs = true, bq = true, bpq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while (n--) {
            cin >> cmd >> x;
            if (cmd == 1) {
                if (bs) s.push(x);
                if (bq) q.push(x);
                if (bpq) pq.push(x);
            } else { // cmd == 2
                if (bs) {
                    if (!s.empty() && s.top() == x) {
                        s.pop();
                    } else {
                        bs = false;
                    }
                }

                if (bq) {
                    if (!q.empty() && q.front() == x) {
                        q.pop();
                    } else {
                        bq = false;
                    }
                }

                if (bpq) {
                    if (!pq.empty() && pq.top() == x) {
                        pq.pop();
                    } else {
                        bpq = false;
                    }
                }
            }
        }

        if (!bs && !bq && !bpq) {
            cout << "impossible" << endl;
        } else if ((bs && bq) || (bs && bpq) || (bq && bpq)) {
            cout << "not sure" << endl;
        } else if (bs) {
            cout << "stack" << endl;
        } else if (bq) {
            cout << "queue" << endl;
        } else { // bpq == true
            cout << "priority queue" << endl;
        }

    }
    return 0;
}