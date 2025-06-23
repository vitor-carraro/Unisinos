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
        void BubbleShort();
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

template <typename T>
void MyArray<T>::BubbleShort()
{
    for (int j = 0; j < 100; j++)
    {
        T valor1 = 0;
        for (int i = size; i >= 0; i--)
        {
            if(p[i] < p[i - 1])
            {
                valor1 = p[i - 1]; 
                p[i - 1] = p[i];
                p[i] = valor1;
            }
        }
    }
}
