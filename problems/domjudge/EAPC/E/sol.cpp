#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    int n;
    cin >> n;

    unordered_set<string> S;

    for (int i = 0; i < n; ++i)
    {
        int points;
        cin >> points;

        vector<Point> V;
        for (int ii = 0; ii < points; ++ii)
        {
            Point tmp;
            cin >> tmp.x >> tmp.y;
            V.push_back(tmp);
        }

        sort(V.begin(), V.end(), [](const Point &lhs, const Point &rhs)
             {
            if (lhs.x < rhs.x) {
                return true;
            } else if (lhs.x == rhs.x && lhs.y < rhs.y) {
                return true;
            } else {
                return false;
            } });

        string shape;
        for (int ii = 0; ii < points - 1; ++ii)
        {
            // format X
            int dx = V[ii].x - V[ii + 1].x;
            shape += to_string(dx);
            shape += 'X';

            // format Y
            int dy = V[ii].y - V[ii + 1].y;
            shape += to_string(dy);
            shape += 'Y';
        }

        S.insert(shape);
    }

    cout << S.size() << endl;

    return 0;
}