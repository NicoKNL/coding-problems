#include <bits/stdc++.h>
using namespace std;


string addAndCarry(string in, int add, int start) {
    if (start >= in.size()) {
        in += ('0' + (add % 10));
    } else {
        int a = in[start] - '0';
        int b = add % 10;

        in[start] = '0' + ((a + b) % 10);
        add = add + ((a + b) / 10) * 10;
    }

    add = add / 10;
    if (add > 0) {
        in = addAndCarry(in, add, start + 1);
    }

    return in;
}

string addStrings(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < b.length(); ++i) {
        a = addAndCarry(a, b[i] - '0', i);
    }

    reverse(a.begin(), a.end());
    return a;
}

void digitSum(string in) {
    long long sum = 0;
    for (char c : in) {
        sum += c - '0';
    }
    printf("SUM: %lld\n", sum);
}

int main()
{
    string result = "1";
    for (int i = 2; i <= 100; ++i) {
        string tmp = result;
        for (int j = 1; j < i; ++j) {
            result = addStrings(result, tmp);
        }
        cout << result << endl;
    }
    digitSum(result);
}
