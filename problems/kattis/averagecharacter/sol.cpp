#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int sum = 0;

    for (char c : s)
        sum += int(c);

    sum /= s.size();

    cout << char(sum) << endl;
}