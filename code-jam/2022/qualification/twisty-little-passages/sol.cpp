#include <bits/stdc++.h>

using namespace std;

void solve()
{
    unsigned long long n, k;
    cin >> n >> k;

    vector<unsigned long long> V(n + 1, 0);
    set<int> S;

    for (int i = 1; i <= n; ++i)
        S.insert(i);

    int room, passages;
    cin >> room >> passages;
    V[room] = passages;
    S.erase(room);

    for (int i = 0; i < k && S.size() > 0; ++i)
    {
        string cmd = "T " + to_string(*S.begin());

        cout << cmd << endl;
        cin >> room >> passages;
        V[room] = passages;
        S.erase(room);
    }

    unsigned long long fully_connected = (n * (n - 1ull)) / 2ull; // Upper limit

    unsigned long long seen = accumulate(V.begin(), V.end(), 0); // Passages seen
    unsigned long long seen_maximum = seen;                      // Graph more like fully connected
    unsigned long long seen_minimum = seen / 2ull;               // Handshake lemma - we see every passage from both ends
    unsigned long long expected_seen = (seen_maximum + seen_minimum) / 2ull;

    unsigned long long unvisited = count(V.begin(), V.end(), 0ull);
    unsigned long long unknown_maximum = unvisited * (n - 1ull) / 2ull; // Fully connected
    unsigned long long unknown_minimum = unvisited;                     // Barely attached
    unsigned long long expected_unknown = (unknown_maximum + unknown_minimum) / 2ull;

    unsigned long long expected_avg = min((expected_seen + expected_unknown) / 2ull, fully_connected);
    expected_avg /= 75ull;
    expected_avg *= 1000ull;
    string cmd = "E " + to_string(expected_avg);
    cout << cmd << endl;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
        solve();

    return 0;
}