#include <bits/stdc++.h>

using namespace std;

int getYear(string dt)
{
    dt = dt.substr(0, 4);
    return stoi(dt);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string name, study_start, dob;
        int courses;
        cin >> name >> study_start >> dob >> courses;

        int study_start_year = getYear(study_start);
        int dob_year = getYear(dob);

        if (study_start_year >= 2010)
            cout << name << " eligible" << endl;
        else if (dob_year >= 1991)
            cout << name << " eligible" << endl;
        else if (courses >= 41)
            cout << name << " ineligible" << endl;
        else
            cout << name << " coach petitions" << endl;
    }

    return 0;
}