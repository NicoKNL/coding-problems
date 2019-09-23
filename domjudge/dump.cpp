#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int target;
    int weight;

};

struct Node { // edits
    int dist;
    Node* parent;
};
