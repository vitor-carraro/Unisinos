#include <iostream>

#define SIZE 3 

using namespace std;

int main(){

    //Definindo uma matriz quadrada de inteiros com o tamanho de SIZE_MAX
    int MatInt[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) //Realiza a leitura da matriz
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << "Posição da matriz [" << i << "][" << j << "]: ";
            cin >> MatInt[i][j];
        }
    }

    int lessValue = MatInt[0][0];
    int linha = -1, coluna = -1;

    //Descobrindo o menor valor de MatInt
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
        {
            if(MatInt[i][j] < lessValue){
                lessValue = MatInt[i][j];
                linha = i;
                coluna = j;
            }
        }
    }

    cout << "Menor valor da matriz é '" << lessValue << "' e suas posições são [" << linha << "][" << coluna << "]";
    
}