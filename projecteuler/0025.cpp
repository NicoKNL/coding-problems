#include <bits/stdc++.h>

using namespace std;

string decrement(string a) {
    reverse(a.begin(), a.end());
    int i = 0;
    bool borrowing = false;
    while (a[i] == '0') {
        borrowing = true;
        a[i] = '9';
        ++i;
    }

    if (borrowing) {
        a[i] -= 1;
        if (i == a.length() - 1 && a[i] == '0') {
            a = a.substr(0, a.length() - 1);
        }
    } else {
        a[0] -= 1;
    }

    reverse(a.begin(), a.end());
    return a;
}

string carry(string a, int b, int pos)
{
    if (pos >= a.length()) {
        a += '0' + b;
        b = 0;
    } else {
        int tmp = a[pos] - '0';
        tmp += b % 10;
        a[pos] = '0' + tmp % 10;
        b /= 10;
        tmp /= 10;
        b += tmp;
    }
    if (b > 0) {
        a = carry(a, b, pos + 1);
    }
    return a;
}

string add(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < b.length(); ++i) {
        a = carry(a, b[i] - '0', i);
    }

    reverse(a.begin(), a.end());
    return a;
}

string multiply(string a, int b)
{
    string tmp = a;
    for (int i = 1; i < b; ++i) {
        a = add(a, tmp);
    }
    return a;
}

string multiply(string a, string b)
{
    string tmp = a;
    while (b != "0") {
        a = add(a, tmp);
        b = decrement(b);
        cout << b << " : " << a << endl;
    }
    return a;
}

int main() {
    string a = "1";
    string b = "1";

    int i = 1;
    while (a.length() != 1000) {
        string tmp = b;
        b = add(a, b);
        a = tmp;
        ++i;
    }
    cout << i << " : " << a;
}