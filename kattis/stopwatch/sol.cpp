#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool running = false;
    int t0, t1;
    int time = 0;
    for (int i = 0; i < n; ++i)
    {
        if (running)
        {
            cin >> t1;
            time += (t1 - t0);
            t0 = t1;
            running = false;
        }
        else
        {
            cin >> t0;
            running = true;
        }
    }

    if (running)
    {
        cout << "still running" << endl;
    }
    else
    {
        cout << time << endl;
    }

    return 0;
}