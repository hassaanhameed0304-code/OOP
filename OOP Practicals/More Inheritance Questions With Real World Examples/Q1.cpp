#include <iostream>
using namespace std;

class Vehicle{
protected:
    string type;
    string make;
    string model;
    string color;
    int year;
    int miles;

public:
    Vehicle(string t, string mk, string mdl, string clr, int y, int m)
        : type(t), make(mk), model(mdl), color(clr), year(y), miles(m) {}

    void displayVehicle() {
        cout << "Type: " << type << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Miles Driven: " << miles << endl;
    }
};

class GasVehicle : public Vehicle {
protected:
    int fuelTankSize;

public:
    GasVehicle(string t, string mk, string mdl, string clr, int y, int m, int f)
        : Vehicle(t, mk, mdl, clr, y, m), fuelTankSize(f) {}

    void displayGas() {
        cout << "Fuel Tank Size: " << fuelTankSize << endl;
    }
};

class ElectricVehicle : public Vehicle {
protected:
    int energyStorage;

public:
    ElectricVehicle(string t, string mk, string mdl, string clr, int y, int m, int e)
        : Vehicle(t, mk, mdl, clr, y, m), energyStorage(e) {}

    void displayElectric() {
        cout << "Energy Storage: " << energyStorage << endl;
    }
};

class HeavyVehicle : public GasVehicle {
protected:
    int maxWeight;
    int wheels;
    float length;

public:
    HeavyVehicle(string t, string mk, string mdl, string clr, int y, int m,
                 int f, int mw, int w, float l)
        : GasVehicle(t, mk, mdl, clr, y, m, f),
          maxWeight(mw), wheels(w), length(l) {}

    void displayHeavy() {
        cout << "Max Weight: " << maxWeight << endl;
        cout << "Wheels: " << wheels << endl;
        cout << "Length: " << length << endl;
    }
};

class Bus : public HeavyVehicle {
private:
    int seats;

public:
    Bus(string t, string mk, string mdl, string clr, int y, int m,
        int f, int mw, int w, float l, int s)
        : HeavyVehicle(t, mk, mdl, clr, y, m, f, mw, w, l), seats(s) {}

    void display() {
        displayVehicle();
        displayGas();
        displayHeavy();
        cout << "Number of Seats: " << seats << endl;
    }
};

int main(void){
    Bus b("Bus", "Toyota", "Coaster", "White", 2020, 50000,
          60, 8000, 6, 7.5, 30);

    b.display();

    return 0;
}