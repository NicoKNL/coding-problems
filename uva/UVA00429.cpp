#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int diff(string a, string b) {
    int result = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        if (i > a.size() || i > b.size()) {
            result++;
            continue;
        }

        if (a[i] != b[i]) {
            result++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        string s, t, tmp;
        if (cases > 1) cout << endl;
        else         getline(cin, s); // \newline

        vector<string> dict;
        map<string, int> m;
        map<int, string> inv_m;

        int k = 0;
        while (cin >> s) {
            if (s == "*") break;
            dict.push_back(s);
            m[s] = k;
            inv_m[k] = s;
            k++;
        }

        int wordcount = dict.size();
        vi V(dict.size());
        vvi adj(wordcount);
        vi visited(wordcount, 0);
        vi dist(wordcount, 0);
        vi parent(wordcount, -1);
        int diffAB;
        for (int i = 0; i < wordcount; i++) {
            for (int j = i + 1; j < wordcount; j++) {
                diffAB = diff(dict[i], dict[j]);
                if (diffAB == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        getline(cin, tmp); // newline after *
        while (getline(cin, tmp)) {
            if (tmp.empty()) break;
            stringstream ss(tmp);
            ss >> s >> t;
            visited.assign(wordcount, 0);
            dist.assign(wordcount, 0);
            queue<int> Q;
            Q.push(m[s]);
            visited[m[s]] = 1;

            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        Q.push(v);
                        if (inv_m[v] == t) {
                            while (!Q.empty()) Q.pop();
                            break;
                        }
                    }
                }
            }
            printf("%s %s %d\n", s.c_str(), t.c_str(), dist[m[t]]);
//            vector<string> result;
//            while (t != s) {
//                result.push_back(t);
//                t = inv_m[parent[m[t]]];
//            }
//
//            result.push_back(s);
//            reverse(result.begin(), result.end());
//            for (int i = 0; i < result.size(); i++) {
//                if (i > 0) cout << " ";
//                cout << result[i];
//            }
//            cout << " " << result.size() - 1 << endl;
        }
        cases++;

    }
    return 0;
}