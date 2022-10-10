#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int W, L;
        cin >> W >> L;

        if (W == 0 && L == 0)
            break;

        int n;
        cin >> n;

        int x = 0, y = 0;
        int x_real = 0, y_real = 0;
        for (int i = 0; i < n; ++i)
        {
            char dir;
            int dist;
            cin >> dir >> dist;

            if (dir == 'u')
            {
                y += dist;
                y_real = min(y_real + dist, L - 1);
            }

            if (dir == 'd')
            {
                y -= dist;
                y_real = max(y_real - dist, 0);
            }

            if (dir == 'l')
            {
                x -= dist;
                x_real = max(x_real - dist, 0);
            }

            if (dir == 'r')
            {
                x += dist;
                x_real = min(x_real + dist, W - 1);
            }
        }

        cout << "Robot thinks " << x << " " << y << endl;
        cout << "Actually at " << x_real << " " << y_real << endl
             << endl;
    }

    return 0;
}