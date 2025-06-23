#include <iostream>
#include "pessoa.h"

using namespace std;

Pessoa::Pessoa(string nome, int idade) {
    this->nome = nome;
    this->idade = idade;
}

string Pessoa::get_nome() const {
    return this->nome;
}

void Pessoa::set_nome(string nome) {
    this->nome = nome;
}

int Pessoa::get_idade() const {
    return this->idade;
}

void Pessoa::set_idade(int idade) {
    this->idade = idade;
}

void Pessoa::imprime_dados() {
    cout << "=== Dados pessoais ===" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
}

