#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Data {
    string name;
    int low;
    int high;
};

int main() {
    int n, d, low, high, q, price;
    string brand;
    vector<Data> db; // database
    cin >> n;
    while (n--) {
        db.clear(); // reset database
        cin >> d;
        while (d--) {
            cin >> brand >> low >> high;
            db.push_back(Data {brand, low, high});
        }

        cin >> q;
        while (q--) {
            Data holder = {"", -1, -1};
            cin >> price;
            for (auto entry: db) {
                if (entry.low <= price && price <= entry.high) {
                    if (holder.low == -1 ) {
                        holder = entry;
                    } else {
                        holder = Data {"", -1, -1};
                        break;
                    }
                }
            }
            if (holder.low == -1) {
                cout << "UNDETERMINED" << endl;
            } else {
                cout << holder.name << endl;
            }
        }
        if (n) cout << endl;
    }

    return 0;
}