#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
#define x first
#define y second

bool intersect(Point a1, Point a2, Point b1, Point b2)
{
    if (a1.x > a2.x) swap(a1.x, a2.x);
    if (b1.y > b2.y) swap(b1.y, b2.y);
    return (a1.x < b1.x && a2.x > b1.x && b1.y < a1.y && b2.y > a1.y);
}

int main()
{
    // grab input file
    ifstream infile("../advent-of-code-2019/input/03.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<Point> wire1;
    vector<Point> wire2;

    string line_tmp = "";
    int i = 0;
    while (getline(infile, line_tmp)) {
        stringstream ss_csv(line_tmp);
        string line;
        Point p = {0, 0};
        if (i == 0) wire1.emplace_back(p);
        else wire2.emplace_back(p);

        while (getline(ss_csv, line, ',')) {
            stringstream ss(line);

            string instruction;
            while (ss >> instruction) {
                char direction = instruction[0];
                int offset = stoi(instruction.substr(1));
                switch (direction) {
                    case 'U':
                        p.y += offset;
                        break;
                    case 'D':
                        p.y -= offset;
                        break;
                    case 'L':
                        p.x -= offset;
                        break;
                    case 'R':
                        p.x += offset;
                        break;
                }
                if (i == 0) wire1.emplace_back(p);
                else wire2.emplace_back(p);
            }
        }
        ++i;
    }

    int distance = 999999999;
    for (int i = 0; i < wire1.size() - 1; ++i) {
        for (int j = 0; j < wire2.size() - 1; ++j) {
            if (intersect(wire1[i], wire1[i + 1], wire2[j], wire2[j + 1])) {
                int next_distance = abs(wire2[j].x) + abs(wire1[i].y);
                if (next_distance > 0) distance = min(distance, next_distance);
            }
        }
    }
    cout << distance << endl;
}
