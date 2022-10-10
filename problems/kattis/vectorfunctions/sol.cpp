#include "vectorfunctions.h"

#include <algorithm>
#include <numeric>

using namespace std;

// Reverse a vector.
// Note that it is sent as a reference, so you should
// reverse the same vector that was sent in.
void backwards(vector<int> &vec)
{
    reverse(vec.begin(), vec.end());
}

// Return every other element of the vector, starting with the first.
// You should return a new vector with the answer.
// You are not allowed to modify the vector, even though it is
// sent as a reference. Therefore, the parameter is declared "const".
vector<int> everyOther(const vector<int> &vec)
{
    vector<int> other;

    for (int i = 0; i < vec.size(); ++i)
    {
        if (i % 2 == 0)
            other.push_back(vec[i]);
    }

    return other;
}

// Return the smallest value of a vector.
int smallest(const vector<int> &vec)
{
    return *min_element(vec.begin(), vec.end());
}

// Return the sum of the elements in the vector.
int sum(const vector<int> &vec)
{
    return accumulate(vec.begin(), vec.end(), 0);
}

// Return the number of odd integers, that are also on an
// odd index (with the first index being 0).
int veryOdd(const vector<int> &vec)
{
    int count = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i % 2 == 1)
            if (vec[i] % 2 == 1)
                ++count;
    }
    return count;
}