#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        double A, B, X, Y;
        cin >> A >> B >> X >> Y;

        double t_chef = A / X;
        double t_chefina = B / Y;

        if (t_chef < t_chefina)
        {
            cout << "Chef\n";
        }
        else if (t_chef > t_chefina)
        {
            cout << "Chefina\n";
        }
        else
        {
            cout << "Both\n";
        }
    }
}