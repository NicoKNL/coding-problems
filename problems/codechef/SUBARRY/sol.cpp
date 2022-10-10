#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        long long lo, hi;
        cin >> lo;
        hi = lo;
        N--;

        while (N--)
        {
            long long tmp;
            cin >> tmp;
            lo = min(lo, tmp);
            hi = max(hi, tmp);
        }

        long long abs_hi = max(abs(lo), abs(hi));

        long long ans_max = abs_hi * abs_hi;

        long long ans_min;
        if (lo < 0 && hi < 0)
        {
            ans_min = hi * hi;
        }
        else if (lo < 0 && hi >= 0)
        {
            ans_min = lo * hi;
        }
        else
        {
            ans_min = lo * lo;
        }

        cout << ans_min << " " << ans_max << endl;
    }

    return 0;
}
