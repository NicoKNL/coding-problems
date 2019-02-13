#include <iostream>
#include <vector>

using namespace std;

int withouts;


vector<bool> recurse(vector<bool> in) {
    vector<bool> front(in.begin(), in.begin() + in.size() / 2);
    vector<bool> back(in.begin() + in.size() / 2, in.end());

    if (front.size() > 1 && back.size() > 1) {
        front = recurse(front);
        back = recurse(back);
    }

    if (front.at(0) ^ back.at(0)) withouts++;
    if (front.at(0) || back.at(0)) {
        return vector<bool> {1};
    } else {
        return vector<bool> {0};
    }

}

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

    withouts = 0;
    vector<bool> front(tournament.begin(), tournament.begin() + tournament.size() / 2 - 1);
    vector<bool> back(tournament.begin() + tournament.size() / 2, tournament.end());
    recurse(tournament);

    cout << withouts << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}