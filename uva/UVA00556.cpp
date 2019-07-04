#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

vector<vector<int>> ML {
        {0, -1},
        {1, 0}
};

vector<vector<int>> MR {
        {0, 1},
        {-1, 0}
};

vector<int> rotate(vector<int> dir, vector<vector<int>> rotation) {
    vector<int> new_dir;
    int tmp;
    for (int r = 0; r < rotation.size(); r++) {
        tmp = 0;
        for (int c = 0; c < rotation[0].size(); c++) {
            tmp += rotation[r][c] * dir[c];
        }
        new_dir.push_back(tmp);
    }
    return new_dir;
}

bool in_bounds(vector<int> pos, int rows, int cols) {
    return 0 <= pos[0] && pos[0] < cols && 0 <= pos[1] && pos[1] < rows;
}

int main() {
    int rows, cols, tmp;
    string s_tmp;
    vector<vector<int>> maze;
    vector<vector<int>> book;

    vector<int> dir = {0, 1};

    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;
        maze.clear();

        for (int r = 0; r < rows; r++) {
            vector<int> maze_row;
            vector<int> book_row;
            cin >> s_tmp;
            for (int c = 0; c < cols; c++) {
                tmp = s_tmp.at(c) - '0';
                maze_row.push_back(tmp);
                book_row.push_back(0);
            }
            maze.push_back(maze_row);
            book.push_back(book_row);
        }

        vector<int> pos {0, rows - 1};
        vector<int> dir {1, 0};
        vector<int> next_pos;

        while (true) {
            // step
            // Rotate right check
            dir = rotate(dir, MR);
            next_pos = {pos[0] + dir[0], pos[1] - dir[1]};
            if (in_bounds(next_pos, rows, cols) && maze[next_pos[1]][next_pos[0]] == 0) {
                book[next_pos[1]][next_pos[0]] += 1;
                dir = rotate(dir, ML);
                pos = next_pos;
            } else {
                dir = rotate(dir, ML);
                dir = rotate(dir, ML);
                continue;
            }
            if (pos[0] == 0 && pos[1] == rows - 1) break;
        }

        // Start counting
        int counter[5] = {0};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (maze[r][c] == 0) {
                    counter[book[r][c]]++;
                }
            }
        }

        // Output
        for (int i = 0; i < 5; i++) {
            cout << setw(3) << counter[i];
            if (i < 4) cout << " ";
        }
        cout << endl;
    }


    return 0;
}