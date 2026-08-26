#include <iostream>
using namespace std;

class Shape {
protected:
    int numberOfSides;
    double area;

public:
    Shape(int sides) {
        numberOfSides = sides;
        area = 0.0;
    }

    int getNumberOfSides() const {
        return numberOfSides;
    }

    double getArea() const {
        return area;
    }

    void setNumberOfSides(int sides) {
        numberOfSides = sides;
    }

    void setArea(double a) {
        area = a;
    }
};

class Rectangle : public Shape {
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape(4) {
        length = l;
        width = w;
    }

    void generateArea() {
        area = length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : Shape(0) {
        radius = r;
    }

    void generateArea() {
        area = 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double height;
    double base;

public:
    Triangle(double h, double b) : Shape(3) {
        height = h;
        base = b;
    }

    void generateArea() {
        area = (height * base) / 2;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
    }

    void checkSides() {
        if (length == width)
            cout << "All sides are equal." << endl;
        else
            cout << "Sides are not equal." << endl;
    }

    void generateArea() {
        area = length * width;
    }
};

int main(void) {
    Rectangle rect(5, 3);
    rect.generateArea();
    cout << "Rectangle Area: " << rect.getArea() << endl;

    Circle circ(4);
    circ.generateArea();
    cout << "Circle Area: " << circ.getArea() << endl;

    Triangle tri(6, 4);
    tri.generateArea();
    cout << "Triangle Area: " << tri.getArea() << endl;

    Square sq(5);
    sq.generateArea();
    sq.checkSides();
    cout << "Square Area: " << sq.getArea() << endl;

    return 0;
}