#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct AVLNode
{
    long long value, height, subtree_size, smaller_count;
    AVLNode *l, *r;
    AVLNode(long long v) : value(v), height(1), subtree_size(1), smaller_count(0), l(nullptr), r(nullptr){};
};

class AVLTree
{
public:
    AVLNode *root;

    AVLTree() : root(nullptr){};

    AVLNode *insert(int value)
    {
        AVLNode *n = new AVLNode(value);
        root = insert(root, n);
        return n;
    }

private:
    AVLNode *insert(AVLNode *p, AVLNode *n)
    {
        if (!p)
            return n;
        else if (n->value < p->value)
        {
            p->l = insert(p->l, n);
        }
        else if (n->value > p->value)
        {
            if (p->l)
                n->smaller_count += p->l->subtree_size;
            n->smaller_count += 1;
            p->r = insert(p->r, n);
        }
        else
            return p;

        p->height = max(getHeight(p->l), getHeight(p->r)) + 1;
        p->subtree_size += 1;

        int balance_factor = getBalanceFactor(p);

        if (balance_factor > 1)
        {
            if (n->value < p->l->value)
                p = rotateRight(p);
            else // n->value > p->l->value
            {
                p->l = rotateLeft(p->l);
                p = rotateRight(p);
            }
        }

        if (balance_factor < -1)
        {
            if (n->value > p->r->value)
                p = rotateLeft(p);
            else // n->value < p->r->value
            {
                p->r = rotateRight(p->r);
                p = rotateLeft(p);
            }
        }

        updateSubtreeSize(p);

        return p;
    }

    int getHeight(AVLNode *n) { return n ? n->height : 0; }

    int getSubtreeSize(AVLNode *n) { return n ? n->subtree_size : 0; }

    int max(int a, int b) { return (a > b) ? a : b; }

    int getBalanceFactor(AVLNode *n) { return n ? getHeight(n->l) - getHeight(n->r) : 0; }

    AVLNode *rotateRight(AVLNode *y)
    {
        AVLNode *x = y->l;
        AVLNode *z = x->r;

        x->r = y;
        y->l = z;

        y->height = max(getHeight(y->l), getHeight(y->r)) + 1;
        x->height = max(getHeight(x->l), getHeight(x->r)) + 1;

        y->subtree_size = getSubtreeSize(y->l) + getSubtreeSize(y->r) + 1;
        x->subtree_size = getSubtreeSize(x->l) + getSubtreeSize(x->r) + 1;

        return x;
    }

    AVLNode *rotateLeft(AVLNode *x)
    {
        AVLNode *y = x->r;
        AVLNode *z = y->l;

        x->r = z;
        y->l = x;

        x->height = max(getHeight(x->l), getHeight(x->r)) + 1;
        y->height = max(getHeight(y->l), getHeight(y->r)) + 1;

        x->subtree_size = getSubtreeSize(x->l) + getSubtreeSize(x->r) + 1;
        y->subtree_size = getSubtreeSize(y->l) + getSubtreeSize(y->r) + 1;

        return y;
    }

    void updateSubtreeSize(AVLNode *n)
    {
        if (n->r)
            n->r->subtree_size = getSubtreeSize(n->r->l) + getSubtreeSize(n->r->r) + 1;

        if (n->l)
            n->l->subtree_size = getSubtreeSize(n->l->l) + getSubtreeSize(n->l->r) + 1;

        n->subtree_size = getSubtreeSize(n->l) + getSubtreeSize(n->r) + 1;
    }
};

struct Trainer
{
    long long A;
    long long B;
};

vector<long long> parseArena(int N)
{
    vector<long long> V;

    for (int i = 0; i < N; ++i)
    {
        long long tmp;
        cin >> tmp;

        V.push_back(tmp);
    }

    return V;
}

vector<Trainer> parseTrainers(int N, vector<long long> &A, vector<long long> &B)
{
    vector<Trainer> trainers;
    for (int i = 0; i < N; ++i)
    {
        trainers.push_back({A[i], B[i]});
    }
    return trainers;
}

void normalizeB(vector<Trainer> &V)
{
    sort(V.begin(), V.end(),
         [](const Trainer &lhs, const Trainer &rhs)
         { return lhs.B < rhs.B; });

    for (int i = 0; i < V.size(); ++i)
    {
        V[i].B = i;
    }
}

void normalizeA(vector<Trainer> &V)
{
    sort(V.begin(), V.end(),
         [](const Trainer &lhs, const Trainer &rhs)
         { return lhs.A < rhs.A; });

    for (int i = 0; i < V.size(); ++i)
    {
        V[i].A = i;
    }
}

void reverseSortTrainersOnA(vector<Trainer> &V)
{
    sort(V.begin(), V.end(),
         [](const Trainer &lhs, const Trainer &rhs)
         { return lhs.A > rhs.A; });
}

vector<long long> calculateWincountPerTrainer(const vector<Trainer> &V)
{
    vector<long long> wincount(V.size());
    AVLTree tree;

    for (int i = 0; i < V.size(); ++i)
    {
        const Trainer &t = V[i];

        wincount[i] = t.A;

        auto node = tree.insert(t.B);
        wincount[i] += node->smaller_count;
    }

    return wincount;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<long long> A = parseArena(N);
        vector<long long> B = parseArena(N);
        vector<Trainer> trainers = parseTrainers(N, A, B);

        normalizeB(trainers);
        normalizeA(trainers);

        reverseSortTrainersOnA(trainers);

        vector<long long> wincount = calculateWincountPerTrainer(trainers);

        long long answer = count(wincount.begin(), wincount.end(), N - 1);

        cout << answer << endl;
    }

    return 0;
}
