#include <bits/stdc++.h>

using namespace std;
map<int, string> digits = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eightteen"},
        {19, "nineteen"},
        {20, "twenty"}
};

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string output;
    if (m == 0) {
        output += digits[h] + " o' clock";
    } else if (m == 15) {
        output += "quarter past " + digits[h];
    } else if (m == 30) {
        output += "half past " + digits[h];
    } else if (m == 45) {
        output += "quarter to " + digits[(h + 1) % 10];
    } else if (m < 30) {
        if (m <= 20) {
            output += digits[m];
        } else {
            output += digits[20] + " " + digits[m % 10];
        }

        if (m == 1) {
            output += " minute";
        } else {
            output += " minutes";
        }

        output += " past " + digits[h];
    } else { // 30 < m < 60
        h = (h + 1) % 12;
        m = 60 - m;
        if (m <= 20) {
            output += digits[m];
        } else {
            output += digits[20] + " " + digits[m % 10];
        }

        if (m == 1) {
            output += " minute";
        } else {
            output += " minutes";
        }
        output += " to " + digits[h];
    }
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
