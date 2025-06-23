#include <iostream>
#include "melancia.h"

using namespace std;

Melancia::Melancia(double preco, double preco_adicional, bool estacao): Fruta(preco) {
    this->preco_adicional = preco_adicional;
    this->estacao = estacao;
}

double Melancia::get_preco_adicional() const {
    return this->preco_adicional;
}

void Melancia::set_preco_adicional(double preco_adicional) {
    this->preco_adicional = preco_adicional;
}

bool Melancia::eh_estacao() const {
    return this->estacao;
}

void Melancia::set_estacao(bool estacao) {
    this->estacao = estacao;
}

double Melancia::calcula_preco_final() {
    if(eh_estacao())
        return Fruta::get_preco();
    return Fruta::calcula_preco(0.0) + preco_adicional;
}

