#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
public:
    float width;
    float height;
public:
    Rectangle() {

    }

    void read_input() {
        cin >> this->width >> this->height;
    }

    void display() {
        printf("%d %d\n", (int)width, (int)height);
    }
};

class RectangleArea : public Rectangle {
public:
    RectangleArea() {

    }

    void display() {
        cout << width * height << endl;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}