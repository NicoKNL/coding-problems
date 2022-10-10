#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        long long tmp;
        cin >> tmp;
        sum += tmp;
    }

    if (sum % 3 == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}