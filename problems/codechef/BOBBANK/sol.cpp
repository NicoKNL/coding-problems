#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int balance, X, Y, Z;
        cin >> balance >> X >> Y >> Z;

        for (int i = 0; i < Z; ++i)
        {
            balance += X;
            balance -= Y;
        }

        cout << balance << endl;
    }

    return 0;
}