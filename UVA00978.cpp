#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, b, sg, sb, tmp;
    multiset<int, greater<int>> green, blue;
    vector<int> green_winners, blue_winners;
    cin >> n;
    while (n--) {
        cin >> b >> sg >> sb;
        green.clear(); blue.clear();
        while (sg--) {
            cin >> tmp;
            green.insert(tmp);
        }

        while (sb--) {
            cin >> tmp;
            blue.insert(tmp);
        }

        while (green.size() > 0 && blue.size() > 0) {
            green_winners.clear(); blue_winners.clear();
            tmp = min(min(b, (int) green.size()), (int) blue.size());
            for (int i = 0; i < tmp; i++) {
                sg = *green.begin(); green.erase(green.begin());
                sb = *blue.begin(); blue.erase(blue.begin());
                if (sg > sb) green_winners.push_back(sg - sb);
                if (sg < sb) blue_winners.push_back(sb - sg);
            }
            for (auto gw: green_winners) green.insert(gw);
            for (auto bw: blue_winners) blue.insert(bw);
        }

        if (green.size() > blue.size()) {
            cout << "green wins" << endl;
            for (auto g: green) cout << g << endl;
        } else if (green.size() < blue.size()) {
            cout << "blue wins" << endl;
            for (auto b: blue) cout << b << endl;
        } else {
            cout << "green and blue died" << endl;
        }

        if (n) cout << endl;
    }
    return 0;
}