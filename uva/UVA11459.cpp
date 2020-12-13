#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, players, tunnels, rolls, from, to, active_player, roll;
    cin >> n;
    bool game_won;
    while (n--) {
        cin >> players >> tunnels >> rolls;
        unordered_map<int, int> umap;
        vector<int> player_positions;

        for (int i = 0; i < players; i++) {
            player_positions.push_back(1);
        }

        for (int i = 0; i < tunnels; i++) {
            cin >> from >> to;
            umap[from] = to;
        }

        game_won = false;
        active_player = 0;
        while (rolls--) {
            cin >> roll;
            if (game_won) continue;
            player_positions[active_player] += roll;
            while (umap.find(player_positions[active_player]) != umap.end()) {
                player_positions[active_player] = umap[player_positions[active_player]];
            }
            if (player_positions[active_player] >= 100) {
                player_positions[active_player] = 100;
                game_won = true;
            }
            active_player++;
            active_player %= players;
        }

        for (int i = 0; i < players; i++) {
            cout << "Position of player " << i + 1 << " is " << player_positions[i] << "." << endl;
        }
    }
    return 0;
}