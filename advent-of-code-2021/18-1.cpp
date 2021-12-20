#include <bits/stdc++.h>

using namespace std;

enum MODE
{
    EXPLODE,
    SPLIT,
};

struct Node
{
    int value;
    Node *parent;
    Node *left;
    Node *right;

    Node()
    {
        value = -1;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

Node *parse(string &s, Node *node)
{
    char c = s[0];
    s = s.substr(1);

    if ('0' <= c && c <= '9')
    {
        cout << "c: " << c << endl;
        node->value = c - '0';
        cout << node->value << endl;
        return node;
    }

    if (c == '[')
    {
        Node *left_node = new Node();
        left_node->parent = node;
        node->left = parse(s, left_node);
    }

    c = s[0];
    s = s.substr(1);

    if (c == ',')
    {
        Node *right_node = new Node();
        right_node->parent = node;
        node->right = parse(s, right_node);
    }

    c = s[0];
    s = s.substr(1);

    if (c == ']')
    {
        return node;
    }

    return node;
}

void dfs(Node *node)
{
    if (node->value != -1)
    {
        cout << "value: " << node->value << endl;
        return;
    }

    dfs(node->left);
    dfs(node->right);
}

void addRight(Node *node, int value)
{
    if (node->value != -1)
    {
        node->value += value;
        return;
    }

    addRight(node->right, value);
}

void upstreamLeft(Node *node, int value)
{
    if (node == nullptr)
        return;

    if (node == node->parent->right)
    {
        addRight(node->parent->left, value);
        return;
    }

    upstreamLeft(node->parent, value);
}

void addLeft(Node *node, int value)
{
    if (node->value != -1)
    {
        node->value += value;
        return;
    }

    addLeft(node->left, value);
}

void upstreamRight(Node *node, int value)
{
    if (node == nullptr)
        return;

    if (node == node->parent->left)
    {
        addLeft(node->parent->right, value);
        return;
    }

    upstreamRight(node->parent, value);
}

bool explode(Node *node)
{
    queue<pair<int, Node *>> Q;
    Q.push({0, node});

    while (!Q.empty())
    {
        int depth;
        Node *node;

        tie(depth, node) = Q.front();
        Q.pop();

        if (node->value == -1)
        {
            Q.push({depth + 1, node->left});
            Q.push({depth + 1, node->right});
        }
        else if (depth > 4)
        {
            int left_value = node->value;
            int right_value = node->parent->right->value;
            cout << "exploding: [" << left_value << "," << right_value << "]" << endl;
            // upstreamLeft(node->parent, left_value);
            upstreamRight(node->parent, right_value);

            return true;
        }
    }

    return false;
}

int main()
{
    string line;
    vector<Node *> nums;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        cout << line << endl;
        Node *node = new Node();
        parse(line, node);
        cout << line << endl;
        nums.push_back(node);
    }

    dfs(nums[0]);
    explode(nums[0]);
    dfs(nums[0]);
    // for (int i = 1; i < nums.size(); ++i)
    // {
    //     nums[0] = "[" + nums[0] + "," + nums[i] + "]";
    //     nums[0] = resolve(nums[0]);
    // }

    // MODE mode = EXPLODE;
    // bool reduce = true;
    // while (reduce)
    // {
    //     reduce = false;

    //     switch (mode)
    //     {
    //     case EXPLODE:
    //         line = explode(line);
    //         break;
    //     case SPLIT:
    //         break;
    //     }
    // }

    return 0;
}