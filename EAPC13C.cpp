#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

double evenParser(int a, int b, int c, int d, char op1, char op2, char op3)
{
    double sum_a = 0.0;
    double sum_b = 0.0;
    double sum = 0.0;
    switch(op1) {
        case '+' :  sum_a = (double) a + (double) b;
                    break;
        case '-' :  sum_a = (double) a - (double) b;
                    break;
        case '*' :  sum_a = (double) a * (double) b;
                    break;
        case '/' :  sum_a = (double) a / (double) b;
                    break;
    }

    switch(op3) {
        case '+' :  sum_b = (double) c + (double) d;
            break;
        case '-' :  sum_b = (double) c - (double) d;
            break;
        case '*' :  sum_b = (double) c * (double) d;
            break;
        case '/' :  sum_b = (double) c / (double) d;
            break;
    }

    switch(op2) {
        case '+' :  sum = sum_a + sum_b;
            break;
        case '-' :  sum = sum_a - sum_b;
            break;
        case '*' :  sum = sum_a * sum_b;
            break;
        case '/' :  sum = sum_a / sum_b;
            break;
    }
    return sum;
};

double evenLeftParser(int a, int b, int c, int d, char op1, char op2, char op3)
{
    double sum = 0.0;
    switch(op2) {
        case '+' :  sum = ((double) b) + ((double) c);
            break;
        case '-' :  sum = ((double) b) - ((double) c);
            break;
        case '*' :  sum = ((double) b) * ((double) c);
            break;
        case '/' :  sum = ((double) b) / ((double) c);
            break;
    }

    switch(op1) {
        case '+' :  sum = ((double) a) + sum;
            break;
        case '-' :  sum = ((double) a) - sum;
            break;
        case '*' :  sum = ((double) a) * sum;
            break;
        case '/' :  sum = ((double) a) / sum;
            break;
    }

    switch(op3) {
        case '+' :  sum = sum + ((double) d);
            break;
        case '-' :  sum = sum - ((double) d);
            break;
        case '*' :  sum = sum * ((double) d);
            break;
        case '/' :  sum = sum / ((double) d);
            break;
    }
    return sum;
};

double evenRightParser(int a, int b, int c, int d, char op1, char op2, char op3)
{
    double sum = 0.0;
    switch(op2) {
        case '+' :  sum = ((double) b) + ((double) c);
            break;
        case '-' :  sum = ((double) b) - ((double) c);
            break;
        case '*' :  sum = ((double) b) * ((double) c);
            break;
        case '/' :  sum = ((double) b) / ((double) c);
            break;
    }

    switch(op3) {
        case '+' :  sum = sum + ((double) d);
            break;
        case '-' :  sum = sum - ((double) d);
            break;
        case '*' :  sum = sum * ((double) d);
            break;
        case '/' :  sum = sum / ((double) d);
            break;
    }

    switch(op1) {
        case '+' :  sum = ((double) a) + sum;
            break;
        case '-' :  sum = ((double) a) - sum;
            break;
        case '*' :  sum = ((double) a) * sum;
            break;
        case '/' :  sum = ((double) a) / sum;
            break;
    }

    return sum;
};

double leftParser(int a, int b, int c, int d, char op1, char op2, char op3)
{
    double sum = 0.0;
    switch(op1) {
        case '+' :  sum = ((double) a) + ((double) b);
            break;
        case '-' :  sum = ((double) a) - ((double) b);
            break;
        case '*' :  sum = ((double) a) * ((double) b);
            break;
        case '/' :  sum = ((double) a) / ((double) b);
            break;
    }

    switch(op2) {
        case '+' :  sum = sum + ((double) c);
            break;
        case '-' :  sum = sum - ((double) c);
            break;
        case '*' :  sum = sum * ((double) c);
            break;
        case '/' :  sum = sum / ((double) c);
            break;
    }

    switch(op3) {
        case '+' :  sum = sum + ((double) d);
            break;
        case '-' :  sum = sum - ((double) d);
            break;
        case '*' :  sum = sum * ((double) d);
            break;
        case '/' :  sum = sum / ((double) d);
            break;
    }

    return sum;
};

double rightParser(int a, int b, int c, int d, char op1, char op2, char op3)
{
    double sum = 0.0;
    switch(op3) {
        case '+' :  sum = ((double) c) + ((double) d);
            break;
        case '-' :  sum = ((double) c) - ((double) d);
            break;
        case '*' :  sum = ((double) c) * ((double) d);
            break;
        case '/' :  sum = ((double) c) / ((double) d);
            break;
    }
    switch(op2) {
        case '+' :  sum = ((double) b) + sum;
            break;
        case '-' :  sum = ((double) b) - sum;
            break;
        case '*' :  sum = ((double) b) * sum;
            break;
        case '/' :  sum = ((double) b) / sum;
            break;
    }

    switch(op1) {
        case '+' :  sum = ((double) a) + sum;
            break;
        case '-' :  sum = ((double) a) - sum;
            break;
        case '*' :  sum = ((double) a) * sum;
            break;
        case '/' :  sum = ((double) a) / sum;
            break;
    }

    return sum;
};

void oneRun()
{
    int input[4];
    string ops = "+-/*";
    for (int i = 0; i < 4; i++) cin >> input[i];
    sort(input, input+4); // Sort for the permutation stuff

    char op1;
    char op2;
    char op3;

    double even;
    double left;
    double right;
    double evenLeft;
    double evenRight;
    do {
        for (int k = 0; k < 4; k++) { // op1
            op1 = ops[k];
            for (int m = 0; m < 4; m++) { // op2
                op2 = ops[m];
                for (int n = 0; n < 4; n++) { // op3
                    op3 = ops[n];
                    even = evenParser(input[0], input[1], input[2], input[3], op1, op2, op3);
                    left = leftParser(input[0], input[1], input[2], input[3], op1, op2, op3);
                    evenLeft = evenLeftParser(input[0], input[1], input[2], input[3], op1, op2, op3);
                    right = rightParser(input[0], input[1], input[2], input[3], op1, op2, op3);
                    evenRight = evenRightParser(input[0], input[1], input[2], input[3], op1, op2, op3);
                    if (abs(even - 24.0) < 0.00001 ||
                        abs(left - 24.0) < 0.00001 ||
                        abs(evenLeft- 24.0) < 0.00001 ||
                        abs(evenRight - 24.0) < 0.00001 ||
                        abs(right - 24.0) < 0.00001) {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }

    } while (next_permutation(input, input+4));
    cout << "NO" << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}