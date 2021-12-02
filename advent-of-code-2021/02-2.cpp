#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    int x = 0;
    int y = 0;
    int aim = 0;

    while (getline(cin, s))
    {
        stringstream ss;
        ss.str(s);

        string dir;
        int dist;

        ss >> dir >> dist;

        if (dir == "forward")
        {
            x += dist;
            y += aim * dist;
        }
        else if (dir == "up")
        {
            aim -= dist;
        }
        else
        {
            aim += dist;
        }
    }

    cout << x * y << endl;

    return 0;
}