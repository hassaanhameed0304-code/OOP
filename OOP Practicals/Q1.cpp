#include <iostream>

using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0; 
    
    virtual ~ArrayMultiplier() {}
};

class ArrayMultiplier1D : public ArrayMultiplier {
private:
    int* arr;
    int size;

public:
    ArrayMultiplier1D(int* a, int s) : arr(a), size(s) {}

    void calculate() override {
        long long product = 1;
        for (int i = 0; i < size; ++i) {
            product *= arr[i];
        }
        cout << "Product of 1D Array elements: " << product << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
private:
    int** arr;
    int rows;
    int cols;

public:
    ArrayMultiplier2D(int** a, int r, int c) : arr(a), rows(r), cols(c) {}

    void calculate() override {
        long long product = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                product *= arr[i][j];
            }
        }
        cout << "Product of 2D Array elements: " << product << endl;
    }
};

int main() {
    int arr1D[] = {2, 3, 4, 5};
    ArrayMultiplier1D mul1D(arr1D, 4);
    
    int rows = 2, cols = 3;
    int** arr2D = new int*[rows];
    int count = 1;
    for (int i = 0; i < rows; ++i) {
        arr2D[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            arr2D[i][j] = ++count;
        }
    }
    ArrayMultiplier2D mul2D(arr2D, rows, cols);

    cout << "--- Problem 1 Execution ---" << endl;
    mul1D.calculate();
    mul2D.calculate();
    cout << endl;

    for (int i = 0; i < rows; ++i) {
        delete[] arr2D[i];
    }
    delete[] arr2D;

    return 0;
}