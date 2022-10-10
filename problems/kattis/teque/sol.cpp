#include <bits/stdc++.h>

using namespace std;

int SIZE = 1000000;

struct teque
{
    list<int> L;
    list<int>::iterator middle;

    void push_front(int n)
    {
        L.push_front(n);

        if (L.size() == 1)
            middle = L.begin();
        else
        {
            if (L.size() % 2 == 1)
                middle++;
        }
    }

    void push_back(int n)
    {
        L.push_back(n);
        if (L.size() == 1)
            middle = L.begin();
        else
        {
            if (L.size() % 2 == 0)
                middle--;
        }
    }

    void push_middle(int n)
    {
        if (L.size() == 0)
        {
            L.push_front(n);
            middle = L.begin();
        }
        else
        {
            middle = L.insert(middle, n);
            if (L.size() % 2 == 1)
                ++middle;
        }
    }

    int get(int i)
    {
        auto it = L.begin();
        advance(it, i);
        return *it;
    }
};

ostream &operator<<(ostream &os, const list<int> &L)
{
    for (auto each : L)
        os << " " << each;

    return os;
}

int main()
{
    int n;
    cin >> n;

    teque T;

    for (int i = 0; i < n; ++i)
    {
        string op;
        int n;
        cin >> op >> n;

        if (op == "push_back")
            T.push_back(n);
        else if (op == "push_middle")
            T.push_middle(n);
        else if (op == "push_front")
            T.push_front(n);
        else
            cout << T.get(n) << endl;

        cout << T.L << endl;
    }
    return 0;
}