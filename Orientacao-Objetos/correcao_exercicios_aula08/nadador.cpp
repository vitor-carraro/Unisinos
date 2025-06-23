#include <iostream>
#include "nadador.h"

using namespace std;

Nadador::Nadador(string nome, int idade, string categoria): Atleta(nome, idade) {
    this->categoria = categoria;
}

string Nadador::get_categoria() const {
    return this->categoria;
}

void Nadador::set_categoria(string categoria) {
    this->categoria = categoria;
}

void Nadador::imprime_info() {
    Atleta::imprime_info();
    cout << "Categoria: " << categoria << endl;
}

