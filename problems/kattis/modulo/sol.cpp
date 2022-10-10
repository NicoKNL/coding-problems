#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> nums;

    for (int i = 0; i < 10; ++i)
    {
        int tmp;
        cin >> tmp;

        nums.insert(tmp % 42);
    }

    cout << nums.size() << endl;

    return 0;
}