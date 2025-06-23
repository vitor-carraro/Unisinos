#include <iostream>

using namespace std;

template <typename T> class MyArray {
    private:
        T* p;
        int size;
    public:
        MyArray(T array[], int s);
        void print();
        T* bubble_sort();
};

template <typename T> MyArray<T>::MyArray(T array[], int size) {
    p = new T[size];
    this->size = size;
    for(int i = 0; i < size; i++) {
        p[i] = array[i];
    }
}

template <typename T> void MyArray<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << " " << *(p + i);
    }
    cout << endl;
}

template <typename T> T* MyArray<T>::bubble_sort() {
    for(int i = 0; i < size - 1; i++) {
        for(int j = size - 1; i < j; j--) {
            if(p[j] < p[j - 1]) {
                T temp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = temp;
            }
        }
    }
    return p;
}

