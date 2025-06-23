#include <iostream>
#include "fruta.h"

using namespace std;

Fruta::Fruta(double preco) {
    this->preco = preco;
}

double Fruta::get_preco() const {
    return this->preco;
}

void Fruta::set_preco(double preco) {
    this->preco = preco;
}

double Fruta::calcula_preco(double taxa) {
    return this->preco + (this->preco * taxa);
}

