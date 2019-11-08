#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

#define loop(i, n) for (int i = 0; i < n; i++)

// todo: finish...

class SegmentTree {
private:
    vi A;
    int n;
    vi tree;
    vi lazy;

    int l(int p) { return  p<<1; }
    int r(int p) { return (p<<1)+1; }

    int conquer(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return A[a] <= A[b] ? a : b;
    }

    void build(int p, int L, int R) {
        if (L == R)
            tree[p] = L;
        else {
            int m = (L+R)/2;
            build(l(p), L  , m);
            build(r(p), m+1, R);
            tree[p] = conquer(tree[l(p)], tree[r(p)]);
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {
            tree[p] = L;
            if (L != R)
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            else
                A[L] = lazy[p];
            lazy[p] = -1;
        }
    }

    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (i > j) return;
        if ((L >= i) && (R <= j)) {
            A[L] = val;
            lazy[p] = val;
            propagate(p, L, R);
        }
        else {
            int m = (L+R)/2;
            update(l(p), L  , m, i          , min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j        , val);
            tree[p] = conquer(tree[l(p)], tree[r(p)]);
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (i > j) return -1;
        if ((L >= i) && (R <= j)) return tree[p];
        int m = (L+R)/2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m+1, R, max(i, m+1), j));
    }

public:
    SegmentTree(int sz) : n(sz), tree(4*n), lazy(4*n, -1) {}

    SegmentTree(const vi &_A) : SegmentTree((int)_A.size()) {
        A = _A;
        build(1, 0, n-1);
    }

    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

int main() {
    int n, queries;
    while (cin >> n) {
        if (n == 0) break;
        cin >> queries;
        vi vals(n);
        loop(i, n) cin >> vals[i];

        vvii T(n);
        build(vals, T, n + 1);

        int l, r;
        loop(i, queries) {
            cin >> l >> r;
            cout << tree.RMQ(l, r) << endl;
        }
    }

    return 0;
}