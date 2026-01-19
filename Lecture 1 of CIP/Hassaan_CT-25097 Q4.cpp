#include <iostream>
using namespace std;
int main(void) {
	int n;
	cout << "Enter Value For Size Of The Array " << endl;
	cin >> n;
	int* arr = new int [n];
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cout << "Enter Values for the Array" << endl;
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "The Total is " << sum;
	delete[] arr;
	return 0;
}