#include <iostream>
#include <stack>

using namespace std;
// TODO: finish
int main() {
    bool reset = false;
    while (true) {
        stack<int> s;
        int n;
        int input;
        cin >> n;
        if (n == 0) {
            break;
        }

        if (reset) {
            cout << endl;
            reset = false;
        }
        cin >> input;
        int counter = 1;
        while (counter <= n) {
            s.push(counter);
            while (!s.empty()) {
                if (s.top() == input) {
                    s.pop();
                    cin >> input;
                    if (input == 0) reset = true;
                } else {
                    break;
                }
            }
            counter++;
        }


        if (s.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}