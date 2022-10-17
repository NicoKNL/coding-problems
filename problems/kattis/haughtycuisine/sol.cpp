#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int M;
    cin >> M;
    vector<string> recommendations(M, "");
    for (int i = 0; i < M; ++i)
        cin >> recommendations[i];

    for (int i = 1; i < N; ++i)
    {
        int items;
        cin >> items;
        for (int ii = 0; ii < items; ++ii)
        {
            string s;
            cin >> s;
        }
    }

    cout << M << endl;

    for (auto each : recommendations)
        cout << each << endl;

    return 0;
}