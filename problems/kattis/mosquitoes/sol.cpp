// TODO: For reasons unknown, this fails on a single case of the final testset
// Maximum clique solution
#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int global_max = 0;

struct Point
{
    double x, y;
};

bool isClique(vector<vector<int>> &graph, set<int> &chosen)
{
    for (int u : chosen)
        for (int v : chosen)
            if (graph[u][v] == 0)
                return false;

    return true;
}

int maxClique(vector<vector<int>> &graph, set<int> &chosen, int u)
{
    if (u >= graph.size())
        return chosen.size();

    int potential = chosen.size() + (graph.size() - u);
    if (potential <= global_max)
        return chosen.size();

    int max_ = 1;
    for (int v = u + 1; v < graph.size(); v++)
    {
        chosen.insert(v);

        if (isClique(graph, chosen))
        {
            max_ = max(max_, (int)chosen.size());
            global_max = max(global_max, max_);
            // cout << "yes: " << max_ << endl;
            max_ = max(max_, maxClique(graph, chosen, v));
            global_max = max(global_max, max_);
            // cout << "max_" << max_ << endl;
        }

        chosen.erase(v);
    }

    return max_;
}

double dist(Point &p1, Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt((dx * dx) + (dy * dy));
}

void solve()
{
    int N;
    double diameter;

    cin >> N >> diameter;
    double x, y;

    vector<Point> points;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }

    vector<vector<int>> graph(N, vector<int>(N, 0));

    for (int u = 0; u < N; u++)
        for (int v = 0; v < N; v++)
            if (dist(points[u], points[v]) <= diameter)
                graph[u][v] = 1;

    global_max = 0;
    int result = 0;
    for (int u = 0; u < graph.size() && graph.size() - u > result; u++)
    {
        set<int> chosen = {u};
        result = max(result, maxClique(graph, chosen, u));
    }

    cout << result << endl;
}

int main()
{
    int cases;
    cin >> cases;

    while (cases--)
        solve();
}