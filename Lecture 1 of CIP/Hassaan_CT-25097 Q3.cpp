#include <iostream>
using namespace std;
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int main(void){
	int x = 6,y = 5;
	swap(x,y);
	cout << "Swap Successful!" <<endl;
	cout << "Value of X is " << x << " & " << "Value of Y is " << y << endl;
}