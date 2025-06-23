#include <iostream>
#include "atleta.h"

using namespace std;

Atleta::Atleta(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
}

string Atleta::get_nome() const {
    return this->nome;
}

void Atleta::set_nome(string nome) {
    this->nome = nome;
}

int Atleta::get_idade() const {
    return this->idade;
}

void Atleta::set_idade(int idade) {
    this->idade = idade;
}

void Atleta::imprime_info() {
    cout << "==== Informações do Atleta ====" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
}

