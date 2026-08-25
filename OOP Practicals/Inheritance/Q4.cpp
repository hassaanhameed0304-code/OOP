#include <iostream>
using namespace std;

class Item{
protected:
    string Name;
    int Quantity;
public:
    void setName(string name){ 
		Name = name; 
	}
    void setQuantity(int qty){ 
		Quantity = qty; 
	}
    string getName(){ 
		return Name; 
	}
    int getQuantity(){ 
		return Quantity; 
	}
};

class BakedGoods : public Item{
protected:
    double Discount = 0.10; 
};

class Cakes : public BakedGoods{
private:
    double Price = 600;
public:
    double calculatePrice(){
        double total = Price * Quantity;
        total = total - (total * Discount);
        return total;
    }
};

class Bread : public BakedGoods{
private:
    double Price = 200;
public:
    double calculatePrice(){
        double total = Price * Quantity;
        total = total - (total * Discount);
        return total;
    }
};

class Drinks : public Item{
private:
    double Discount = 0.05;
    double Price = 100;
public:
    double calculatePrice(){
        double total = Price * Quantity;
        total = total - (total * Discount);
        return total;
    }
};

int main(void){
    int qty;
    double totalBill = 0;

    Cakes cake;
    cout << "Enter quantity of Cakes: ";
    cin >> qty;
    cake.setQuantity(qty);
    totalBill += cake.calculatePrice();

    Bread bread;
    cout << "Enter quantity of Bread: ";
    cin >> qty;
    bread.setQuantity(qty);
    totalBill += bread.calculatePrice();

    Drinks drink;
    cout << "Enter quantity of Drinks: ";
    cin >> qty;
    drink.setQuantity(qty);
    totalBill += drink.calculatePrice();

    cout << "\nTotal Bill: " << totalBill << " Rs" << endl;

    return 0;
}
