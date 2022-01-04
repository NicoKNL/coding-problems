#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    vector<string> lines;
    int max_len = 0;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        max_len = max(max_len, (int)line.length());
        lines.push_back(line);
    }

    int penalty = 0;
    for (int i = 0; i < lines.size() - 1; ++i)
    {
        penalty += pow(max_len - lines[i].length(), 2);
    }

    cout << penalty << endl;

    return 0;
}