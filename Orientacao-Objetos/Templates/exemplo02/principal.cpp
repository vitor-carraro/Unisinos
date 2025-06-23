#include <iostream>
#include "class_array.h"

#define SIZE 4

using namespace std;

int main() {
    int array[SIZE] = {4, 3, 1, 2};
    MyArray<int> a(array, SIZE);

    a.print();

    return 0;
}
