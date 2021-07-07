#include <bits/stdc++.h>
using namespace std;

list<int> cups = {4, 6, 3, 5, 2, 8, 1, 7, 9};
vector<list<int>::iterator> cup_pointers(10000001);
list<int> three_cups;

auto current_cup_it = cups.begin();
int target_cup = 0;

void pickUp()
{
    for (int j = 1; j <= 3; ++j) {
        auto it = current_cup_it;
        it = next(it);
        if (it == cups.end()) it = cups.begin();
        three_cups.splice(three_cups.end(), cups, it);
    }
}

void selectTarget()
{
    target_cup = *current_cup_it;
    bool valid = false;
    while (!valid) {
        --target_cup;
        if (target_cup < 1) {
            target_cup = cups.size() + 3;
        }
        valid = true;
        for (int cup : three_cups) {
            if (cup == target_cup) {
                valid = false;
                break;
            }
        }
    }
}

void putBack()
{
    auto it = cup_pointers[target_cup];
    it = next(it);
    cups.splice(it, three_cups);
}

int main() 
{
    for (int i = 10; i <= 1000000; ++i) {
        cups.push_back(i);
    }

    auto it = cups.begin();
    while (it != cups.end()) {
        cup_pointers[*it] = it;
        ++it;
    } 

    for (int turn = 0; turn < 10000000; ++turn) {
        pickUp();
        selectTarget();
        putBack();
        ++current_cup_it;
        if (current_cup_it == cups.end()) current_cup_it = cups.begin();
    }

    it = cups.begin();
    for (; it != cups.end(); ++it) {
        if (*it == 1) break;
    }

    long long cupmult = 1;
    ++it;
    cupmult *= (long long) (*it);
    ++it;
    cupmult *= (long long) (*it);
    cout << cupmult << endl;
}
