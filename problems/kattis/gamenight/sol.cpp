#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string s;
    cin >> s;

    int a = 0, b = 0, c = 0;
    for (char t : s)
    {
        if (t == 'A')
            ++a;
        else if (t == 'B')
            ++b;
        else if (t == 'C')
            ++c;
    }

    struct counter
    {
        int a, b, c;
    };

    // INITIALIZE for ABC
    counter counter = {0, 0, 0};
    for (int i = 0; i < s.length(); ++i)
    {
        char t = s[i];

        if (i < a)
        {
            if (t == 'A')
                ++counter.a;
        }
        else if (i < (a + b))
        {
            if (t == 'B')
                ++counter.b;
        }
        else if (i < (a + b + c))
        {
            if (t == 'C')
                ++counter.c;
        }
    }

    string ss = s + s;
    int swaps = a - counter.a + b - counter.b + c - counter.c;
    for (int i = 1; i < s.length(); ++i)
    {
        if (ss[i - 1] == 'A')
            --counter.a;

        if (ss[i + a - 1] == 'A')
            ++counter.a;

        if (ss[i + a - 1] == 'B')
            --counter.b;

        if (ss[i + a + b - 1] == 'B')
            ++counter.b;

        if (ss[i + a + b - 1] == 'C')
            --counter.c;

        if (ss[i + a + b + c - 1] == 'C')
            ++counter.c;

        int new_swaps = a - counter.a + b - counter.b + c - counter.c;
        swaps = min(swaps, new_swaps);
    }

    // INITIALIZE for CBA
    counter = {0, 0, 0};
    for (int i = 0; i < s.length(); ++i)
    {
        char t = s[i];

        if (i < c)
        {
            if (t == 'C')
                ++counter.c;
        }
        else if (i < (c + b))
        {
            if (t == 'B')
                ++counter.b;
        }
        else if (i < (c + b + a))
        {
            if (t == 'A')
                ++counter.a;
        }
    }

    for (int i = 1; i < s.length(); ++i)
    {
        if (ss[i - 1] == 'C')
            --counter.c;

        if (ss[i + c - 1] == 'C')
            ++counter.c;

        if (ss[i + c - 1] == 'B')
            --counter.b;

        if (ss[i + c + b - 1] == 'B')
            ++counter.b;

        if (ss[i + c + b - 1] == 'A')
            --counter.a;

        if (ss[i + c + b + a - 1] == 'A')
            ++counter.a;

        int new_swaps = a - counter.a + b - counter.b + c - counter.c;
        swaps = min(swaps, new_swaps);
    }

    cout << swaps << endl;
}