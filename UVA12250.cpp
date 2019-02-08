#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, string> m;
    m.insert(pair<string, string>("HELLO", "ENGLISH"));
    m.insert(pair<string, string>("HOLA", "SPANISH"));
    m.insert(pair<string, string>("HALLO", "GERMAN"));
    m.insert(pair<string, string>("BONJOUR", "FRENCH"));
    m.insert(pair<string, string>("CIAO", "ITALIAN"));
    m.insert(pair<string, string>("ZDRAVSTVUJTE", "RUSSIAN"));

    int case_number = 1;

    string input;
    while (true)
    {
        cin >> input;
        if (input == "#") break;
        if (m.find(input) == m.end()) {
            cout << "Case " << case_number << ": " << "UNKNOWN" << endl;
        } else {
            cout << "Case " << case_number << ": " << m.at(input) << endl;
        }
        case_number++;
    }

    return 0;
}