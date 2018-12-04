//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//void oneRun()
//{
//    int n;
//    cin >> n;
//    int s[n];
//
//    int students = 0;
//    for (int i = 0; i < n; i++) {
//        cin >> s[i];
//        students += s[i];
//    }
//
//    int solution[n];
//
//    for (int i = 0; i < n; i++) {
//        int students_above = students;
//        int minimum_anger = 0;
//        for (int j = 0; j <= i; j++) {
//            students_above -= s[j];
//
//            if (i == j) {
//                // At the end of the "recursion"
//                solution[i] = min(minimum_anger, solution[j-1]+s[j-1]) + students_above;
//            } else {
//                minimum_anger = min(minimum_anger, students_above);
//            }
//        }
//    }
//
//    cout << solution[n-1] << endl;
//}
//
//int main()
//{
//    int n_cases;
//    cin >> n_cases;
//    while (n_cases--) oneRun();
//    return 0;
//}

#include <iostream>

using namespace std;

void test() {
    int nfloors; // number of floors
    cin >> nfloors;
    int students[nfloors + 1]; // number of students per floor
    students[0] = 0;
    for (int i = 1; i <= nfloors; i++) {
        cin >> students[i];
    }

    //creating table who needs to go to a floor on or below
    int till[nfloors + 1];
    till[0] = 0;
    for (int i = 1; i <= nfloors; i++) {
        till[i] = till[i - 1] + students[i];
    }
    //creating table who needs to go to a floor on or above
    int from[nfloors + 2];
    from[nfloors + 1] = 0;
    for (int i = nfloors; i >= 0; i--) {
        from[i] = from[i + 1] + students[i];
    }



    int table[nfloors + 1][nfloors + 1]; // x , y

    table[0][0] = 0;

    for (int x = 1; x <= nfloors; x++) {
        for (int y = 0; y < x; y++) {
            if (x == y + 1) {
                int miny = table[y][0];
                for (int z = 1; z < y; z++) {
                    if (table[y][z] < miny) {
                        miny = table[y][z];
                    }
                }
                table[x][y] = miny + from[x+1];
            } else {
                table[x][y] = table[x - 1][y] - students[x] + till[x - 1] - till[y];
            }
        }
    }

    for (int x = 0; x <= nfloors; x++) {
        cout << "x = " << x << " : ";
        for (int y = 0; y < x; y++) {
            cout << table[x][y] << "  ";
        }
        cout << endl;
    }


    int minres = table[nfloors][0]; // minimum total lift anger
    for (int y = 1; y < nfloors; y++) {
        if (table[nfloors][y] < minres) {
            minres = table[nfloors][y];
        }
    }

    cout << minres << endl;

}


int main() {
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        test();
    }
}