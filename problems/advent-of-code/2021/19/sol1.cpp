#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y, z;

    bool operator<(const Point &other) const
    {
        return tie(x, y, z) < tie(other.x, other.y, other.z); //< other.x) || (x == other.x && y < other.y) || (x == other.x && y == other.y && z < other.z);
    }

    bool operator==(const Point &other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    void rotate90X()
    {
        tie(x, y, z) = tuple<int, int, int>(x, -z, y);
    }

    void rotate90Y()
    {
        tie(x, y, z) = tuple<int, int, int>(-z, y, x);
    }

    void rotate90Z()
    {
        tie(x, y, z) = tuple<int, int, int>(y, -x, z);
    }
};

struct Scanner
{
    set<Point> S;
    set<Point> S_default;
    bool locked;

    Scanner()
    {
        locked = false;
        string line;
        while (getline(cin, line))
        {
            if (line.length() == 0)
                break;

            stringstream ss;
            ss << line;

            Point p;
            char _;
            ss >> p.x >> _ >> p.y >> _ >> p.z;

            S.insert(p);
        }
        S_default = S;
    }

    bool operator==(const Scanner &other) const
    {
        vector<Point> intersection;
        set_intersection(S.begin(), S.end(), other.S.begin(), other.S.end(), back_inserter(intersection));
        cout << "intersect: " << intersection.size() << endl;
        return intersection.size() >= 12;
    }

    void rotate90X()
    {
        set<Point> S2;
        for (Point p : S)
        {
            p.rotate90X();
            S2.insert(p);
        }
        S = S2;
    }

    void rotate90Y()
    {
        set<Point> S2;
        for (Point p : S)
        {
            p.rotate90Y();
            S2.insert(p);
        }
        S = S2;
    }

    void rotate90Z()
    {
        set<Point> S2;
        for (Point p : S)
        {
            p.rotate90Z();
            S2.insert(p);
        }
        S = S2;
    }

    void reset()
    {
        S = S_default;
    }

    void normalize()
    {
        int min_x = INT32_MAX;
        int min_y = INT32_MAX;
        int min_z = INT32_MAX;

        for (const Point &p : S)
        {
            min_x = min(min_x, p.x);
            min_y = min(min_y, p.y);
            min_z = min(min_z, p.z);
        }

        set<Point> S2;
        for (Point p : S)
        {
            if (min_x > 0)
                p.x -= min_x;
            else if (min_x < 0)
                p.x += min_x;

            if (min_y > 0)
                p.y -= min_y;
            else if (min_y < 0)
                p.y += min_y;

            if (min_z > 0)
                p.z -= min_z;
            else if (min_z < 0)
                p.z += min_z;

            S2.insert(p);
        }
        S = S2;
    }
};

int main()
{
    string line;

    vector<Scanner> V;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        Scanner s;
        V.push_back(s);
    }

    V[0].locked = true;
    V[0].normalize();

    vector<string> orientations = {
        "",
        "y",
        "yy",
        "yyy",
        "x",
        "xy",
        "xyy",
        "xyyy",
        "xx",
        "xxy",
        "xxyy",
        "xxyyy",
        "xxx",
        "xxxy",
        "xxxyy",
        "xxxyyy",
        "z",
        "zy",
        "zyy",
        "zyyy",
        "zz",
        "zzy",
        "zzyy",
        "zzyyy"};

    for (int i = 1; i < V.size(); ++i)
    {
        Scanner &s1 = V[i];

        for (string o : orientations)
        {
            s1.reset();
            for (char c : o)
            {
                if (c == 'x')
                    s1.rotate90X();
                if (c == 'y')
                    s1.rotate90Y();
                if (c == 'z')
                    s1.rotate90Z();
            }

            s1.normalize();

            if (s1 == V[0])
                cout << "found!" << endl;
        }
    }

    cout << V.size() << endl;

    return 0;
}
