#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int teeth_upper_L = 8;
    int teeth_lower_L = 8;

    int teeth_upper_R = 8;
    int teeth_lower_R = 8;

    bool left_has_blue = false;
    bool right_has_blue = false;

    for (int i = 0; i < N; ++i)
    {
        string s;
        char c;
        cin >> s >> c;

        //// SIDE OF TOOTH
        bool rhs;
        if (s[1] == '-' || s[1] == '+')
        {
            rhs = true;
        }
        else
        {
            rhs = false;
        }

        if (c == 'b')
        {
            if (rhs)
            {

                right_has_blue = true;
            }
            else
            {
                left_has_blue = true;
            }
        }

        //// UPPER OR LOWER JAW
        bool upper;
        if (rhs)
        {
            if (s[1] == '+')
            {
                upper = true;
            }
            else
            {
                upper = false;
            }
        }
        else
        {
            if (s[0] == '+')
            {
                upper = true;
            }
            else
            {
                upper = false;
            }
        }

        //// MARK TOOTH
        if (rhs)
        {
            if (upper)
            {
                --teeth_upper_R;
            }
            else
            {
                --teeth_lower_R;
            }
        }
        else
        {
            if (upper)
            {
                --teeth_upper_L;
            }
            else
            {
                --teeth_lower_L;
            }
        }
    }

    if (left_has_blue && right_has_blue)
    {
        cout << 2 << endl;
    }
    else if (left_has_blue && teeth_upper_R > 0 && teeth_lower_R > 0)
    {
        cout << 1 << endl;
    }
    else if (right_has_blue && teeth_upper_L > 0 && teeth_lower_L > 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 2 << endl;
    }

    return 0;
}