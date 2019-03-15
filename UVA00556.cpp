#include <iostream>
#include <vector>

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

int main() {
    int rows, cols, tmp;
    vector<vector<int>> maze;
    vector<vector<int>> book;

    vector<int> dir = {0, 1};
    dir = rotate(dir, ML);
    dir = rotate(dir, MR);
    dir = rotate(dir, MR);
    dir = rotate(dir, ML);

    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;
        maze.clear();

        for (int r = 0; r < rows; r++) {
            vector<int> maze_row;
            vector<int> book_row;
            for (int c = 0; c < cols; c++) {
                cin >> tmp;
                maze_row.push_back(tmp);
                book_row.push_back(0);
            }
            maze.push_back(maze_row);
            book.push_back(book_row);
        }

        vector<int> pos {0, rows - 1};
        vector<int> dir {1, 0};
        vector<int> next_pos;
        // Set count on this spot to 1?

        while (true) {
            // step
            // Rotate right check
            dir = rotate(dir, MR);
            next_pos = {pos[0] + dir[0], pos[1] + dir[1]};
            if (0 <= next_pos[0] && next_pos[0] < cols && 0 <= next_pos[1] && next_pos[1] < rows && maze[next_pos[1]][next_pos[0]] == 0) {

            }
            if (pos[0] == 0 && pos[1] == rows - 1) break;
        }

        // Start counting

        // Output
    }


    return 0;
}