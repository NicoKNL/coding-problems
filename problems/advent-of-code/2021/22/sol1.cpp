#include <bits/stdc++.h>

using namespace std;

bool inBounds(int x, int y, int z)
{
    bool x_ok = (0 <= x && x <= 100);
    bool y_ok = (0 <= y && y <= 100);
    bool z_ok = (0 <= z && z <= 100);

    return x_ok && y_ok && z_ok;
}

int main()
{
    vector<vector<vector<bool>>> G(101, vector<vector<bool>>(101, vector<bool>(101, false)));

    bool on;
    int x1, x2, y1, y2, z1, z2;
    while (cin >> on >> x1 >> x2 >> y1 >> y2 >> z1 >> z2)
    {
        x1 += 50;
        x2 += 50;

        y1 += 50;
        y2 += 50;

        z1 += 50;
        z2 += 50;

        if (!inBounds(x1, y1, z1) || !inBounds(x2, y2, z2))
            continue;

        for (int x = x1; x <= x2; ++x)
            for (int y = y1; y <= y2; ++y)
                for (int z = z1; z <= z2; ++z)
                    G[x][y][z] = on;
    }

    int result = 0;

    for (int x = 0; x < 101; ++x)
        for (int y = 0; y < 101; ++y)
            for (int z = 0; z < 101; ++z)
                result += G[x][y][z];

    cout << result << endl;
}