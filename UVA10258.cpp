#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
struct Team {
    bool submitted = false;
    int team_number;
    int solved = 0;
    bool alreadySolved[10] = {false};
    int penalty_time = 0;
    int problems[10] = {0};

    Team() {};

    Team(int id) {
        team_number = id;
    }

    bool operator<(const Team& b) const {
        if (solved > b.solved) {
          return true;
        } else if (solved == b.solved && penalty_time < b.penalty_time) {
            return true;
        } else if (solved == b.solved && penalty_time == b.penalty_time && team_number < b.team_number){
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    int n, c, p, t;
    char L;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--) {
        istringstream ss_in;
        string s;
        vector<Team> rankings;
        unordered_map<int, Team> teams;
        for (int i = 1; i < 101; i++) {
            teams[i] = Team(i);
        }

        while (getline(cin, s)) {
            if (s.empty()) break;
            ss_in.clear();
            ss_in.str(s);
            ss_in >> c >> p >> t >> L;

            if (L == 'R' || L == 'U' || L == 'E') {
                teams[c].submitted = true;
            } else if (L == 'I') {
                teams[c].problems[p] += 20;
                teams[c].submitted = true;
            } else {
                if (!teams[c].alreadySolved[p]) {
                    teams[c].alreadySolved[p] = true;
                    teams[c].problems[p] += t;
                    teams[c].solved++;
                    teams[c].penalty_time += teams[c].problems[p];
                    teams[c].submitted = true;
                }
            }
        }

        for (auto it: teams) {
            if (it.second.submitted) {
                rankings.push_back(it.second);
            }
        }

        sort(rankings.begin(), rankings.end());
        for (Team team: rankings) {
            cout << team.team_number << " " << team.solved << " " << team.penalty_time << endl;
        }
        if (n) cout << endl;
    }
    return 0;
}