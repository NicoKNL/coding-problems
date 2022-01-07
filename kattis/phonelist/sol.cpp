#include <bits/stdc++.h>

using namespace std;

struct trie
{
    unordered_map<char, trie *> children = {};
    bool is_end_of_word = false;
};

void insert(trie *root, string key)
{
    for (char c : key)
    {
        if (root->children.find(c) == root->children.end())
            root->children[c] = new trie;

        root = root->children[c];
    }

    root->is_end_of_word = true;
}

bool isPrefixFree(trie *root)
{
    queue<trie *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        trie *current = Q.front();
        Q.pop();

        if (current->is_end_of_word && current->children.size() > 0)
            return false;

        for (auto each : current->children)
        {
            Q.push(each.second);
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        trie *root = new trie;

        while (n--)
        {
            string s;
            cin >> s;
            insert(root, s);
        }

        if (isPrefixFree(root))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}