#include <bits/stdc++.h>

using namespace std;

int digitSum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int L, D, X;
    cin >> L >> D >> X;

    vector<int> nums;

    for (int i = 1; i <= 10000; ++i)
    {
        if (digitSum(i) == X && L <= i && i <= D)
            nums.push_back(i);
    }

    cout << nums.front() << endl;
    cout << nums.back() << endl;

    return 0;
}