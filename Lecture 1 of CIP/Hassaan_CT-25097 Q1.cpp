#include <iostream>
using namespace std;
void greet(string name){
	cout << "Hello " << name << endl;
}
void greet(string name,string greeting){
	cout << greeting << name << endl;
}
void greet(){
	cout << "Hello, Guest!" << endl;
}
int main(void){
	string name;
	greet(name = "Ali!");
	greet("Sara! ", "Hi, ");
	greet();
}