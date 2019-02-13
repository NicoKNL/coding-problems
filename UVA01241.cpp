#include <iostream>
#include <vector>

using namespace std;

void run() {
    int n, m, players;
    cin >> n >> m;
    players = (1 << n);
    vector<bool> tournament;

    for (int i = 0; i < players; i++) {
        tournament.push_back(1);
    }

    int p;
    while (m--) {
        cin >> p;
        tournament[p - 1] = 0;
    }

    int withouts = 0;
    while (tournament.size() > 1) {
        for (int i = 0; i < players; i+=2) {
            if (tournament[i] ^ tournament[i + 1]) withouts++;
            if (tournament[i] | tournament[i + 1]) tournament[i] = 1;
        }

        for (int i = tournament.size() - 1; i > 0; i-=2) {
            tournament.erase(tournament.begin() + i);
        }
    }
    cout << withouts << endl;

}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}