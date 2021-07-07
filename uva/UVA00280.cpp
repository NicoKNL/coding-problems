#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    while (cin >> V) {
        if (V == 0) {
            return 0;
        }
        vector<vector<int>> adj(V+1);
        int source;
        int target;
        while (cin >> source) {
            if (source == 0) {
                break;
            }
            while (cin >> target) {
                if (target == 0) {
                    break;
                }
                adj[source].push_back(target);
            }
        }
        int queries;
        cin >> queries;
        while (queries--) {
            cin >> source;
            vector<int> visited(V+1);
            queue<int> Q;
//            Q.push(source);
            for (int t_id: adj[source]) {
                if (!visited[t_id]){
                    Q.push(t_id);
                }
            }
            while (!Q.empty()) {
                int id = Q.front();
                Q.pop();
                visited[id] = 1;
                for (int t_id: adj[id]) {
                    if (!visited[t_id]){
                        Q.push(t_id);
                    }
                }
            }

            vector<int> unreachable;
            for (int i = 1; i < V + 1; i++) {
                if (!visited[i]) {
                    unreachable.push_back(i);
                }
            }
            sort(unreachable.begin(), unreachable.end());
            cout << unreachable.size();
            for (int i = 0; i < unreachable.size(); i++) {
                cout << " " << unreachable[i];
            }
            cout << endl;
        }
    }
    return 0;
}