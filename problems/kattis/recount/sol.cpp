#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name;

    unordered_map<string, int> M;

    bool runoff = false;
    int most_votes = 0;
    string most_voted = "";

    while (getline(cin, name))
    {
        if (name == "***")
            break;

        ++M[name];

        if (M[name] > most_votes)
        {
            most_voted = name;
            most_votes = M[name];
            runoff = false;
        }
        else if (M[name] == most_votes)
        {
            runoff = true;
        }
    }

    if (runoff)
        cout << "Runoff!" << endl;
    else
        cout << most_voted << endl;

    return 0;
}