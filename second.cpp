#include <queue>
#include <vector>
#include <iostream>

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().weight << " ";
        q.pop();
    }
    std::cout << '\n';
}

struct Edge
{
    Edge(int w) {
        weight = w;
    }
    int weight;

    bool operator>(const Edge& other) const {
        return (other.weight > weight);
    }
};

int main() {
//    std::priority_queue<int> q;
//
//    for(int n : {1,8,5,6,3,4,0,9,7,2})
//        q.push(n);
//
//    print_queue(q);

//    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> q2;

    for(int n : { 2, 1, 2})// 1,8,5,6,3,4,0,9,7,2})
        q2.push(Edge(n));

    print_queue(q2);

    // Using lambda to compare elements.
//    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
//    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
//
//    for(int n : {1,8,5,6,3,4,0,9,7,2})
//        q3.push(n);
//
//    print_queue(q3);

}