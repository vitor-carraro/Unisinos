/**
 * Código exemplo para uso das estruturas:
 * StaticList, StaticQueue e StaticStack
 */

#include <iostream>
#include "staticList.h"
#include "staticQueue.h"
#include "staticStack.h"

using namespace std;

int main() {
    StaticList<int> sl(5);  // Cria uma lista estática de tipo int com 5 posições
    StaticQueue<int> sq(5); // Cria uma fila estátia de tipo int com 5 posições
    StaticStack<int> ss(5); // Cria uma pilha estática de tipo int com 5 posições

    /**
     * Tenta inserir o elemento 5 na posição 0 (zero) da lista.
     * Verifica se o elemento foi inserido por meio do código de retorno 
     * da função.
     */
    if(sl.insert(5, 0) == 0)
        cout << "Elemento inserido com sucesso na lista!" << endl;
    cout << "\n";
    
    /**
     * Tenta remover um elemento da fila vazia.
     * Verifica o código de retorno da função.
     */
    int result;
    int code = sq.dequeue(result);
    if(code)
        cout << "Fila vazia!!" << endl;
    cout << "\n";
        
    
    /**
     * Tenta inserir o elemento 4 na pilha.
     * Verifica se o elemento foi inserido por meio do código de retorno
     * da função.
     */
    if(ss.push(4) == 0)
        cout << "Elemento inserido com sucesso na pilha!" << endl;
    cout << "\n";


    return 0;
}
