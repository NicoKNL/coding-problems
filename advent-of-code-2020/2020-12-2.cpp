#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

pair<int,int> ship_pos = {0, 0};
pair<int, int> pos = {10, 1};

void rotateRight(int degrees)
{
    pair<int, int> tmp = pos;

    while (degrees > 0) {
        cout << "x" << endl;
        pos.x = tmp.y;
        pos.y = -tmp.x;
        tmp = pos;
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
            ship_pos.x += n * pos.x;
            ship_pos.y += n * pos.y; 
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

    cout << ship_pos.x << ", " << ship_pos.y << endl;
    cout << abs(ship_pos.x) + abs(ship_pos.y) << endl;
}
