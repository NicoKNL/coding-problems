#include <bits/stdc++.h>

using namespace std;

struct Segment
{
    char top;
    char top_left;
    char top_right;
    char center;
    char bottom_left;
    char bottom_right;
    char bottom;
};

ostream &operator<<(ostream &os, const Segment &seg)
{
    os << " " << seg.top << endl;
    os << seg.top_left << " " << seg.top_right << endl;
    os << " " << seg.center << endl;
    os << seg.bottom_left << " " << seg.bottom_right << endl;
    os << " " << seg.bottom << endl;
    return os;
}

ostream &operator<<(ostream &os, const vector<string> &V)
{
    for (const auto &v : V)
    {
        os << v << " ";
    }
    os << endl;
    return os;
}

vector<string>
getDigitStrings(const Segment &seg)
{
    vector<string> digit_strings(10, "");

    digit_strings[0] = string(1, seg.top) + string(1, seg.top_left) + string(1, seg.top_right) + string(1, seg.bottom_left) + string(1, seg.bottom_right) + string(1, seg.bottom);
    digit_strings[1] = string(1, seg.top_right) + string(1, seg.bottom_right);
    digit_strings[2] = string(1, seg.top) + string(1, seg.top_right) + string(1, seg.center) + string(1, seg.bottom_left) + string(1, seg.bottom);
    digit_strings[3] = string(1, seg.top) + string(1, seg.top_right) + string(1, seg.center) + string(1, seg.bottom_right) + string(1, seg.bottom);
    digit_strings[4] = string(1, seg.top_left) + string(1, seg.top_right) + string(1, seg.center) + string(1, seg.bottom_right);
    digit_strings[5] = string(1, seg.top) + string(1, seg.top_left) + string(1, seg.center) + string(1, seg.bottom_right) + string(1, seg.bottom);
    digit_strings[6] = string(1, seg.top) + string(1, seg.top_left) + string(1, seg.center) + string(1, seg.bottom_left) + string(1, seg.bottom_right) + string(1, seg.bottom);
    digit_strings[7] = string(1, seg.top) + string(1, seg.top_right) + string(1, seg.bottom_right);
    digit_strings[8] = string(1, seg.top) + string(1, seg.top_left) + string(1, seg.top_right) + string(1, seg.center) + string(1, seg.bottom_left) + string(1, seg.bottom_right) + string(1, seg.bottom);
    digit_strings[9] = string(1, seg.top) + string(1, seg.top_left) + string(1, seg.top_right) + string(1, seg.center) + string(1, seg.bottom_right) + string(1, seg.bottom);

    sort(digit_strings[0].begin(), digit_strings[0].end());
    sort(digit_strings[1].begin(), digit_strings[1].end());
    sort(digit_strings[2].begin(), digit_strings[2].end());
    sort(digit_strings[3].begin(), digit_strings[3].end());
    sort(digit_strings[4].begin(), digit_strings[4].end());
    sort(digit_strings[5].begin(), digit_strings[5].end());
    sort(digit_strings[6].begin(), digit_strings[6].end());
    sort(digit_strings[7].begin(), digit_strings[7].end());
    sort(digit_strings[8].begin(), digit_strings[8].end());
    sort(digit_strings[9].begin(), digit_strings[9].end());

    return digit_strings;
}

set<char> getSetOfLength(const vector<string> &signals, int n)
{
    for (const string &s : signals)
    {
        set<char> S(s.begin(), s.end());
        if (S.size() == n)
            return S;
    }
}

void solveTrivialByCount(const vector<string> &signals, Segment &seg)
{
    map<char, int> M;

    for (const auto &s : signals)
    {
        for (const auto &c : s)
        {
            ++M[c];
        }
    }

    for (const auto &each : M)
    {
        if (each.second == 4)
            seg.bottom_left = each.first;
        if (each.second == 6)
            seg.top_left = each.first;
        if (each.second == 9)
            seg.bottom_right = each.first;
    }
}

void solveTop(const vector<string> &signals, Segment &seg)
{
    set<char> S2 = getSetOfLength(signals, 2); // 1
    set<char> S3 = getSetOfLength(signals, 3); // 7

    for (const char &c : S2)
    {
        S3.erase(c);
    }

    seg.top = *S3.begin();
}

void solveTopRight(const vector<string> &signals, Segment &seg)
{
    set<char> S2 = getSetOfLength(signals, 2); // 1

    S2.erase(seg.bottom_right);

    seg.top_right = *S2.begin();
}

void solveCenter(const vector<string> &signals, Segment &seg)
{
    set<char> S4 = getSetOfLength(signals, 4); // 4

    S4.erase(seg.top_left);
    S4.erase(seg.top_right);
    S4.erase(seg.bottom_right);

    seg.center = *S4.begin();
}

void solveBottom(const vector<string> &signals, Segment &seg)
{
    set<char> S7 = getSetOfLength(signals, 7); // 0

    S7.erase(seg.top);
    S7.erase(seg.top_left);
    S7.erase(seg.top_right);
    S7.erase(seg.center);
    S7.erase(seg.bottom_left);
    S7.erase(seg.bottom_right);

    seg.bottom = *S7.begin();
}

int getValue(const vector<string> &digits, const Segment &seg)
{
    int result = 0;
    vector<string> digit_strings = getDigitStrings(seg);

    for (int i = 0; i < digits.size(); ++i)
    {
        string s = digits[i];
        sort(s.begin(), s.end());

        for (int ii = 0; ii < digit_strings.size(); ++ii)
        {
            if (s == digit_strings[ii])
            {
                result += (ii * pow(10, 3 - i));
                break;
            }
        }
    }
    return result;
}

int solve(const vector<string> &signals, const vector<string> &digits)
{
    Segment seg = {'.', '.', '.', '.', '.', '.', '.'};

    solveTrivialByCount(signals, seg);
    // Essentially:
    //    solveTopLeft();
    //    solveBottomLeft();
    //    solveBottomRight();

    solveTop(signals, seg);
    solveTopRight(signals, seg);
    solveCenter(signals, seg);
    solveBottom(signals, seg);

    int value = getValue(digits, seg);
    return value;
}

int main()
{
    string s;
    int result = 0;
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        stringstream ss;
        ss << s;

        string signal;
        vector<string> signals;

        for (int i = 0; i < 10; ++i)
        {
            ss >> signal;
            signals.push_back(signal);
        }

        char delim;
        ss >> delim;

        vector<string> digits;
        for (int i = 0; i < 4; ++i)
        {
            ss >> signal;
            digits.push_back(signal);
        }

        result += solve(signals, digits);
    }
    cout << result << endl;

    return 0;
}