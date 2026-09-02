#include <iostream>

using namespace std;

class Store {
protected:
    double total_bill;

public:
    Store(double bill) : total_bill(bill) {}

    virtual void calculateFinalBill() = 0;

    virtual ~Store() {}
};

class ImtiazStore : public Store {
public:
    ImtiazStore(double bill) : Store(bill) {}

    void calculateFinalBill() override {
        double discount = total_bill * 0.07;
        double final_bill = total_bill - discount;
        cout << "ImtiazStore Original Bill: $" << total_bill << endl;
        cout << "ImtiazStore Final Bill (7% off): $" << final_bill << "\n" << endl;
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(double bill) : Store(bill) {}

    void calculateFinalBill() override {
        double discount = total_bill * 0.05;
        double final_bill = total_bill - discount;
        cout << "BinHashimStore Original Bill: $" << total_bill << endl;
        cout << "BinHashimStore Final Bill (5% off): $" << final_bill << endl;
    }
};

int main(void) {
    double initial_purchase_amount = 1500.00;

    Store* store1 = new ImtiazStore(initial_purchase_amount);
    Store* store2 = new BinHashimStore(initial_purchase_amount);

    cout << "--- Problem 2 Execution ---" << endl;
    store1->calculateFinalBill();
    store2->calculateFinalBill();

    delete store1;
    delete store2;

    return 0;
}