#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Bowl {
    int i;
    double height;
    double radius_bottom;
    double radius_top;

    bool operator<(const Bowl&a) const {
        return i < a.i;
    }
};

int stack(vector<Bowl> bowls) {
    double height = bowls[0].height;


    // TODO: Stacking logic nog function yet...  slope comparisons vs base comparisons and the mix of the options..
    Bowl bottom;
    Bowl top;
    double bottom_slope;
    double top_slope;
    double base_offset;
    double rim_offset;
    for (int i = 1; i < bowls.size(); i++) {
        bottom = bowls[i - 1];
        top = bowls[i];

        if (bottom.radius_top <= top.radius_bottom) {  // They can only stack on top of eachother
            height += top.height;
        } else { // They stack with overlap
            bottom_slope = bottom.height / (bottom.radius_top - bottom.radius_bottom);
            top_slope = top.height / (top.radius_top - top.radius_bottom);

            if (bottom_slope < top_slope && bottom.radius_bottom > top.radius_bottom) { // They fully stack inside of eachother
                height -= bottom.height;
                height += top.height;
            } else {
                base_offset = min(bottom.height, (top.radius_bottom - bottom.radius_bottom) * bottom_slope); // First shift bases
                rim_offset = min(bottom.height, top_slope / bottom_slope * bottom.height);
                height += max(base_offset, rim_offset);
            }
        }
    }
    return (int) height;
}

void oneRun()
{
    int n_bowls;
    cin >> n_bowls;

    vector<Bowl> bowls;

    int i = 0;
    while (n_bowls--) {
        Bowl b;
        b.i = i;
        cin >> b.height;
        cin >> b.radius_bottom;
        cin >> b.radius_top;
        bowls.push_back(b);
        i++;
    }

    sort(bowls.begin(), bowls.end()); // Ensure Bowl vector is sorted

    int min_height;
    int iter_index = 0;
    do {
        cout << "iter index: " << iter_index << endl;
        if (iter_index == 0) {
            min_height = stack(bowls);
        } else {
            min_height = min(min_height, stack(bowls));
        }
        iter_index++;
    } while (next_permutation(bowls.begin(), bowls.end()));
    cout << min_height << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}