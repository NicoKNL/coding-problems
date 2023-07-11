#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Distance
{
    int straights = 0;
    int quarter_rounds = 0;

    Distance operator+(const Distance &other)
    {
        return {straights + other.straights, quarter_rounds + other.quarter_rounds};
    }
};

bool isValidPosition(int r, int c)
{
    if (r == 0 && c == 0)
        return false;

    return (r % 2 == 1 && c % 2 == 1) == 0;
}

double dist(const Distance &d)
{
    return 5.0 * (double)d.straights + 10.0 * 3.14159265359 / 4.0 * (double)d.quarter_rounds;
}

Distance min(const Distance &a, const Distance &b)
{
    if (dist(a) < dist(b))
        return a;

    return b;
}

int main()
{
    int h, w;
    cin >> h >> w;

    fixed(cout);
    cout.precision(9);

    vector<vector<char>> GRID(h, vector<char>(w, '.'));

    for (int r = 0; r < h; ++r)
        for (int c = 0; c < w; ++c)
            cin >> GRID[r][c];

    int rows = 2 * h + 1;
    int cols = 2 * w + 1;
    vector<vector<Distance>> DIST(rows, vector<Distance>(cols));

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            if (isValidPosition(r, c))
            {
                if (r == 0) // on first horizontal street
                {
                    DIST[r][c] = DIST[r][c - 1] + Distance{1, 0};
                }
                else if (c == 0) // on first vertical street
                {
                    DIST[r][c] = DIST[r - 1][c] + Distance{1, 0};
                }
                else if (r % 2 == 0 && c % 2 == 0) // on intersection
                {
                    DIST[r][c] = min(DIST[r][c - 1] + Distance{1, 0}, DIST[r - 1][c] + Distance{1, 0});
                }
                else if (r % 2 == 0) // horizontally in between intersections
                {
                    if (r > 1 && GRID[(r - 1) / 2][c / 2] == 'O')
                        DIST[r][c] = min(DIST[r][c - 1] + Distance{1, 0}, DIST[r - 1][c - 1] + Distance{0, 1});
                    else
                        DIST[r][c] = DIST[r][c - 1] + Distance{1, 0};
                }
                else if (c % 2 == 0) // vertically in between intersections
                {
                    if (c > 1 && GRID[r / 2][(c - 1) / 2] == 'O')
                        DIST[r][c] = min(DIST[r - 1][c] + Distance{1, 0}, DIST[r - 1][c - 1] + Distance{0, 1});
                    else
                        DIST[r][c] = DIST[r - 1][c] + Distance{1, 0};
                }
            }
        }
    }

    cout << dist(DIST[rows - 1][cols - 1]) << endl;
}