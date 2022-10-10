#include <bits/stdc++.h>

using namespace std;

unordered_map<string, char> M = {
    {"clank", 'A'},
    {"bong", 'B'},
    {"click", 'C'},
    {"tap", 'D'},
    {"poing", 'E'},
    {"clonk", 'F'},
    {"clack", 'G'},
    {"ping", 'H'},
    {"tip", 'I'},
    {"cloing", 'J'},
    {"tic", 'K'},
    {"cling", 'L'},
    {"bing", 'M'},
    {"pong", 'N'},
    {"clang", 'O'},
    {"pang", 'P'},
    {"clong", 'Q'},
    {"tac", 'R'},
    {"boing", 'S'},
    {"boink", 'T'},
    {"cloink", 'U'},
    {"rattle", 'V'},
    {"clock", 'W'},
    {"toc", 'X'},
    {"clink", 'Y'},
    {"tuc", 'Z'},
    {"whack", ' '},
    {"bump", '^'},
    {"pop", '<'},
    {"dink", '1'},
    {"thumb", '0'},
};

int main()
{
    int n;
    cin >> n;

    list<char> L;

    bool shift = false;
    bool caps = false;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        char c = M[s];

        if (c == '<')
        {
            if (L.size())
                L.pop_back();
        }
        else if (c == ' ')
            L.push_back(c);
        else if (c == '^')
            caps = !caps;
        else if (c == '0')
            shift = false;
        else if (c == '1')
            shift = true;
        else
        {
            if ((caps && !shift) || (shift && !caps))
                L.push_back(c);
            else
                L.push_back(c + 97 - 65);
        }
    }

    for (const auto &each : L)
    {
        cout << each;
    }
    cout << endl;
    return 0;
}