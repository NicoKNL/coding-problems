#include <bits/stdc++.h>

using namespace std;

struct tree
{
    int value = -1;
    tree *left = nullptr;
    tree *right = nullptr;

    tree(int v) : value(v){};
};

void insert(tree *root, int v);

void insertLeft(tree *root, int v)
{
    if (root->left == nullptr)
        root->left = new tree(v);
    else
        insert(root->left, v);
}

void insertRight(tree *root, int v)
{
    if (root->right == nullptr)
        root->right = new tree(v);
    else
        insert(root->right, v);
}

void insert(tree *root, int v)
{
    if (v < root->value)
        insertLeft(root, v);
    else
        insertRight(root, v);
}

string encode(tree *root)
{
    string encoded_tree = "";

    if (root != nullptr)
    {
        encoded_tree += '[';
        encoded_tree += encode(root->left);
        encoded_tree += '|';
        encoded_tree += encode(root->right);
        encoded_tree += ']';
    }

    return encoded_tree;
}

int main()
{
    int n, k;
    cin >> n >> k;

    set<string> shapes;

    while (n--)
    {
        vector<int> V(k);
        for (int i = 0; i < k; ++i)
            cin >> V[i];

        tree *root = new tree(V[0]);

        for (int i = 1; i < k; ++i)
            insert(root, V[i]);

        string shape = encode(root);
        shapes.insert(shape);
    }

    cout << shapes.size() << endl;

    return 0;
}