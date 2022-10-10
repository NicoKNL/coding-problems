#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    cin >> N >> K;

    long long count = 0;

    while (N--)
    {
        long long num;
        cin >> num;

        if (num % K == 0)
            ++count;
    }

    cout << count << '\n';
}