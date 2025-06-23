#include <iostream>

using namespace std;

template <typename T> 
T multiplicar(T a, T b) {
    return a * b;
}

int main() {
    // Chama a função para um inteiro
    cout << multiplicar<int>(5, 3) << endl;

    // Chama a função para um double
    cout << multiplicar<double>(7.5, 9.3) << endl;

    return 0;
}

