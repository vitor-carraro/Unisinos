#include <iostream>
#include "corredor.h"

using namespace std;

Corredor::Corredor(string nome, int idade, double peso, Competicao competicao): Atleta(nome, idade), competicao(competicao) {
    this->peso = peso;
}

double Corredor::get_peso() const {
    return this->peso;
}

void Corredor::set_peso(double peso) {
    this->peso = peso;
}

Competicao Corredor::get_competicao() const {
    return this->competicao;
}

void Corredor::set_competicao(Competicao competicao) {
    this->competicao = competicao;
}

void Corredor::imprime_competicao() {
    cout << "-- Competição na qual participa  -- " << endl;
    cout << "Nome: " << competicao.get_nome() << endl;
    competicao.imprime_data();
    cout << "\n";
}

void Corredor::imprime_info() {
    Atleta::imprime_info();
    cout << "Peso: " << peso << endl;
    imprime_competicao();
    cout << "\n";
}

