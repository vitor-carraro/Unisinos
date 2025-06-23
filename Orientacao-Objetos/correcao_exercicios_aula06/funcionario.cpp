#include <iostream>
#include "funcionario.h"
#include "calculadora.h"

using namespace std;

FuncionarioCaixa::FuncionarioCaixa(string nome, string endereco, Calculadora calculadora): calculadora(calculadora) {
    this->nome = nome;
    this->endereco = endereco;
}

string FuncionarioCaixa::get_nome() {
    return this->nome;
}

void FuncionarioCaixa::set_nome(string nome) {
    this->nome = nome;
}

string FuncionarioCaixa::get_endereco() {
    return this->endereco;
}

void FuncionarioCaixa::set_endereco(string endereco) {
    this->endereco = endereco;
}

Calculadora FuncionarioCaixa::get_calculadora() {
    return this->calculadora;
}

void FuncionarioCaixa::set_calculadora(Calculadora calculadora) {
    this->calculadora = calculadora;
}

float FuncionarioCaixa::soma(float valor1, float valor2) {
    return this->calculadora.soma(valor1, valor2);
}

float FuncionarioCaixa::subtrai(float valor1, float valor2) {
    return this->calculadora.subtrai(valor1, valor2);
}

float FuncionarioCaixa::multiplica(float valor1, float valor2) {
    return this->calculadora.multiplica(valor1, valor2);
}

float FuncionarioCaixa::divide(float valor1, float valor2) {
    return this->calculadora.divide(valor1, valor2);
}

int FuncionarioCaixa::eleva_ao_quadrado(int valor) {
    return this->calculadora.eleva_ao_quadrado(valor);
}

int FuncionarioCaixa::eleva_ao_cubo(int valor) {
    return this->calculadora.eleva_ao_cubo(valor);
}

void FuncionarioCaixa::imprime_info() {
    cout << "==== Informações do Funcionário ====" << endl;
    cout << "Nome: " << get_nome() << endl;
    cout << "Endereço: " << get_endereco() << endl;
    cout << "-- Calculadora -- " << endl;
    calculadora.imprime_info();
}

