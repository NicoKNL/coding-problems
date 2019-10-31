#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string in;
        vector<vector<int>> adj(26);
        vector<bool> visited(26);
        while(1) {
            cin >> in;

            if (in[0] == '(') {
                int s = in[1] - 'A';
                int t = in[3] - 'A';
                adj[s].push_back(t);
                adj[t].push_back(s);
            } else if (in[0] == '*') {
                break;
            }
        }
        cin >> in;
        vector<int> v;
        for (int i = 0; i < in.length(); i += 2) {
            v.push_back(in[i] - 'A');
        }

        int trees = 0;
        int acorns = 0;
        for (int i : v) {
            if (visited[i]) continue;
            int nodes = 1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()) {
                int current = Q.front(); Q.pop();
                visited[current] = true;
                for (int i_adj: adj[current]) {
                    if (!visited[i_adj]) {
                        nodes++;
                        Q.push(i_adj);
                    }
                }
            }
            if (nodes == 1) acorns++;
            else trees++;
        }
        
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }
    return 0;
}