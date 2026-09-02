#include <iostream>

using namespace std;

class Vehicle {
protected:
    int carId;
    string brand;
    string model;

public:
    Vehicle(int id, string b, string m) : carId(id), brand(b), model(m) {}

    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
    virtual void processReturn() = 0; 
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    bool available;

public:
    Car(int id, string b, string m) : Vehicle(id, b, m), available(true) {}

    bool isAvailable() override {
        return available;
    }

    void rent() override {
        if (available) {
            available = false;
            cout << brand << " " << model << " (ID: " << carId << ") has been successfully rented.\n";
        }
    }

    void processReturn() override {
        available = true;
        cout << brand << " " << model << " (ID: " << carId << ") has been successfully returned.\n";
    }
};

class RentalSystem {
public:
    void rentVehicle(Vehicle* v) {
        if (v->isAvailable()) {
            v->rent();
        } else {
            cout << "Rental failed. The selected vehicle is currently unavailable.\n";
        }
    }

    void returnVehicle(Vehicle* v) {
        v->processReturn();
    }
};

class Customer {
private:
    string name;

public:
    Customer(string n) : name(n) {}

    void rentVehicle(Vehicle* v, RentalSystem& system) {
        cout << name << " is initiating a rental process...\n";
        system.rentVehicle(v);
    }

    void returnVehicle(Vehicle* v, RentalSystem& system) {
        cout << name << " is initiating a return process...\n";
        system.returnVehicle(v);
    }
};

int main(void) {
    const int inventorySize = 3;
    Vehicle* inventory[inventorySize];

    inventory[0] = new Car(1001, "Toyota", "Corolla");
    inventory[1] = new Car(1002, "Honda", "Civic");
    inventory[2] = new Car(1003, "Ford", "Mustang");

    RentalSystem enterprise;
    Customer alice("Alice");

    alice.rentVehicle(inventory[0], enterprise);
    cout << "\n";

    alice.rentVehicle(inventory[0], enterprise);
    cout << "\n";

    alice.rentVehicle(inventory[2], enterprise);
    cout << "\n";

    alice.returnVehicle(inventory[0], enterprise);
    cout << "\n";
    
    alice.rentVehicle(inventory[0], enterprise);
    cout << "\n";

    for (int i = 0; i < inventorySize; ++i) {
        delete inventory[i];
    }

    return 0;
}