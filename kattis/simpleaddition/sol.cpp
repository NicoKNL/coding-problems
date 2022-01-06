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
            // cout << _a << " + " << _b << " + " << carry << endl;
            // cout << "mod: " << (_a + _b + carry) % 10 << endl;
            // cout << "div: " << (_a + _b + carry) / 10 << endl;

            result += (char)((_a + _b + carry) % 10) + '0';
            carry = (_a + _b + carry) / 10;
            // cout << "  --  " << result << endl;
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
    string a, b;
    cin >> a >> b;

    big_integer A = {a};
    big_integer B = {b};

    big_integer result = A + B;

    cout << result.v << endl;

    return 0;
}