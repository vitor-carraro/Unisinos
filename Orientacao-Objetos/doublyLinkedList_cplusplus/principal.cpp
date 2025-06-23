/**
 * Código exemplo para uso da estrutura:
 * DoublyLinkedList
 */

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main() {
    DoublyLinkedList<int> dll;  // Cria uma lista duplamente encadeada de tipo int

    /**
     * Insere os elementos 5, 6, 7 e 8 em sequência na lista.
     */
    dll.insert(5, 0);
    dll.insert(6, 1);
    dll.insert(7, 2);
    dll.insert(8, 3);

    /**
     * Insere o elemento 9 no início da lista.
     */
    dll.insertFirst(9);
    
    /**
     * Insere o elemento 10 no início da lista.
     */
    dll.insertLast(10);

    /**
     * Imprime os elementos da lista.
     */
    cout << "==== ELEMENTOS NA LISTA ====" << endl;
    int result;
    int num_elements = dll.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(dll.get(i, result) == 0)
            cout << result << " "; 
    }
    cout << "\n";

    return 0;
}
