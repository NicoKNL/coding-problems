#include <bits/stdc++.h>

using namespace std;

int main() {
    int countries, partners, home, leaver;
    cin >> countries >> partners >> home >> leaver;
    vector<vector<int>> adj(countries + 1);
    vector<int> partnercount(countries + 1);
    vector<int> currentcount(countries + 1);
    vector<bool> handled(countries + 1);
    queue<int> leaving;
    leaving.push(leaver);
    handled[leaver] = true;

    int s, t;
    for (int i = 0; i < partners; i++) {
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
        partnercount[s]++;
        currentcount[s]++;
        partnercount[t]++;
        currentcount[t]++;
    }

    int current;
    while (!leaving.empty()) {
        current = leaving.front();
        leaving.pop();
        for (int neighbour : adj[current]) {
            currentcount[neighbour]--;
            if (currentcount[neighbour] <= partnercount[neighbour] / 2 && handled[neighbour] == false) { // div by 2 is correct? check!
                leaving.push(neighbour);
                handled[neighbour] = true;
            }
        }
    }

    if (currentcount[home] <= partnercount[home] / 2 || home == leaver) {
        cout << "leave" << endl;
    } else {
        cout << "stay" << endl;
    }
    return 0;
}