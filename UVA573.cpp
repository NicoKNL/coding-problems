#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double height, climb, slide, fatigue;

    while(cin >> height >> climb >> slide >> fatigue) {
        if (height == 0) break;

        double climb_decay = fatigue * climb / 100.0;
        double tracked_height = 0;
        int day = 1;
        while (0 <= tracked_height && tracked_height < height) {
            tracked_height += climb;
            if (tracked_height > height) break;

            tracked_height -= slide;
            if (tracked_height < 0) break;

            climb -= climb_decay;
            climb = max(0.0, climb);
            day++;
        }

        if (tracked_height <= 0) {
            cout << "failure on day " << day << endl;
        } else {
            cout << "success on day " << day << endl;
        }
    }

    return 0;
}