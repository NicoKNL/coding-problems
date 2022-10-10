#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

pair<int, int> pos = {0, 0};
pair<int, int> dir = {1, 0};

void rotateRight(int degrees)
{
    pair<int, int> tmp = dir;

    while (degrees > 0) {
        cout << "x" << endl;
        dir.x = tmp.y;
        dir.y = -tmp.x;
        tmp = dir;
        degrees -= 90;
    }
}

void parse(char c, int n)
{
    switch(c) {
        case 'N':
            pos.y += n;
            break;
        case 'S':
            pos.y -= n;
            break;
        case 'E':
            pos.x += n;
            break;
        case 'W':
            pos.x -= n;
            break;
        case 'L':
            rotateRight(360 - n);
            break;
        case 'R':
            rotateRight(n);
            break;
        case 'F':
            pos.x += dir.x;
            pos.y += dir.y; 
            break;
    }
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/12.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    while (getline(infile, line)) {
        char c = line[0];
        int value = stoi(line.substr(1));
        parse(c, value);
    }

    cout << pos.x << ", " << pos.y << endl;
    cout << abs(pos.x) + abs(pos.y) << endl;
}
