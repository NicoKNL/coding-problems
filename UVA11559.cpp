#include <iostream>

using namespace std;

int main() {
    long int participants, budget, hotels, weeks;

    while (cin >> participants >> budget >> hotels >> weeks) {
        unsigned long int cost = -1;
        bool found = false;
        for (int h = 0; h < hotels; h++) {
            unsigned long int price, beds, current_price;
            cin >> price;
            for (int w = 0; w < weeks; w++) {
                cin >> beds;
                if (beds >= participants) {
                    current_price = price * participants;
                    if (current_price < cost) {
                        cost = current_price;
                        found = true;
                    }
                }
            }
        }

        if (!found || cost > budget) {
            cout << "stay home" << endl;
        } else {
            cout << cost << endl;
        }
    }
    return 0;
}