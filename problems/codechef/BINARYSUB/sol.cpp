#include <iostream>
#include <string>

using namespace std;

unsigned long long MOD = 998244353;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        unsigned long long prev_answer = 1ull; // empty string
        unsigned long long answer = 1ull;      // Always one way

        for (int i = 1; i < s.length(); ++i)
        {
            unsigned long long current = 0ll;
            if (s[i] == 'a')
            {
                current += answer;
                if (s[i - 1] == 'b')
                {
                    current += prev_answer;
                }
            }

            if (s[i] == 'b')
            {
                current += answer;

                if (s[i - 1] == 'a')
                {
                    current += prev_answer;
                }
            }

            prev_answer = answer;
            answer = current % MOD;
        }

        cout << answer << '\n';
    }
}