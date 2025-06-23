#include <iostream>
#include <cmath>
#include "calculadora.h"

using namespace std;

Calculadora::Calculadora(string cor) {
    this->memoria = 0;
    this->cor = cor;
}

int Calculadora::get_memoria() {
    return memoria;
}

void Calculadora::set_memoria(int memoria) {
    this->memoria = memoria;
}

string Calculadora::get_cor() {
    return cor;
}

void Calculadora::set_cor(string cor) {
    this->cor = cor;
}

float Calculadora::soma(float valor1, float valor2) {
    return valor1 + valor2;
}

float Calculadora::subtrai(float valor1, float valor2) {
    return valor1 - valor2;
}

float Calculadora::multiplica(float valor1, float valor2) {
    return valor1 * valor2;
}

float Calculadora::divide(float valor1, float valor2) {
    if(valor2 == 0)
        return -1;
    else
        return valor1 / valor2;
}

int Calculadora::eleva_ao_quadrado(int valor) {
    return pow(valor, 2);
}

int Calculadora::eleva_ao_cubo(int valor) {
    return pow(valor, 3);
}

void Calculadora::imprime_info() {
    cout << "Cor: " << get_cor() << endl;
    cout << "Memória: " << get_memoria() << endl;
}

