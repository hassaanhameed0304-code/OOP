#include <iostream>
using namespace std;

class base { // single base class
    int x;
public:
    void getdata() {
        cout << "Enter the value of x = ";
        cin >> x;
    }
    int getX() { return x; } // helper to access x if needed
};

class derive : public base { // single derived class
    int y;
public:
    void readdata() {
        cout << "Enter the value of y = ";
        cin >> y;
    }
    void product() {
        cout << "Product = " << getX() * y << endl;
    }
};

int main() {
    derive a; // object of derived class
    a.getdata();
    a.readdata();
    a.product();
    return 0;
}
