// Given an array of integers, 
// return a new array such that each element at index i of the new array is the product of all the numbers 
// in the original array except the one at i.

// For example, if our input was [1, 2, 3, 4, 5], 
// the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], 
// the expected output would be [2, 3, 6].

// Follow-up: what if you can't use division?

#include <iostream>
using namespace std;

void inputArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void changeArray(int a[], int n) {
    int answer = 1;
    for (int i= 0; i < n; i++) {
        answer *= a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = answer / a[i];
    }
}

/*void arrProd(const int arr[], int size){
    int prod = 1;
    int arr2[size];

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(j != i)
                prod = prod * arr[j];
        }
        arr2[i] = prod;
        prod = 1;
    }

    //Prints out final array
    for(int i = 0; i < size; i++){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
}*/

int main () {
    int n, k, a[100];
    cout << "Nhap so phan cua mang: ";
    cin >> n;
    inputArray(a, n);
    cout << "Xuat mang vua nhap: ";
    printArray(a, n);
    cout << "\nXuat mang sau khi thay doi: ";
    changeArray(a, n);
    printArray(a, n);
    return 0;
}