#include <iostream>
using namespace std;

class Calculator {
private:
    double Num1, Num2, Num3;

public:
    Calculator(double n1, double n2, double n3) {
        Num1 = n1;
        Num2 = n2;
        Num3 = n3;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(double a, double b, double c) {
        return a + b + c;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double multiply(double a, double b, double c) {
        return a * b * c;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double divide(double a, double b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Division by zero not allowed." << endl;
            return 0;
        }
    }

    void demonstrate() {
        cout << "Add (2 numbers): " << add(Num1, Num2) << endl;
        cout << "Add (3 numbers): " << add(Num1, Num2, Num3) << endl;
        cout << "Multiply (2 numbers): " << multiply(Num1, Num2) << endl;
        cout << "Multiply (3 numbers): " << multiply(Num1, Num2, Num3) << endl;
        cout << "Subtract: " << subtract(Num1, Num2) << endl;
        cout << "Divide: " << divide(Num1, Num2) << endl;
    }
};

int main(void) {
    double n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;

    Calculator calc(n1, n2, n3);
    calc.demonstrate();

    return 0;
}