#include <iostream>

#define SIZE 3

using namespace std;

void SomaMatriz(float Mat[][]);
void MultiplicaMatriz(float Mat[][]);

int main() {

    float Matriz[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> Matriz[i][j];
        }
    }
    
}

// soma os elementos das linhas L1 e L2 de uma matriz, resultado colocado na linha L2
void SomaMatriz(float Mat[][]){
    float Soma;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Soma = Soma + Mat[i][j]; 
        }

        if (i = 2)
        {
            Mat[i] = Soma;
        }
        
    }
    
}

// Multiplica os elementos das linhas L1 e L2 de uma matriz, resultado colocado na linha L2
void MultiplicaMatriz(float Mat[][])
{
    
}
