#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account() {
        cout << "Enter balance: ";
        cin >> balance;
    }

    Account(double b) : balance(b) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance" << endl;
    }

    void checkBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class InterestAccount : virtual public Account {
protected:
    double interest;

public:
    InterestAccount() : Account(), interest(0.30) {}

    InterestAccount(double b, double i = 0.30) : Account(b), interest(i) {}

    void deposit(double amount) override {
        balance += amount + (amount * interest);
    }
};

class ChargingAccount : virtual public Account {
protected:
    double fee;

public:
    ChargingAccount() : Account(), fee(25) {}

    ChargingAccount(double b, double f = 25) : Account(b), fee(f) {}

    void withdraw(double amount) override {
        double total = amount + fee;
        if (total <= balance)
            balance -= total;
        else
            cout << "Insufficient balance" << endl;
    }
};

class ACI : public InterestAccount, public ChargingAccount {
public:
    ACI(double b)
        : Account(b), InterestAccount(b), ChargingAccount(b) {}

    void transfer(double amount, Account &acc) {
        if (amount <= balance) {
            balance -= amount;
            acc.deposit(amount);
        } else {
            cout << "Transfer failed" << endl;
        }
    }

    void transfer(double amount, InterestAccount &acc) {
        if (amount <= balance) {
            balance -= amount;
            acc.deposit(amount);
        } else {
            cout << "Transfer failed" << endl;
        }
    }

    void transfer(double amount, ChargingAccount &acc) {
        if (amount <= balance) {
            balance -= amount;
            acc.deposit(amount);
        } else {
            cout << "Transfer failed" << endl;
        }
    }
};

int main(void) {
    InterestAccount ia(1000);
    ChargingAccount ca(1000);
    ACI aci(2000);

    ia.deposit(500);
    ia.checkBalance();

    ca.withdraw(200);
    ca.checkBalance();

    aci.transfer(300, ia);
    aci.checkBalance();
    ia.checkBalance();

    return 0;
}