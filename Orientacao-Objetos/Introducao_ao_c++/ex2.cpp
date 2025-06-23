#include <iostream>

using namespace std;

#define SIZE 10

int main(){

    int numeromax;
    
    do
    {
        cout << "qual o numero maximo de casas(deve ser impar): ";
        cin >> numeromax;
    } while (numeromax % 2 == 0);
 
}