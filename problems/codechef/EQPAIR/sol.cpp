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

        unordered_map<long long, long long> M;

        for (int i = 0; i < N; ++i)
        {
            long long number;
            cin >> number;

            M[number]++;
        }

        long long answer = 0;

        for (auto [i, count] : M)
        {
            answer += (count * (count - 1ll) / 2ll);
        }

        cout << answer << endl;
    }

    return 0;
}
