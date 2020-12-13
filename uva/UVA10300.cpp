#include <iostream>
#include <iomanip>

using namespace std;

void run() {
    int farmers;
    cin >> farmers;

    int size, animals, value;
    double cost = 0.0;
    for (int f = 0; f < farmers; f++) {
        cin >> size >> animals >> value;

        double avg_space = (double) size / (double) animals;
        double animal_cost = avg_space * (double) value;
        cost += animal_cost * (double) animals;
    }
    cout << fixed << setprecision(0) << cost << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}