/**
 * Código exemplo para uso da estrutura:
 * SinglyLinkedList
 */

#include <iostream>
#include "singlyLinkedList.h"

using namespace std;

int main() {
    SinglyLinkedList<int> sll;  // Cria uma lista encadeada de tipo int

    /**
     * Insere os elementos 5, 6, 7 e 8 em sequência na lista.
     */
    sll.insert(5, 0);
    sll.insert(6, 1);
    sll.insert(7, 2);
    sll.insert(8, 3);

    /**
     * Insere o elemento 9 no início da lista.
     */
    sll.insertFirst(9);
    
    /**
     * Insere o elemento 10 no início da lista.
     */
    sll.insertLast(10);

    /**
     * Imprime os elementos da lista.
     */
    cout << "==== ELEMENTOS NA LISTA ====" << endl;
    int result;
    int num_elements = sll.numElements();
    for(int i = 0; i < num_elements; i++) {
        if(sll.get(i, result) == 0)
            cout << result << " "; 
    }
    cout << "\n";

    return 0;
}
