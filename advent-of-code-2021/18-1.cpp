#include <bits/stdc++.h>

using namespace std;

struct Node;
struct Pair;
struct Number;

struct Node
{
};

struct Pair : public Node
{
};

struct Number : public Node
{
};

int main()
{
    string line;

    vector<Node *> V;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        Node *node = parse(line);
    }
    return 0;
}