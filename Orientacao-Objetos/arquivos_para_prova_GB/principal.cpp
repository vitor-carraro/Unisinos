/**
 * Prova do Grau B
 * Nome: Vitor Wisniewski Carraro
 */

#include <iostream>
#include "staticQueue.h"
#include "doublyLinkedList.h"
#include "singlyLinkedList.h"
#include "staticStack.h"

using namespace std;

StaticQueue<int> returnEven(DoublyLinkedList<int> dl);
int addOddNumbers(SinglyLinkedList<int> list, int pos, int value);
int addOddNumbers(SinglyLinkedList<int> sl);
void organizeQueue(StaticQueue<int>* q);


int main() {
    // Teste da função returnEven
    DoublyLinkedList<int> dl;
    dl.insertLast(0);
    dl.insertLast(1);
    dl.insertLast(2);
    dl.insertLast(3);
    dl.insertLast(4);
    dl.insertLast(5);

    StaticQueue<int> filaReturnEven = returnEven(dl);
    if (filaReturnEven.isEmpty())
        cout << "Fila vazia!";
    else
        cout << "Quantidade de elementos pares: " << filaReturnEven.numElements() << endl << endl;
    
    // Teste da função addOddNumbers
    SinglyLinkedList<int> sl;

    sl.insertLast(0);
    sl.insertLast(1);
    sl.insertLast(2);
    sl.insertLast(3);
    sl.insertLast(4);
    sl.insertLast(5);

    int sum = addOddNumbers(sl);
    if(sum == INT_MAX)
        cout << "List vazia!" << endl << endl;
    else
        cout << "A soma é: " << sum << endl << endl;

    // Teste da função push
    
    StaticStack<int> Ss(10);
    StaticStack<int> Ss2(10);
    
    //Pilha 1
    Ss.push(0);
    Ss.push(1);
    Ss.push(2);
    Ss.push(3);
    Ss.push(4);
    
    //Pilha 2
    Ss2.push(5);
    Ss2.push(6);
    Ss2.push(7);
    Ss2.push(8);
    Ss2.push(9);

    StaticStack<int> saux(Ss.numElements());
    int valorPilha;
    cout << "Pilha antes: " << endl;
	while(!Ss.isEmpty()) {
        Ss.pop(valorPilha);
        saux.push(valorPilha);
        cout << valorPilha << endl;
    }
    while(!saux.isEmpty()) {
        saux.pop(valorPilha);
        Ss.push(valorPilha);
    }
	cout << "\n\n";

    //Juntar pilhas
    if(Ss.push(Ss2) == 0){
        cout << "pilhas empilhadas corretamente" << endl << endl;
    }else{
        cout << "pilha atingiu o indice max.";
    }

    cout << "Pilha apos: " << endl;
	while(!Ss.isEmpty()) {
        Ss.pop(valorPilha);
        saux.push(valorPilha);
        cout << valorPilha << endl;
    }
    while(!saux.isEmpty()) {
        saux.pop(valorPilha);
        Ss.push(valorPilha);
    }
	cout << "\n\n";

    // Teste da função organizeQueue
    StaticQueue<int> filaFuncaoOrganize(10);
    filaFuncaoOrganize.enqueue(1);
    filaFuncaoOrganize.enqueue(-1);
    filaFuncaoOrganize.enqueue(24);
    filaFuncaoOrganize.enqueue(5);
    filaFuncaoOrganize.enqueue(67);
    filaFuncaoOrganize.enqueue(-108);
    filaFuncaoOrganize.enqueue(-12);
    filaFuncaoOrganize.enqueue(23);

    cout << "Fila antes do organize:" << endl;
    int filaValue;
    StaticQueue<int> sq_temp(filaFuncaoOrganize.numElements());

    while(!filaFuncaoOrganize.isEmpty()) {
        filaFuncaoOrganize.dequeue(filaValue);
        sq_temp.enqueue(filaValue);
        cout << filaValue << " ";
    }
    // Remonta a fila original
    while(!sq_temp.isEmpty()) {
        sq_temp.dequeue(filaValue);
        filaFuncaoOrganize.enqueue(filaValue);
    }
    cout << "\n";

    organizeQueue(&filaFuncaoOrganize);

    cout << "Fila pos do organize:" << endl;

    while(!filaFuncaoOrganize.isEmpty()) {
        filaFuncaoOrganize.dequeue(filaValue);
        sq_temp.enqueue(filaValue);
        cout << filaValue << " ";
    }
    // Remonta a fila original
    while(!sq_temp.isEmpty()) {
        sq_temp.dequeue(filaValue);
        filaFuncaoOrganize.enqueue(filaValue);
    }
    cout << "\n";
    
    


    return 0;
}

StaticQueue<int> returnEven(DoublyLinkedList<int> dl)
{
    StaticQueue<int> filaRetornada(dl.numElements());
    
    if(dl.isEmpty()){
        cout << "Lista sem elementos!!";
    }
    else{
        int valor;
        
        for (int i = 0; i < dl.numElements(); i++)
        {
            if (dl.get(i, valor) == 0)
            {
                if(valor % 2 == 0)
                    filaRetornada.enqueue(valor);
            }
        }

        return filaRetornada; 
    }

    return filaRetornada;
}

int addOddNumbers(SinglyLinkedList<int> list, int pos, int value) {
    if(pos == list.numElements())
        return 0;
    else {
        list.get(pos, value);
        if (value % 2 == 0)
            value = 0;
        
        return value + addOddNumbers(list, pos + 1, value); 
    }
}

int addOddNumbers(SinglyLinkedList<int> list) {
    int value = 0;

    if(list.isEmpty())
        return INT_MAX;
    else
        return addOddNumbers(list, 0, value);
}

void organizeQueue(StaticQueue<int> *q)
{
    StaticQueue<int> sauxNegativo(q->numElements());
    StaticQueue<int> sauxZero(q->numElements());
    StaticQueue<int> sauxPositivo(q->numElements());

    int value;
    while (!q->isEmpty())
    {
        q->dequeue(value);
        if (value < 0)
        {
            sauxNegativo.enqueue(value);
        }else if (value == 0)
        {
            sauxZero.enqueue(value);
        }
        else if (value > 0)
        {
            sauxPositivo.enqueue(value);
        }
    }

    while (!sauxNegativo.isEmpty())
    {
        sauxNegativo.dequeue(value);
        q->enqueue(value);
    }
    
    
    while (!sauxZero.isEmpty())
    {
        sauxZero.dequeue(value);
        q->enqueue(value);
    }

    
    while (!sauxPositivo.isEmpty())
    {
        sauxPositivo.dequeue(value);
        q->enqueue(value);
    }    

}
