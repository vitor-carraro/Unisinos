#include <iostream>
#include "banana.h"

using namespace std;

Banana::Banana(double preco, string tipo): Fruta(preco) {
    this->tipo = tipo;
}

string Banana::get_tipo() const {
    return this->tipo;
}

void Banana::set_tipo(string tipo) {
    this->tipo = tipo;
}
