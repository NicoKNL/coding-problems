#include <bits/stdc++.h>

using namespace std;

struct Cave
{
    string id;
    bool is_small;
    int visits;
    int visit_limit;
    vector<Cave *> adj;

    Cave(string s)
    {
        id = s;
        is_small = id[0] == tolower(s[0]) ? true : false;
        visits = 0;
        visit_limit = 1;
    }

    bool visited()
    {
        if (!is_small)
            return false;
        else
            return visits >= visit_limit;
    }

    void visit()
    {
        if (is_small)
            ++visits;
    }

    void unvisit()
    {
        if (is_small)
            --visits;
    }
};

pair<string, string> parseLine(string line)
{
    int dashpos = line.find('-');
    string s = line.substr(0, dashpos);
    string t = line.substr(dashpos + 1);
    return {s, t};
}

Cave *insertIfNotFound(unordered_map<string, Cave *> &V, string id)
{
    if (V.find(id) == V.end())
    {
        Cave *c = new Cave(id);
        V[id] = c;
    }

    return V[id];
}

void dfs(unordered_map<string, Cave *> &V, Cave *current, set<string> &paths, string &path)
{
    path += ",";
    path += current->id;
    current->visit();

    if (current->id == "end")
    {
        paths.insert(path);
    }
    else
    {
        for (Cave *other : current->adj)
        {
            if (!other->visited())
            {
                dfs(V, other, paths, path);
            }
        }
    }

    path = path.substr(0, path.length() - (current->id.length() + 1));
    current->unvisit();
}

int main()
{
    unordered_map<string, Cave *> V;

    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
        {
            break;
        }

        string s, t;
        tie(s, t) = parseLine(line);

        Cave *from = insertIfNotFound(V, s);
        Cave *to = insertIfNotFound(V, t);

        from->adj.push_back(to);
        to->adj.push_back(from);
    }

    set<string> paths;
    string path = "";

    for (auto &each : V)
    {
        if (each.first != "start" && each.first != "end")
        {
            each.second->visit_limit = 2;
            dfs(V, V["start"], paths, path);
            each.second->visit_limit = 1;
        }
    }

    cout << paths.size() << endl;

    return 0;
}