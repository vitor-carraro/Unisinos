#include <iostream>

using namespace std;

template <typename T>
class MyArray {
    private:
        T* p;
        int size;
    public:
        MyArray(T array[], int s);
        void print();
};

template <typename T>
MyArray<T>::MyArray(T array[], int s) {
    p = new T[s];
    size = s;
    for(int i = 0; i < size; i++) {
        p[i] = array[i];
    }
}

template <typename T>
void MyArray<T>::print() {
    for(int i = 0; i < size; i++) {
        cout << " " << *(p + i);
    }
    cout << endl;
}

