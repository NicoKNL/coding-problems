#include <iostream>
#include <stack>

using namespace std;

int main() {
    bool reset = true;
    int n;
    int input;
    while (true) {
        stack<int> s;

        if (reset) {
            reset = false;
            cin >> n;
            if (n == 0) {
                break;
            }
        }

        cin >> input;
        if (input == 0) {
            reset = true;
            cout << endl;
            continue;
        }
        int input_counter = 1;
        int counter = 1;
        while (counter <= n) {
            s.push(counter);
            while (!s.empty()) {
                if (s.top() == input) {
                    s.pop();

                    if (input_counter < n) {
                        cin >> input;
                        input_counter++;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            counter++;
        }

        while (input_counter < n) {
            cin >> input;
            input_counter++;
        }

        if (s.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}