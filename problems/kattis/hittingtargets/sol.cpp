#include <bits/stdc++.h>

using namespace std;

struct vec2
{
    double x, y;
};

struct target
{
    virtual bool hit(vec2 pt) = 0;
};

struct rectangle : target
{
    vec2 bottom_left;
    vec2 top_right;

    rectangle(vec2 a, vec2 b) : bottom_left(a), top_right(b){};

    bool hit(vec2 pt) override
    {
        return bottom_left.x <= pt.x && pt.x <= top_right.x && bottom_left.y <= pt.y && pt.y <= top_right.y;
    }
};

struct circle : target
{
    vec2 center;
    double radius;

    circle(vec2 a, double r) : center(a), radius(r){};

    bool hit(vec2 pt) override
    {
        return sqrt(pow(pt.x - center.x, 2) + pow(pt.y - center.y, 2)) <= radius;
    }
};

int main()
{
    int n_targets;
    cin >> n_targets;

    vector<target *> V;

    for (int i = 0; i < n_targets; ++i)
    {
        string t;
        cin >> t;

        if (t == "rectangle")
        {
            vec2 a, b;
            cin >> a.x >> a.y >> b.x >> b.y;

            V.emplace_back(new rectangle(a, b));
        }
        else
        {
            vec2 c;
            double r;
            cin >> c.x >> c.y >> r;

            V.emplace_back(new circle(c, r));
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        vec2 pt;
        cin >> pt.x >> pt.y;

        int count = 0;

        for (auto t : V)
            if (t->hit(pt))
                ++count;

        cout << count << endl;
    }

    return 0;
}