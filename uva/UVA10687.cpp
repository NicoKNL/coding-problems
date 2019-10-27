#include <bits/stdc++.h>

using namespace std;

struct Station {
    int x, y;
    Station * s1;
    Station * s2;
    bool visited = false;
    void update(Station & t) {
        int dist = pow(x - t.x, 2) + pow(y - t.y, 2);
        int s1_dist = pow(x - s1->x, 2) + pow(y - s1->y, 2);
        int s2_dist = pow(x - s2->x, 2) + pow(y - s2->y, 2);
        if (s2_dist < s1_dist) { //quick reorder. s2 = farther away.
            Station * tmp = s1;
            s1 = s2;
            s2 = tmp;
        }

        if (s2_dist == s1_dist) {
            if (s2 < s1) {
                Station * tmp = s1;
                s1 = s2;
                s2 = tmp;
            }
        }

        if (dist < s2_dist) {
            s2 = &t;
        } else if (dist == s2_dist) {
            if (t.x < s2->x) {
                s2 = &t;
            } else if (t.x == s2->x && t.y < s2-> y) {
                s2 = &t;
            }
        }

        if (dist < s1_dist) {
            s2 = s1;
            s1 = &t;
        } else if (dist == s1_dist) {
            if (t.x < s1->x) {
                s2 = s1;
                s1 = &t;
            } else if (t.x == s1->x && t.y < s1-> y) {
                s2 = s1;
                s1 = &t;
            }
        }
    }
};

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        vector<Station> stations(N);
        for (int i = 0; i < N; i++) {
            cin >> stations[i].x >> stations[i].y;
        }

        for (int s = 0; s < N; s++) {
            for (int t = 0; t < N; t++) {
                if (stations[s].x == stations[t].x && stations[s].y == stations[t].y) continue;
                if (stations[s].s1 == nullptr) {
                    stations[s].s1 = &stations[t];
                } else if (stations[s].s2 == nullptr) {
                    stations[s].s2 = &stations[t];
                } else {
                    stations[s].update(stations[t]);
                }
            }
        }

        queue<Station *> Q;
        Q.push(&stations[0]);
        while (!Q.empty()) {
            Station * current = Q.front();
            Q.pop();
            current->visited = true;
            if (current->s1 != nullptr && !current->s1->visited) Q.push(current->s1);
            if (current->s2 != nullptr && !current->s2->visited) Q.push(current->s2);
        }

        bool all_visited = true;
        for (Station s: stations) {
            if (!s.visited) {
                all_visited = false;
                break;
            }
        }

        if (all_visited) {
            cout << "All stations are reachable." << endl;
        } else {
            cout << "There are stations that are unreachable." << endl;
        }
    }
    return 0;
}

//4
//1 0 0 1 -1 0 0 -1
//8
//1 0 1 1 0 1 -1 1 -1 0 -1 -1 0 -1 1 -1
//6
//0 3 0 4 1 3 -1 3 -1 -4 -2 -5
//0