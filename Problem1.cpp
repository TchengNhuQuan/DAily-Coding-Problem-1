// Given a list of numbers and a number k, 
// return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17,
// return true since 10 + 7 is 17.

#include <iostream>
using namespace std;

void inputArray(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

bool check(int a[], int n, int k) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n+1; j++) {
            if ((a[i] + a[j]) == k) {
                cout << "since " << a[i] << " + " << a[j] << " = " << k << endl;
                return 1;
            }
        }
    }
    return 0;
}

int main () {
    int n, k, a[100];
    cout << "Nhap so phan cua mang: ";
    cin >> n;
    inputArray(a, n);
    cout << "Xuat mang vua nhap: ";
    printArray(a, n);
    cout << "\nNhap k: ";
    cin >> k;
    if (check(a, n, k)) {
        cout << "True";
    } else {
        cout << "False";
    }
}