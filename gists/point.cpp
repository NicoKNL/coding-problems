#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct pt {
    T x, y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};}
    // ^ only for floating-point ^
};

// Equality testing
bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

// 2D point vector length
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

// -1 if negative, 0 for zero, 1 for positive numbers
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

// print points
ostream& operator<<(ostream& os, pt p) {
    return os << "(" << p.x << "," << p.y << ")";
}

// example
int main() {
    pt a{2, 3};
    pt b{5, 2};
    cout << a+b << " " << a-b << endl;
    return 0;
}