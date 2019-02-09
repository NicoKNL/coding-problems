#include <iostream>

using namespace std;

int main() {
    int months;
    int month;
    double downpayment;
    double payment;
    double loan;
    double value;
    int depreciations;
    double depr[100];
    while (true) {
        cin >> months >> downpayment >> loan >> depreciations;
        if (months < 0) break;

        /* Initialize depreciations */
        for (int i = 0; i < depreciations; i++) {
            if (i == 0) {
                cin >> month >> depr[0];
            } else {
                cin >> month >> depr[month];
                for (int j = month; j < 100; j++) {
                    depr[j] = depr[month];
                }
            }
        }

        /* Calculation */
        value = loan + downpayment;
        payment = loan / (double) months;
        int month_count = 0;
        for (int m = 0; m < months; m++) {
            value = value * (1.0 - depr[m]);

            if (m > 0) loan -= payment;

            if (value > loan) {
                break;
            }

            month_count++;
        }

        if (month_count == 1) {
            cout <<  month_count << " month" << endl;
        } else {
            cout <<  month_count << " months" << endl;
        }
    }
    return 0;
}