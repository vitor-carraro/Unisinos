#include <iostream>
#include "competicao.h"

using namespace std;

Competicao::Competicao(string nome, Data data): data(data) {
    this->nome = nome;
}

string Competicao::get_nome() const {
    return this->nome;
}

void Competicao::set_nome(string nome) {
    this->nome = nome;
}

Data Competicao::get_data() const {
    return this->data;
}

void Competicao::set_data(Data data) {
    this->data = data;
}

void Competicao::imprime_data() {
    cout << "Data da competição: ";
    data.imprime_data();
    cout << "\n";
}

