#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n, r, tmp;
    cin >> m >> n;
    vector<vector<pair<int, int>>> adj;
    vector<vector<pair<int, int>>> adj_t;

    for (int i = 0; i < m; i++) {
        cin >> r;
        vector<pair<int, int>> row;
        for (int j = 0; j < r; j++) {
            cin >> tmp;
            row.push_back(pair<int, int> {tmp, 0});
        }

        for (int j = 0; j < r; j++) {
            cin >> tmp;
            row[j].second = tmp;
        }

        adj.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        adj_t.push_back(vector<pair<int, int>>{});
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            adj_t[adj[i][j].first].push_back(pair<int, int> {i, adj[i][j].second});
        }
    }

    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) {
        cout << adj_t[i].size();
        for (int j = 0; j < adj_t[i].size(); j++) {
            cout << " " << adj_t[i][j].second;
        }
        cout << endl;
    }
    return 0;
}