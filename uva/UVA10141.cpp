#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, p;
    int rfp = 1;
    string tmp;
    istringstream ss_in;
    while (getline(cin, tmp)) {
        ss_in.clear();
        ss_in.str(tmp);
        ss_in >> n >> p;
        if (n == 0 && p == 0) break;

        // Consume irrelevant strings
        for (int i = 0; i < n; i++) {
            getline(cin, tmp);
        }
        string best_proposal_name;
        double best_compliance = -1.0;
        double best_price = 100000000000000000;

        string name;
        double price;
        double compliance;
        int rp;
        for (int i = 0; i < p; i++) {
            getline(cin, name);
            getline(cin, tmp);

            ss_in.clear();
            ss_in.str(tmp);
            ss_in >> price >> rp;

            compliance = (double) rp / (double) n;
            if (compliance > best_compliance || (compliance == best_compliance && price < best_price)) {
                best_proposal_name = name;
                best_compliance = compliance;
                best_price = price;
            }

            // Consume irrelevant strings
            for (int r = 0; r < rp; r++) {
                getline(cin, tmp);
            }
        }

        if (rfp > 1) cout << endl;
        cout << "RFP #" << rfp << endl;
        cout << best_proposal_name << endl;
        rfp++;
    }
}