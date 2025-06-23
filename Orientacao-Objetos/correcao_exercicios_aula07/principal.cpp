#include <iostream>
#include "fruta.h"
#include "banana.h"
#include "melancia.h"
#include "pessoa.h"
#include "programador.h"
#include "aluno.h"

using namespace std;

int main() {
    cout << "**** Contexto das Frutas ****\n" << endl;
    Banana b = Banana(2.50, "Prata");
    cout << "BANANA:" << endl;
    cout << "Tipo: " << b.get_tipo() << endl;
    cout << "Preço: " << b.calcula_preco(0.5) << endl;

    Melancia m = Melancia(5.00, 2.50, true);
    cout << "MELANCIA:" << endl;
    if(m.eh_estacao())
        cout << "Estamos em época de melancia" << endl;
    else
        cout << "Não estamos em época de melancia" << endl;
    cout << "Preço: " << m.calcula_preco_final() << endl;

    cout << "\n**** Contexto das Pessoas ****\n" << endl;
    Pessoa* p;
    int escolha;
    cout << "Digite 1 para programador e 2 para aluno: ";
    cin >> escolha;
    if(escolha == 1) {
        Programador prog = Programador("Bjarne Stroustrup", 32, "C++");
        p = &prog;
        p->imprime_dados();
    }
    else {
        Aluno a = Aluno("Ada Lovelace", 27, 10.0);
        p = &a;
        p->imprime_dados();
    }

    return 0;
}
