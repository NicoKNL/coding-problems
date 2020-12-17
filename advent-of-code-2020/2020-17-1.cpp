#include <bits/stdc++.h>
using namespace std;

#define GRIDSIZE 8
#define CYCLES 6
#define ZMAX 2 * CYCLES + 1
#define XYMAX 2 * CYCLES + GRIDSIZE

vector<vector<vector<char>>> cube;
vector<vector<vector<char>>> next_cube;

bool inBounds(int x, int y, int z)
{
    return 0 <= x && x < XYMAX && 0 <= y && y < XYMAX && 0 <= z && z < ZMAX;
}

int countActive(int x_, int y_, int z_)
{
    int x, y, z;
    vector<int> offsets = {-1, 0, 1};
    int count = 0;
    for (int z_o : offsets) {
        z = z_ + z_o;
        for (int y_o : offsets) {
            y = y_ + y_o;
            for (int x_o : offsets) {
               x = x_ + x_o;
               if (inBounds(x, y, z) && !(x == x_ && y == y_ && z == z_)) {
                   if (cube[z][y][x] == '#') ++count;
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

    for (int z = 0; z < ZMAX; ++z) {
        vector<vector<char>> grid;
        for (int y = 0; y < XYMAX; ++y) {
            vector<char> row;
            for (int x = 0; x < XYMAX; ++x) {
                row.push_back('.');
            }
            grid.emplace_back(row);
        }
        cube.emplace_back(grid);
    }

    int y = CYCLES;
    while (getline(infile, line)) {
        vector<char> row;
        for (int x = CYCLES; x < CYCLES + line.length(); ++x) {
            cube[CYCLES][y][x] = line[x - CYCLES];
        }
        cout << line << endl;
        ++y;
    }

    for (int i = 0; i < CYCLES; ++i) {
        next_cube = cube;

        for (int z = 0; z < ZMAX; ++z) {
            for (int y = 0; y < XYMAX; ++y) {
                for (int x = 0; x < XYMAX; ++x) {
                    int count = countActive(x, y, z);

                    if (cube[z][y][x] == '#' && (count < 2 || count > 3)) {
                        next_cube[z][y][x] = '.';
                    } else if (count == 3) {
                        next_cube[z][y][x] = '#';
                    }
                }
            }
        }
        cube = next_cube;
    }

    int active_count = 0;
    for (int z = 0; z < ZMAX; ++z) {
        for (int y = 0; y < XYMAX; ++y) {
            for (int x = 0; x < XYMAX; ++x) {
                if (cube[z][y][x] == '#') ++active_count;
            }
        }
    }
    cout << active_count << endl;
}
