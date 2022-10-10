#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y, N;
    cin >> X >> Y >> N;

    for (int i = 1; i <= N; ++i)
    {
        bool fizz = i % X == 0;
        bool buzz = i % Y == 0;

        if (fizz && buzz)
        {
            cout << "FizzBuzz" << endl;
        }
        else if (fizz)
        {
            cout << "Fizz" << endl;
        }
        else if (buzz)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}