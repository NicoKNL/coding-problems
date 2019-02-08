#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run(int case_number)
{
    vector<int> salaries(3);
    for (int i=0; i<3;i++) {
        cin >> salaries[i];
    }

    sort(salaries.begin(), salaries.end());
    cout << "Case " << case_number << ": " << salaries[1] << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        run(i+1);
    }
    return 0;
}