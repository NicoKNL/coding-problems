#include <bits/stdc++.h>

using namespace std;

class toilet
{
public:
    char state;
    int swaps = 0;
    toilet(char c) : state(c){};

    void swap()
    {
        if (state == 'U')
            state = 'D';
        else if (state == 'D')
            state = 'U';

        ++swaps;
    }

    void put(char c)
    {
        if (state != c)
            swap();

        post();
    }

    virtual void post() = 0;
};

class toilet_up : public toilet
{
public:
    using toilet::toilet;
    void post()
    {
        if (state != 'U')
            swap();
    }
};

class toilet_down : public toilet
{
public:
    using toilet::toilet;
    void post()
    {
        if (state != 'D')
            swap();
    }
};

class toilet_leave : public toilet
{
public:
    using toilet::toilet;
    void post() {}
};

int main()
{
    string s;
    cin >> s;

    toilet_up t1(s[0]);
    toilet_down t2(s[0]);
    toilet_leave t3(s[0]);

    for (int i = 1; i < s.length(); ++i)
    {
        t1.put(s[i]);
        t2.put(s[i]);
        t3.put(s[i]);
    }

    cout << t1.swaps << endl;
    cout << t2.swaps << endl;
    cout << t3.swaps << endl;

    return 0;
}