#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Point;
typedef pair<Point, Point> Edge;

enum Orientation
{
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

ostream &operator<<(ostream &os, const Edge &e)
{
    os << e.first << " -> " << e.second;
    return os;
}

ostream &operator<<(ostream &os, const vector<vector<int>> &grid)
{
    for (int r = 0; r < grid.size(); ++r)
    {
        os << "[";
        for (int c = 0; c < grid[0].size(); ++c)
        {
            os << grid[r][c] << " ";
        }
        os << "]" << endl;
    }
    return os;
}

Point parsePoint(string s)
{
    Point p;
    int comma = s.find(',');
    p.first = stoi(s.substr(0, comma));
    p.second = stoi(s.substr(comma + 1));
    return p;
}

Edge parseLine(string s)
{
    int pos = s.find('-');
    string start = (s.substr(0, pos - 1));
    string end = (s.substr(pos + 3));

    return {parsePoint(start), parsePoint(end)};
}

int getMax(const vector<Edge> &edges)
{
    int max_value = 0;
    for (const auto &e : edges)
    {
        max_value = max(max_value, e.first.first);
        max_value = max(max_value, e.first.second);
        max_value = max(max_value, e.second.first);
        max_value = max(max_value, e.second.second);
    }
    return max_value;
}

Orientation getOrientation(const Edge &e)
{
    if (e.first.first == e.second.first)
    {
        return Orientation::VERTICAL;
    }
    else if (e.first.second == e.second.second)
    {
        return Orientation::HORIZONTAL;
    }
    else
    {
        return Orientation::DIAGONAL;
    }
}

vector<int> range(int start, int end)
{
    int offset = start > end ? -1 : 1;

    vector<int> range;
    do
    {
        range.push_back(start);
        start += offset;
    } while (start != end);

    range.push_back(end);

    return range;
}

void tagEdge(vector<vector<int>> &G, const Edge &e)
{
    if (getOrientation(e) == Orientation::HORIZONTAL)
    {
        int x_start = min(e.first.first, e.second.first);
        int x_end = max(e.first.first, e.second.first);
        int y = e.first.second;

        for (int x = x_start; x <= x_end; ++x)
            ++G[y][x];
    }
    else if (getOrientation(e) == Orientation::VERTICAL)
    {
        int y_start = min(e.first.second, e.second.second);
        int y_end = max(e.first.second, e.second.second);
        int x = e.first.first;

        for (int y = y_start; y <= y_end; ++y)
            ++G[y][x];
    }
    else
    { // Orientation::DIAGONAL
        int x_start = e.first.first;
        int x_end = e.second.first;
        int y_start = e.first.second;
        int y_end = e.second.second;

        vector<int> x_range = range(x_start, x_end);
        vector<int> y_range = range(y_start, y_end);

        for (int i = 0; i < x_range.size(); ++i)
            ++G[y_range[i]][x_range[i]];
    }
}

void tagEdges(vector<vector<int>> &G, const vector<Edge> &edges)
{
    for (const auto &e : edges)
    {
        tagEdge(G, e);
    }
}

int countOverlapGreaterThan(const vector<vector<int>> &G, int threshold)
{
    int count = 0;
    for (int y = 0; y < G.size(); ++y)
    {
        for (int x = 0; x < G.size(); ++x)
        {
            if (G[y][x] > threshold)
                ++count;
        }
    }
    return count;
}

int main()
{
    string s;

    vector<Edge> edges;
    while (getline(cin, s))
    {
        Edge e = parseLine(s);
        edges.push_back(e);

        cout << e << endl;
    }

    int max_value = getMax(edges) + 1;

    vector<vector<int>> G(max_value, vector<int>(max_value, 0));
    tagEdges(G, edges);
    cout << G << endl;
    cout << countOverlapGreaterThan(G, 1) << endl;
    return 0;
}