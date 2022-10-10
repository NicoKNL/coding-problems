#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *parent;
    struct TrieNode *children[ALPHABET_SIZE];
    int childcount;
    bool isEndOfWord;
};

vector<struct TrieNode *> reducable;

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->parent = NULL;
    pNode->isEndOfWord = false;
    pNode->childcount = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); ++i)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
            pCrawl->children[index]->parent = pCrawl;
            pCrawl->childcount++;
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
    reducable.push_back(pCrawl);
}

int reduce()
{
    vector<struct TrieNode *> newly_reducable;

    int removed = 0;
    for (auto *t : reducable)
    {
        while (t->parent->childcount == 1)
        {
            ++removed;
            t = t->parent;
        }
    }

    return removed;
}

int main()
{
    int n, l;
    cin >> n >> l;

    vector<string> V(n);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    struct TrieNode *root = getNode();
    sort(V.begin(), V.end());

    for (auto each : V)
        insert(root, each);

    cout << (n * l) - reduce() << endl;

    return 0;
}