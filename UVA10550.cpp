#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string s;

    while(getline(cin, s))
    {
        istringstream input(s);
        int a, b, c, d;
        input >> a >> b >> c >> d;

        if (a == 0 && b == 0 && c == 0 && d == 0) break;

        int degrees = 0;
        int marks = 360 / 40;

        // Start rotating
        degrees += 360 * 2;

        int mark = a;
        int dist = 0;
        while (mark != b)
        {
            mark = (mark - 1);
            if (mark < 0) mark += 40;

            dist++;
        } ;

        degrees += dist * marks;

        // Rotate fully counterclockwise
        degrees += 360;

        mark = b;
        dist = 0;

        while (mark != c)
        {
            mark = (mark + 1) % 40;

            dist++;
        } ;


        degrees += dist * marks;

        mark = c;
        dist = 0;
        while (mark != d)
        {
            mark = (mark - 1);
            if (mark < 0) mark += 40;

            dist++;
        } ;

        degrees += dist * marks;

        cout << degrees << endl;


    }
    return 0;
}