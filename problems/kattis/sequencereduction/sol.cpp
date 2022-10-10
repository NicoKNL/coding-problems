#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <list>

using namespace std;
typedef unsigned long long T;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    multimap<T, list<T>::iterator> M;
    list<T> L;
    for (int i = 0; i < N; ++i)
    {
        T temp;
        cin >> temp;

        M.insert({temp, L.insert(L.end(), temp)});
    }

    T answer = 0ll;
    for (const auto &[num, it] : M)
    {
        auto left = prev(it);
        auto right = next(it);

        bool has_left = false;
        bool has_right = false;
        T left_cost = 0ull;
        if (it != L.begin())
        {
            left_cost = max(*it, *left);
            has_left = true;
        }
        else
        {
            left_cost = INT64_MAX;
        }

        T right_cost = 0ull;
        if (right != L.end())
        {
            right_cost = max(*it, *right);
            has_right = true;
        }
        else
        {
            right_cost = INT64_MAX;
        }

        if (has_left || has_right)
            answer += min(left_cost, right_cost);

        L.erase(it);
    }

    cout << answer << '\n';
}