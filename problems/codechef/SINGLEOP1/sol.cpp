#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int X;
        cin >> X;

        string s;
        cin >> s;

        int i;
        for (i = 0; i < s.length(); ++i)
        {
            if (s[i] == '0')
            {
                break;
            }
        }
        cout << i << endl;
    }
}