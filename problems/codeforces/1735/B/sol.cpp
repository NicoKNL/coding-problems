#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        vector<int> V(N, 0);
        for (int i = 0; i < N; ++i)
            cin >> V[i];

        sort(V.begin(), V.end());
        int div = 2 * V[0] - 1;

        int answer = 0;

        for (int each : V)
        {
            answer += each / div;

            if (each % div == 0)
                answer -= 1;
        }

        cout << answer << '\n';
    }
}