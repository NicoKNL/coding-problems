#include "heap.h"
#include <queue>

using namespace std;

priority_queue<int> Q;

int getMax()
{
    return Q.top();
}

int getSize()
{
    return Q.size();
}

void insert(int element)
{
    Q.push(element);
}

void removeMax()
{
    Q.pop();
}