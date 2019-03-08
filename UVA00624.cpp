#include <iostream>
#include <vector>

using namespace std;
vector<int> songs;
vector<int> best_choices;
int optimal = 1000000;
int n;

int bt(int i, int length, vector<int> choices) {
    if (length < optimal && length >= 0) {
        optimal = length;
        best_choices = choices;
    }

    if (length == 0) {
        return 0;
    }

    int tmp_length = length;
    while (i < songs.size()) {
        tmp_length -= songs[i];
        if (tmp_length >= 0) {
            choices.push_back(songs[i]);
            length = min(length, bt(i + 1, tmp_length, choices));
            choices.pop_back();
        }
        tmp_length += songs[i];
        i++;
    }
    return length;
}

int main() {
    int tracks, tmp;
    while (cin >> n) {
        cin >> tracks;
        songs.clear();
        best_choices.clear();
        optimal = 1000000;
        for (int i = 0; i < tracks; i++) {
            cin >> tmp;
            songs.push_back(tmp);
        }
        bt(0, n, vector<int>{});
        for (int j = 0; j < best_choices.size(); j++) {
            cout << best_choices[j] << " ";
        }
        cout << "sum:" << n - optimal << endl;
    }
    return 0;
}