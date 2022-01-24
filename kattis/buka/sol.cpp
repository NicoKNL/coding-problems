#include <bits/stdc++.h>

using namespace std;

struct big_integer
{
    string v;

    big_integer operator+(big_integer other)
    {
        string a = v;
        string b = other.v;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        if (a.length() < b.length())
            swap(a, b);

        string result;

        int carry = 0;
        for (int i = 0; i < a.length(); ++i)
        {
            if (i >= b.length())
                b += '0';

            int _a = a[i] - '0';
            int _b = b[i] - '0';

            result += (char)((_a + _b + carry) % 10) + '0';
            carry = (_a + _b + carry) / 10;
        }

        if (carry)
        {
            result += (carry + '0');
        }

        reverse(result.begin(), result.end());

        return {result};
    }
};

int main()
{
    string s_a, s_b;
    char op;

    cin >> s_a >> op >> s_b;

    if (op == '*')
    {
        int zeroes = 0;
        string c = s_a + s_b;

        for_each(c.begin(), c.end(),
                 [&](const char c)
                 {
                     if (c == '0')
                         ++zeroes;
                 });

        cout << "1";

        for (int i = 0; i < zeroes; ++i)
            cout << "0";

        cout << endl;
    }
    else
    {
        big_integer a, b;

        a.v = s_a;
        b.v = s_b;

        big_integer c = a + b;
        cout << c.v << endl;
    }

    return 0;
}