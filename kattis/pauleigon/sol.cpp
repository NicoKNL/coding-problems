#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n_serves, paul_score, other_score;
    cin >> n_serves >> paul_score >> other_score;

    unsigned long long total = paul_score + other_score;
    total /= n_serves;

    if (total & 1)
        cout << "opponent" << endl;
    else
        cout << "paul" << endl;

    return 0;
}