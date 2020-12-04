#include <bits/stdc++.h>

using namespace std;

// todo debug stackAB, fully nested bowls are tricky, see 2nd example
double stackAB(vector<double> const & height,
        vector<double> const & bottom,
        vector<double> const & top, int a, int b) { // b on a
    if (bottom[b] >= top[a]) {
        return height[b];
    } else {
        // check for angle/slope
        double angle_a = (top[a] - bottom[a]) / height[a];
        double angle_b = (top[b] - bottom[b]) / height[b];

        if (angle_a > angle_b) { // b fits in a without rims touching
            if (bottom[b] <= bottom[a]) {
                return max(0.0, height[b] - height[a]);
            } else {
                return max(0.0, height[b] - (height[a] - ((bottom[b] - bottom[a]) * angle_a)));
            }
        } else if (top[b] > top[a]){
            double x = (top[a] - bottom[b]) / angle_b;
            return max(0.0, height[b] - angle_b * x);
        } else { // top[b] fits inside a
            return 0.0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int bowls;
        cin >> bowls;

        vector<double> height(bowls);
        vector<double> bottom(bowls);
        vector<double> top(bowls);
        vector<int> order(bowls);
        for (int i = 0; i < bowls; i++) {
            cin >> height[i] >> bottom[i] >> top[i];
            order[i] = i;
        }

        double min_height = INT_MAX;
        do { // stacking here
            double current_height = 0;
            int b; // bowl
            for (int i = 0; i < bowls; i++) {
                if (current_height > min_height) {
                    break;
                }
                b = order[i];
                if (i == 0) {
                    current_height = height[b];
                    cout << "first: " << height[b] << endl;
                } else {
                    current_height += stackAB(height, bottom, top, order[i-1], b);
                    cout << "update: " << current_height << endl;
                }
            }
            cout << "--------------" << endl;
            cout << "current: " << current_height << endl;
            cout << "min: " << min_height << endl;
            cout << "--------------" << endl;
            min_height = min(current_height, min_height);
        } while (next_permutation(order.begin(), order.end()));
        cout << min_height << endl;
    }
    return 0;
}