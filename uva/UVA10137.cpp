#include <bits/stdc++.h>

using namespace std;

int main() {
    int students;
    while(cin >> students) {
        if (students == 0) break;

        double avg = 0.0;
        vector<double> money(students);
        for (int i = 0; i < students; i++) {
            cin >> money[i];
            avg += money[i];
        }

        avg = avg / students;
        double diff_a = 0;
        double diff_b = 0;
        for (int i = 0; i < students; i++) {
            if (money[i] > avg) {
                diff_a += (floor((money[i] - avg) * 100)) / 100;
            } else if (money[i] < avg){
                diff_b += (floor((avg - money[i]) * 100)) / 100;
            }
        }
        if (diff_b < diff_a) diff_b = diff_a;
        cout << "$" << fixed << setprecision(2) << diff_b << endl;
    }

    return 0;
}