#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        double alice_dist, alice_time, bob_dist, bob_time;
        cin >> alice_dist >> alice_time >> bob_dist >> bob_time;

        double speed_alice = alice_dist / alice_time;
        double speed_bob = bob_dist / bob_time;

        if (speed_alice > speed_bob)
        {
            cout << "Alice" << endl;
        }
        else if (speed_alice < speed_bob)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Equal" << endl;
        }
    }

    return 0;
}