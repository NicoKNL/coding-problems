#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int prof_id = 1;
int student_id = 1;

class Person {
protected:
    string name;
    int age;
    int cur_id;

public:
    virtual void putdata() {
        cout << "[WARNING] Calling putdata on Person..." << endl;
    }

    virtual void getdata() {
        cout << "[WARNING] Calling getdata on Person..." << endl;
    }
};

class Professor : public Person {
    int publications;

public:
    void putdata() {
        printf("%s %d %d %d\n", name.c_str(), age, publications, cur_id);
    }

    void getdata() {
        cin >> name >> age >> publications;
        cur_id = prof_id;
        prof_id++;
    }
};

class Student : public Person {
    int marks[6];
    int cumulativeMark() {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        return sum;
    }

public:
    void putdata() {
        printf("%s %d %d %d\n", name.c_str(), age, cumulativeMark(), cur_id);
    }

    void getdata() {
        cin >> name >> age >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4] >> marks[5];
        cur_id = student_id;
        student_id++;
    }


};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
