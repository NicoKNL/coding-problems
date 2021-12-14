#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> Rule;
#define from first
#define to second

tuple<unordered_map<string, int>, char, char> parsePolymer()
{
    unordered_map<string, int> P;

    string line, start;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        start = line;
    }

    for (int i = 0; i < start.length() - 1; ++i)
    {
        string s = start.substr(i, 2);
        cout << s << endl;
        P[s] += 1;
    }

    return {P, start[0], start[start.length() - 1]};
}

vector<Rule> parseRules()
{
    vector<Rule> rules;

    while (true)
    {
        string a, _, b;
        cin >> a >> _ >> b;

        if (a.empty() || b.empty())
            break;

        rules.push_back({a, b});
    }

    return rules;
}

void applyRules(unordered_map<string, int> &P, const vector<Rule> &rules)
{
    unordered_map<string, int> next_P;

    for (const auto &rule : rules)
    {
        if (P.find(rule.from) != P.end())
        {
            string left = rule.from[0] + rule.to;
            string right = rule.to + rule.from[1];
            next_P[left] += P[rule.from];
            next_P[right] += P[rule.from];
        }
    }

    P = next_P;
}

void countChars(const unordered_map<string, int> &P, char first, char last)
{
    cout << "----------------------------------------" << endl;
    unordered_map<char, int> counter;

    for (const auto &each : P)
    {
        // for (int i = 0; i < each.second; ++i)
        //     cout << each.first << ", ";
        counter[each.first[0]] += each.second;
    }
    // cout << endl;
    ++counter[last];

    int total = 0;
    vector<int> V;
    for (const auto &each : counter)
    {
        total += each.second;
        V.push_back(each.second);
        cout << each.first << " : " << each.second << endl;
    }

    cout << "total: " << total << endl;

    sort(V.begin(), V.end());
    cout << "diff: " << *V.rbegin() - *V.begin() << endl;
}

int main()
{
    char first, last;
    unordered_map<string, int> polymer;
    tie(polymer, first, last) = parsePolymer();

    vector<Rule> rules = parseRules();
    countChars(polymer, first, last);

    for (int i = 0; i < 10; ++i)
    {
        applyRules(polymer, rules);
        countChars(polymer, first, last);
    }

    return 0;
}