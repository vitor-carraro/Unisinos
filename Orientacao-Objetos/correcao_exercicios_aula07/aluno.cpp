#include <iostream>
#include "aluno.h"

using namespace std;

Aluno::Aluno(string nome, int idade, double nota): Pessoa(nome, idade) {
    this->nota = nota;
}

double Aluno::get_nota() const {
    return this->nota;
}

void Aluno::set_nota(double nota) {
    this->nota = nota;
}

void Aluno::imprime_dados() {
    Pessoa::imprime_dados();
    cout << "Nota: " << nota << endl;
}

