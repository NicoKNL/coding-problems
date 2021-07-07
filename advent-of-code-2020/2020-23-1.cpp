#include <bits/stdc++.h>
using namespace std;

int current_i = 0;
int current_cup = 0;
int target_i = 0;
int target_cup = 0;

vector<int> cups = {4, 6, 3, 5, 2, 8, 1, 7, 9};
vector<int> three_cups;

void pickUp()
{
    three_cups = vector<int>();
    vector<int> indices;
    for (int j = 1; j <= 3; ++j) {
        int offset_i = (current_i + j) % cups.size();
        indices.push_back(offset_i);
        three_cups.emplace_back(cups[offset_i]);
    }
    sort(indices.begin(), indices.end(), greater<int>());
    for (int index : indices) {
        cups.erase(cups.begin() + index);
    }
}

void selectTarget()
{
    target_cup = current_cup;
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
    
    for (int i = 0; i < cups.size(); ++i) {
        if (cups[i] == target_cup) {
            target_i = i;
            break;
        }
    }
}

void putBack()
{
    cups.insert(cups.begin() + target_i + 1, three_cups.begin(), three_cups.end());
}

void updateIndex()
{
    for (int i = 0; i < cups.size(); ++i) {
        if (cups[i] == current_cup) {
            current_i = (i + 1) % cups.size();
        }
    }
}

void rotate() {
    int i = 0;
    while (cups[i] != 1) {
        ++i;
    }

    rotate(cups.begin(), cups.begin() + i, cups.end());
}

int main() 
{
    for (int turn = 0; turn < 100; ++turn) {
        current_cup = cups[current_i];
        pickUp();
        selectTarget();
        putBack();
        updateIndex();
    }

    rotate();

    for (int i = 1; i < cups.size(); ++i) {
        cout << cups[i];
    }
}
