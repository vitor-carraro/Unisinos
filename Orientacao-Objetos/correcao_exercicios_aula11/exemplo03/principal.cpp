#include <iostream>
#include "class_array.h"

#define SIZE 4

using namespace std;

int main() {
    int array[SIZE] = {4, 3, 1, 2};
    int* p;
    MyArray<int> a(array, SIZE);

    a.print();

    cout << "Sorted array: ";
    p = a.bubble_sort();
    for(int i = 0; i < SIZE; i++)
        cout << p[i] << " ";
    cout << endl;

    delete[] p;

    return 0;
}
