#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int total_knights = N * N / 2;
    if (N * N & 1)
        ++total_knights;

    if (total_knights % 2 == 1)
    {
        cout << "first" << endl;
    }
    else
    {
        cout << "second" << endl;
    }
}