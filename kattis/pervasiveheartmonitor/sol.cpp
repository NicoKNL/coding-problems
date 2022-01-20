#include <bits/stdc++.h>

using namespace std;

vector<string> parseLine(string line)
{

    stringstream ss;
    ss << line;

    vector<string> V;
    string s;

    while (ss >> s)
        V.push_back(s);

    return V;
}

string getName(const vector<string> &name)
{
    string result;

    for_each(name.begin(), name.end(),
             [&result](const string &s)
             {
                 result = result + " " + s;
             });

    return result;
}

int main()
{
    fixed(cout);
    cout.precision(6);
    string line;

    while (getline(cin, line))
    {
        vector<string> parsed = parseLine(line);

        vector<string> name;
        vector<double> heartrates;

        for_each(parsed.begin(), parsed.end(),
                 [&name, &heartrates](const string &s)
                 {
                     if ('0' <= s[0] && s[0] <= '9')
                         heartrates.push_back(stod(s));
                     else
                         name.push_back(s);
                 });

        double avg_heartrate = accumulate(heartrates.begin(), heartrates.end(), 0.0) / (double)heartrates.size();

        cout << avg_heartrate << getName(name) << endl;
    }
    return 0;
}