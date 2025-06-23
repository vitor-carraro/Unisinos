#include <iostream>

using namespace std;

int main() {
    int numeroMax;
    
    // Solicita um número ímpar
    do {
        cout << "Qual o numero maximo de casas (deve ser ímpar): ";
        cin >> numeroMax;
        if (numeroMax % 2 == 0) {
            cout << "O numero é par. Tente novamente!" << endl;
        }
    } while (numeroMax % 2 == 0);

    // Imprime as linhas (EX: numMax = 9, vai ter 5 linhas = numMax/2)
    for (int i = 0; i <= numeroMax / 2; i++) 
    {
        // Imprime os espaços antes de cada valor
        for (int j = 0; j < i; j++) 
        {
            cout << " ";
        }

        // Imprime os valores
        for (int j = i + 1; j <= numeroMax - i; j++) 
        {  
            cout << j;
        }

        // Quebra de linha ao final de cada linha de números
        cout << endl;
    }

}