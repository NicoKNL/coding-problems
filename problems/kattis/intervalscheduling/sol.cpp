#include <bits/stdc++.h>

using namespace std;

struct interval
{
    int s, f;
};

int main()
{
    int n;
    cin >> n;

    vector<interval> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i].s >> V[i].f;

    sort(V.begin(), V.end(),
         [](auto lhs, auto rhs)
         {
             if (lhs.f < rhs.f)
                 return true;

             return false;
         });

    interval blocked = {-1, -1};
    int picks = 0;
    for (int i = 0; i < V.size(); ++i)
    {
        interval inter = V[i];
        if (inter.s >= blocked.f)
        {
            blocked = inter;
            ++picks;
        }
    }

    cout << picks << endl;

    return 0;
}