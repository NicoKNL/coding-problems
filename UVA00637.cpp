#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<vector<int>> front;
        vector<vector<int>> back;

        int sheets = n / 4;
        if (n % 4 > 0) sheets++;

        for (int i = 0; i < sheets; i++) {
            front.push_back(vector<int>{-1, -1});
            back.push_back(vector<int>{-1, -1});
        }

        int i = 0;
        int page_number = 1;
        while (i < sheets && page_number < n) {
            if (page_number < n) front[i][1] = page_number;
            page_number++;
            if (page_number < n) back[i][0] = page_number;
            page_number++;
        }
        
        cout << "Printing order for " << n << " pages:" << endl;
        for (int i = 0; i < sheets; i++) {
            cout << "Sheet " << i + 1 << ", front: " << front[i][0] << ", " << front[i][1] << endl;
            cout << "Sheet " << i + 1 << ", back : " << back[i][0] << ", " << back[i][1] << endl;
        }
    }
    return 0;
}