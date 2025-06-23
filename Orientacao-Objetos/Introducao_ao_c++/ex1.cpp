#include <iostream>

using namespace std;

#define SIZE 10

int main(){

    int matriz[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << "Posição da linha[" << i << "]" << "Posição da coluna[" << j << "]";
            cin >> matriz[i][j];
        }
    }

    int menor = matriz[0][0], menorlinha;

    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if (matriz[i][j] < menor){
                menor = matriz[i][j];
                menorlinha = i;
            }
        }
    }

    cout << "O menor valor consta na linha " << menorlinha << " e o valor é " << menor << endl;
    
    return 0;
}