#include <bits/stdc++.h>

using namespace std;

struct Cave
{
    string id;
    bool is_small;
    bool visited;
    vector<Cave *> adj;

    Cave(string s)
    {
        id = s;
        is_small = id[0] == tolower(s[0]) ? true : false;
        visited = false;
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

void dfs(unordered_map<string, Cave *> &V, Cave *current, int &paths, string &path)
{
    path += ",";
    path += current->id;
    if (current->is_small)
        current->visited = true;

    if (current->id == "end")
    {
        ++paths;
    }
    else
    {
        for (Cave *other : current->adj)
        {
            if (!other->visited)
            {
                dfs(V, other, paths, path);
            }
        }
    }

    path = path.substr(0, path.length() - (current->id.length() + 1));
    current->visited = false;
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

    int paths = 0;
    string path = "";
    dfs(V, V["start"], paths, path);

    cout << paths << endl;

    return 0;
}