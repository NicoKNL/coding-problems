#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> notes = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

    map<string, set<string>> scales;
    for (int i = 0; i < notes.size(); ++i)
    {
        rotate(notes.begin(), notes.begin() + 1, notes.end());
        set<string> scale = {notes[0], notes[2], notes[4], notes[5], notes[7], notes[9], notes[11], notes[0]};
        scales[notes[0]] = scale;
    }

    int n;
    cin >> n;

    set<string> song;
    for (int i = 0; i < n; ++i)
    {
        string note;
        cin >> note;
        song.insert(note);
    }

    set<string> possible_scales;
    for (auto [scale, scalenotes] : scales)
    {
        bool possible = true;
        for (auto note : song)
        {
            if (scalenotes.find(note) == scalenotes.end())
            {
                possible = false;
                break;
            }
        }

        if (possible)
            possible_scales.insert(scale);
    }

    if (possible_scales.size() == 0)
        cout << "none" << endl;
    else
    {
        bool first = true;
        for (auto scale : possible_scales)
        {
            if (!first)
                cout << " ";

            first = false;
            cout << scale;
        }
        cout << endl;
    }

    return 0;
}