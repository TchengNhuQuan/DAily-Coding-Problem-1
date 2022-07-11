// Given an array of integers, 
// find the first missing positive integer in linear time and constant space. 
// In other words, find the lowest positive integer that does not exist in the array. 
// The array can contain duplicates and negative numbers as well.

// For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

// You can modify the input array in-place

#include <iostream>
#include <vector>
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

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int segregate(int a[], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) {
            swap(&a[i], &a[j]);
            j++;
        }
    }
    return j;
}

int findMissingPositive(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) - 1 < n && a[abs(a[i]) - 1] > 0) {
            a[abs(a[i]) - 1] = - a[abs(a[i]) - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            return i + 1;
        }
    }
    return n + 1;
}

int findMissing(int a[], int n) {
    int shift = segregate(a, n);
    return findMissingPositive(a + shift, n - shift);
}

int main () {
    int n, a[100];
    cout << "Nhap so phan tu trong mang: ";
    cin >> n;
    inputArray(a, n);
    cout << "Xuat mang vua nhap: ";
    printArray(a, n);
    int ketqua = findMissing(a, n);
    cout << "\nSo duong nho nhat bi thieu la: " << ketqua << endl;
    
    return 0;
}