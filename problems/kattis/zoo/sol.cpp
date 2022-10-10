#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 1;
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        cin.ignore();

        cout << "List " << t << ":" << endl;

        map<string, int> animals;

        while (n--)
        {
            string line;
            getline(cin, line);

            stringstream ss;
            ss << line;

            string animal;
            while (ss >> animal)
                ;

            transform(
                animal.begin(), animal.end(), animal.begin(),
                [](char c)
                { return tolower(c); });

            ++animals[animal];
        }

        for (auto [animal, count] : animals)
            cout << animal << " | " << count << endl;

        ++t;
    }

    return 0;
}