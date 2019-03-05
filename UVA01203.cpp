#include <iostream>
#include <string>
#include <queue>

using namespace std;
struct Query {
    long id;
    long interval;
    long next;
    Query(){};
    Query (long id, long interval, long next) {
        this->id = id;
        this->interval = interval;
        this->next = next;
    }
};

bool operator< (const Query &a, const Query &b) {
    if (a.next == b.next) {
        return a.id > b.id;
    } else {
        return a.next > b.next;
    }
}

int main() {
    priority_queue<Query> heap;
    string tmp;
    long id, interval;
    while (cin >> tmp) {
        if (tmp == "#") break;
        cin >> id >> interval;
        heap.push(Query(id, interval, interval));
    }

    int k;
    cin >> k;
    Query top;
    while (k--) {
        top = heap.top();
        cout << top.id << endl;
        heap.pop();
        heap.push(Query(top.id, top.interval, top.interval + top.next));
    }
    return 0;
}