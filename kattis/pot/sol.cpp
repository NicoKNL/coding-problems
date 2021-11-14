#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int score = 0;

    while (N--)
    {
        int P;
        cin >> P;

        int exp = P % 10;
        int base = P / 10;
        score += pow(base, exp);
    }
    cout << score << endl;
    return 0;
}