#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> ways(N + 1, 0);
    ways[0] = 1;

    for (int i = 1; i < N + 1; ++i)
    {
        for (int pick = 1; pick <= 3; ++pick)
        {
            if (i - pick >= 0)
                ways[i] += ways[i - pick];
        }
    }

    cout << ways[N] << endl;
}