#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long T;

ostream &operator<<(ostream &os, const vector<int> &V)
{
    for (const auto &each : V)
    {
        os << each << " ";
    }
    return os;
}

set<vector<int>> splits;

void recurse(vector<int> &split, int dimension, int remainder, int last, int D, int H)
{
    // string spacer(dimension, ' ');
    // cout << spacer << spacer << dimension << ": " << split << " :" << remainder << endl;
    if (remainder == 0 && dimension == D)
    {
        splits.insert(split);
    }
    else if (remainder <= 0 || dimension >= D)
    {
        return;
    }
    else
    {
        for (int i = last; i <= remainder; ++i)
        {
            split[dimension] = i;
            recurse(split, dimension + 1, remainder - i, i, D, H);
            split[dimension] = 0;
        }
    }
}

map<int, __uint128_t> FAC;

void build_fac_map(int H)
{
    FAC[0] = 1;
    FAC[1] = 1;
    for (__uint128_t i = 2; i <= H; ++i)
    {
        FAC[i] = FAC[i - 1] * i;
        // cout << "FAC[" << i << "] = " << FAC[i] << endl;
    }
}

unsigned long long factorial(vector<int> &split, int H)
{
    unsigned long long result = FAC[H];
    // cout << result << endl;
    // cout << "- - -" << endl;
    for (int each : split)
    {
        // cout << "each: " << each << endl;
        result /= FAC[each];
    }

    if (result == 0)
    {
        cout << split << endl;
        result = FAC[H];
        cout << result << endl;
        cout << "- - -" << endl;
        for (int each : split)
        {
            // cout << "each: " << each << " >> " << FAC[each] << endl;
            result /= FAC[each];
        }
    }

    return result;
}

int main()
{
    int D, H;
    cin >> D >> H;

    vector<int> split(D);
    for (int i = 0; i < H; ++i)
    {
        split[0] = i;
        recurse(split, 1, H - i - 1, i, D, H - 1);
    }

    build_fac_map(H);

    cout << "-----------" << endl;
    cout << *splits.begin() << endl;
    // cout << "splits: " << splits.size() << endl;
    // for (const auto each : splits)
    //     cout << each << endl;
    cout << "-----------" << endl;

    set<unsigned long long> nums;
    for (auto split : splits)
    {
        nums.insert(factorial(split, H - 1));
        // break;
    }

    for (auto each : nums)
        cout << each << endl;

    return 0;
}