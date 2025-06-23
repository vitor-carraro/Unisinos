#include <iostream>
#include "programador.h"

using namespace std;

Programador::Programador(string nome, int idade, string linguagem): Pessoa(nome, idade) {
    this->linguagem = linguagem;
}

string Programador::get_linguagem() const {
    return this->linguagem;
}

void Programador::set_linguagem(string linguagem) {
    this->linguagem = linguagem;
}

void Programador::imprime_dados() {
    Pessoa::imprime_dados();
    cout << "Linguagem: " << linguagem << endl;
}

