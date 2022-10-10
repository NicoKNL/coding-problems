#include <bits/stdc++.h>

using namespace std;

int makeString(vector<int> a, vector<int> b)
{
    int length = 0;
    int segments = 0;

    for (int i = 0; i < a.size() && i < b.size(); ++i)
    {
        length += a[i];
        length += b[i];

        segments += 2;
    }

    if (segments <= 1)
        return 0;

    return length - segments;
}

int main()
{
    int n;
    cin >> n;

    for (int c = 1; c <= n; ++c)
    {
        cout << "Case #" << c << ": ";

        int s;
        cin >> s;

        vector<int> red;
        vector<int> blue;

        while (s--)
        {
            string tmp;
            cin >> tmp;

            char color = *tmp.rbegin();
            int length = stoi(tmp.substr(0, tmp.length() - 1));

            if (color == 'R')
                red.push_back(length);
            else
                blue.push_back(length);
        }

        sort(red.begin(), red.end(), greater<int>());
        sort(blue.begin(), blue.end(), greater<int>());

        int red_first = makeString(red, blue);
        int blue_first = makeString(blue, red);

        cout << max(red_first, blue_first) << endl;
    }

    return 0;
}