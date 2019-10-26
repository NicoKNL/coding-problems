#include <bits/stdc++.h>

using namespace std;
vector<vector<char>> grid;

map<char, vector<int>> dirs =
        {
                {'N', {-1, 0}},
                {'S', {1, 0}},
                {'E', {0, 1}},
                {'W', {0, -1}}
        };

class Robot {
public:
    int r, c;
    int rows, cols;
    char dir;
    int stickers;

    Robot () {};
    Robot (int r1, int c1, char d1) {
        stickers = 0;
        rows = r1;
        cols = c1;
        dir = d1;
        if (d1 == 'O') {
            dir = 'W';
        }
        if (d1 == 'L') {
            dir = 'E';
        }
    }

    void rotateLeft() {
        if (dir == 'N') {
            dir = 'W';
        } else if (dir == 'W') {
            dir = 'S';
        } else if (dir == 'S') {
            dir = 'E';
        } else if (dir == 'E') {
            dir = 'N';
        }
    }

    void rotateRight() {
        if (dir == 'N') {
            dir = 'E';
        } else if (dir == 'E') {
            dir = 'S';
        } else if (dir == 'S') {
            dir = 'W';
        } else if (dir == 'W') {
            dir = 'N';
        }
    }

    void moveForward() {
        int tmpr = r + dirs[dir][0];
        int tmpc = c + dirs[dir][1];
        if (0 <= tmpr && tmpr < rows) {
            if (0 <= tmpc && tmpc < cols) {
                if (grid[tmpr][tmpc] != '#') {
                    r = tmpr;
                    c = tmpc;
                    if (grid[r][c] == '*') {
                        stickers++;
                        grid[r][c] = '.';
                    }
                }
            }
        }
    }
};

int main() {
    int N, M, S;
    Robot robo;
    while (cin >> N >> M >> S) {
        if (N == 0 && M == 0 && S == 0) break;
        grid = vector<vector<char>> (N, vector<char> (M, '.'));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                cin >> grid[r][c];
                if (grid[r][c] == 'N' || grid[r][c] == 'S' || grid[r][c] == 'L' || grid[r][c] == 'O') {
                    robo = Robot(N, M, grid[r][c]);
                    robo.r = r;
                    robo.c = c;
                }
            }
        }

        string cmd;
        cin >> cmd;
        for (char c : cmd) {
            switch(c) {
                case 'D':
                    robo.rotateRight();
                    break;
                case 'E':
                    robo.rotateLeft();
                    break;
                case 'F':
                    robo.moveForward();
                    break;
            }
        }
        cout << robo.stickers << endl;
    }
    return 0;
}
