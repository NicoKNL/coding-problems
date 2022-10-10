#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> S;

    while (n--)
    {
        int tmp;
        cin >> tmp;
        S.push(tmp);
    }

    while (!S.empty())
    {
        cout << S.top() << endl;
        S.pop();
    }

    return 0;
}