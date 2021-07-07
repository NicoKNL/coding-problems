#include <bits/stdc++.h>
using namespace std;

#define GRIDSIZE 8
#define CYCLES 6
#define XYMAX 2 * CYCLES + GRIDSIZE

vector<vector<vector<vector<char>>>> cube;
vector<vector<vector<vector<char>>>> next_cube;

bool inBounds(int x, int y, int z, int w)
{
    return 0 <= x && x < XYMAX && 0 <= y && y < XYMAX && 0 <= z && z < XYMAX && 0 <= w && w < XYMAX;
}

int countActive(int x_, int y_, int z_, int w_)
{
    int x, y, z, w;
    vector<int> offsets = {-1, 0, 1};
    int count = 0;
    for (int w_o : offsets) {
        w = w_ + w_o;
        for (int z_o : offsets) {
            z = z_ + z_o;
            for (int y_o : offsets) {
                y = y_ + y_o;
                for (int x_o : offsets) {
                    x = x_ + x_o;
                    if (inBounds(x, y, z, w) && !(x == x_ && y == y_ && z == z_ && w == w_)) {
                        if (cube[w][z][y][x] == '#') ++count;
                    }
                }
            }
        }
    }
    return count;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/17.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";

    for (int w = 0; w < XYMAX; ++w) {
        vector<vector<vector<char>>> box;
        for (int z = 0; z < XYMAX; ++z) {
            vector<vector<char>> grid;
            for (int y = 0; y < XYMAX; ++y) {
                vector<char> row;
                for (int x = 0; x < XYMAX; ++x) {
                    row.push_back('.');
                }
                grid.emplace_back(row);
            }
            box.emplace_back(grid);
        }
        cube.emplace_back(box);
    }

    int y = CYCLES;
    while (getline(infile, line)) {
        vector<char> row;
        for (int x = CYCLES; x < CYCLES + line.length(); ++x) {
            cube[CYCLES][CYCLES + GRIDSIZE / 2][y][x] = line[x - CYCLES];
        }
        cout << line << endl;
        ++y;
    }

    for (int i = 0; i < CYCLES; ++i) {
        cout << "----------------" << endl;
        next_cube = cube;

        for (int w = 0; w < XYMAX; ++w) {
            for (int z = 0; z < XYMAX; ++z) {
                for (int y = 0; y < XYMAX; ++y) {
                    for (int x = 0; x < XYMAX; ++x) {
                        int count = countActive(x, y, z, w);

                        if (cube[w][z][y][x] == '#' && (count < 2 || count > 3)) {
                            next_cube[w][z][y][x] = '.';
                        } else if (count == 3) {
                            next_cube[w][z][y][x] = '#';
                        }
                    }
                }
            }
        }
        cube = next_cube;
    }

    int active_count = 0;
    for (int w = 0; w < XYMAX; ++w) {
        for (int z = 0; z < XYMAX; ++z) {
            for (int y = 0; y < XYMAX; ++y) {
                for (int x = 0; x < XYMAX; ++x) {
                    if (cube[z][y][x][w] == '#') ++active_count;
                }
            }
        }
    }

    cout << active_count << endl;
}
