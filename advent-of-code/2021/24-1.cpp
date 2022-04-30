#include <bits/stdc++.h>
#include <sys/resource.h>

using namespace std;
typedef long long T;

tuple<string, string, string> parseLine()
{
    string line;
    getline(cin, line);

    string op, a, b;

    int i = line.find(" ");
    op = line.substr(0, i);
    line = line.substr(i);

    i = line.find(" ");
    a = line.substr(0, i);
    b = line.substr(i);

    return {op, a, b};
}

int main()
{
    T x, y, z, w;
    char a, b;
    T bval;
    string line;
    while (cin >> op >> a >> b)
    {
    }
    return 0;
}