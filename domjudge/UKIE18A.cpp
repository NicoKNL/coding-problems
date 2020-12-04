#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> widths(n+1);
    vector<int> visited(n+1);
    vector<vector<int>> adj(n+1);

    for (int i = 1; i < n + 1; i++) {
        cin >> widths[i];
    }
    int a, b;

    for (int i = 0; i < c; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<vector<int>> clusters;
    for (int i = 1; i < n + 1; i++) {
        if (visited[i]) continue;

        queue<int> nodes;
        vector<int> cluster;
        nodes.push(i);
        while (!nodes.empty()) {
            if (!visited[nodes.front()]) {
                cluster.push_back(nodes.front());
                visited[nodes.front()] = 1;
                for (int j = 0; j < adj[nodes.front()].size(); j++) {
                    nodes.push(adj[nodes.front()][j]);
                }
            }
            nodes.pop();
        }
        if (!cluster.empty()) {
            clusters.push_back(cluster);
        }
    }

    int total_mods = 0;

    for (int i = 0; i < clusters.size(); i++) {
        map<int, int> counter;

        for (int j = 0; j < clusters[i].size(); j++) {
            if (counter.find(widths[clusters[i][j]])!=counter.end()) {
                counter[widths[clusters[i][j]]]++;
            } else {
                counter[widths[clusters[i][j]]] = 1;
            }
        }
        int maxim = 1;
        for (auto x : counter) {
            if (x.second > maxim) maxim = x.second;
        }

        total_mods += clusters[i].size() - maxim;
    }

    cout << total_mods << endl;
    return 0;
}