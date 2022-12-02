#include <iostream>

using namespace std;

struct AVLNode
{
    long long value, height, subtree_size;
    AVLNode *l, *r;
    AVLNode(long long v) : value(v), height(1), subtree_size(1), l(nullptr), r(nullptr){};
};

void print(AVLNode *n)
{
    if (n)
    {
        print(n->l);
        for (int i = 0; i < n->height - 1; ++i)
            cout << "     ";
        cout << "[" << n->value << ", " << n->subtree_size << "]" << endl;
        print(n->r);
    }
}

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
            p->l = insert(p->l, n);
        else if (n->value > p->value)
            p->r = insert(p->r, n);
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