#include <iostream>

using namespace std;

int main()
{
    int k;
    int x1, y1, x2, y2;
    while(cin>>k)
    {
        cin >> x1 >> y1;

        for (int i=0; i < k; i++) {
            cin >> x2 >> y2;
            if (x1 == x2 || y1 == y2) {
                cout << "divisa";
            } else if (x1 < x2 && y1 < y2) {
                cout << "NE";
            } else if (x1 < x2 && y1 > y2) {
                cout << "SE";
            } else if (x1 > x2 && y1 < y2) {
                cout << "NO";
            } else { //if (x1 > x2 && y1 > y2) {
                cout << "SO";
            }
            cout << endl;
        }
    }
}