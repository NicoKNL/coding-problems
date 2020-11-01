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

void digitSum(string in) {
    long long sum = 0;
    for (char c : in) {
        sum += c - '0';
    }
    printf("SUM: %lld\n", sum);
}

int main()
{
    string result = "2";
    for (int i = 2; i <= 1000; ++i) {
        string tmp = result;
        for (int j = 0; j < tmp.length(); ++j) {
            result = addAndCarry(result, tmp[j] - '0', j);
        }
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
    digitSum(result);
}
