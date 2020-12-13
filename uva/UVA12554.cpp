#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string people[n];
    string song[16] = {"Happy", "birthday", "to", "you",
                       "Happy", "birthday", "to", "you",
                       "Happy", "birthday", "to", "Rujia",
                       "Happy", "birthday", "to", "you"};

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    int person_counter = 0;
    int song_counter = 0;
    bool started = false;
    bool all_people = false;
    while (true) {
        if (person_counter == 0 && started) {
            all_people = true;
        }

        if (song_counter == 0 && all_people) {
            break;
        } else {
            started = true;
            cout << people[person_counter] << ": " << song[song_counter] << endl;
            person_counter = (person_counter + 1) % n;
            song_counter = (song_counter + 1) % 16;
        }
    }
    return 0;
}