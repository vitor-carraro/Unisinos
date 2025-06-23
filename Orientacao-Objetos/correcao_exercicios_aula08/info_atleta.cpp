#include <iostream>
#include "info_atleta.h"
#include "nadador.h"
#include "corredor.h"

using namespace std;

void InformacoesAtleta::imprime_exclusivos_atleta(Atleta* atleta) {
    if(Nadador* n = dynamic_cast<Nadador*>(atleta)) {
        cout << "É um nadador, e sua categoria é: " << n->get_categoria() << endl;
    }
    else if(Corredor* c = dynamic_cast<Corredor*>(atleta)) {
        cout << "É um corredor, e o peso deste corredor é: " << c->get_peso() << endl;
    }
}

void InformacoesAtleta::imprime_informacoes_atleta(Atleta* atleta) { 
    if(Nadador* n = dynamic_cast<Nadador*>(atleta))
        n->imprime_info();
    else if(Corredor* c = dynamic_cast<Corredor*>(atleta))
        c->imprime_info();
}

