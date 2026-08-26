#include <iostream>
using namespace std;

class Vector {
private:
    double x;
    double y;

public:
    Vector(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector& other) {
        return Vector(x - other.x, y - other.y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main(void) {
    Vector v1(3, 4);
    Vector v2(1, 2);

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;

    cout << "Vector 1: ";
    v1.display();

    cout << "Vector 2: ";
    v2.display();

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    difference.display();

    return 0;
}