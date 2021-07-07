#include <iostream>

using namespace std;

void run()
{
    long int a, b;

    cin >> a >> b;

    if (a == b) {
        cout << "=";
    } else if (a > b) {
        cout << ">";
    } else {
        cout << "<";
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    while(n--) run();

    return 0;
}