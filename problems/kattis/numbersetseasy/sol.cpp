#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> prime_factors(int n, int threshold)
{
    set<int> factors;

    while (n % 2 == 0)
    {
        if (2 >= threshold)
            factors.insert(2);
        n /= 2;
    }

    for (int i = 3; (i * i) <= n; i += 2)
    {
        while (n % i == 0)
        {
            if (i >= threshold)
                factors.insert(i);
            n /= i;
        }
    }

    if (n > 2 && n >= threshold)
        factors.insert(n);

    return factors;
}

class UnionFind
{
    vector<int> p, rank, setSize;
    int numSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    int numDisJointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;

        int x = findSet(i), y = findSet(j);

        if (rank[x] > rank[y])
            swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
        setSize[y] += setSize[x];
        numSets--;
    }
};

int main()
{
    int T;
    cin >> T;

    for (int casenum = 1; casenum <= T; ++casenum)
    {
        int A, B, P;
        cin >> A >> B >> P;

        UnionFind UF(B + 1);
        vector<set<int>> factors(B + 1);
        for (int i = A; i <= B; ++i)
        {
            factors[i] = prime_factors(i, P);
            for (int ii = A; ii < i; ++ii)
            {
                for (auto f : factors[i])
                {
                    if (factors[ii].find(f) != factors[ii].end())
                    {
                        UF.unionSet(i, ii);
                        break;
                    }
                }
            }
        }

        cout << "Case #" << casenum << ": " << UF.numDisJointSets() - A << endl;
    }
}