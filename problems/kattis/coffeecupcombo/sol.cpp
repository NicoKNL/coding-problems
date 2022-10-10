#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int coffee = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '1')
        {
            coffee = 2;
        }
        else if (coffee > 0)
        {
            s[i] = '1';
            --coffee;
        }
    }

    int answer = count(s.begin(), s.end(), '1');
    cout << answer << '\n';
}