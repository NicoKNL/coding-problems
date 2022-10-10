#include <bits/stdc++.h>

using namespace std;

vector<pair<char, char>> options = {
    {'+', '='},
    {'-', '='},
    {'*', '='},
    {'/', '='},
    {'=', '+'},
    {'=', '-'},
    {'=', '*'},
    {'=', '/'},
};

bool canSolve(char op1, char op2, int a, int b, int c)
{
    if (op1 == '=')
    {
        swap(a, b);
        swap(b, c);
        swap(op1, op2);
    }

    if (b == 0 && op1 == '/')
        return false;

    if (op1 == '+')
        return a + b == c;
    if (op1 == '-')
        return a - b == c;
    if (op1 == '*')
        return a * b == c;
    if (op1 == '/')
        return a / b == c;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for (auto opt : options)
    {
        if (canSolve(opt.first, opt.second, a, b, c))
        {
            cout << a << opt.first << b << opt.second << c << endl;
            break;
        }
    }

    return 0;
}