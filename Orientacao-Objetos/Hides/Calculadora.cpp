#include <iostream>

#include "Calculadora.h"

using namespace std;

Calculadora::Calculadora(string cor)
{
    this->memoria = 0;
    this->cor = cor;
}

void Calculadora::SetMemoria(int memoria)
{
    this->memoria = memoria;
}

int Calculadora::GetMemoria()
{
    return memoria;
}

void Calculadora::SetCor(string cor)
{
    this->cor = cor;
}

string Calculadora::GetCor()
{
    return cor;
}

float Calculadora::Soma(float x, float y)
{
    return x + y;
}

float Calculadora::Subtrai(float x, float y)
{
    return x - y;
}

float Calculadora::Multiplica(float x, float y)
{
    return x * y;
}

float Calculadora::Divide(float x, float y)
{
    if(y != 0){
        return x / y;
    }
    else{ 
        return -1;
    }
}

int Calculadora::eleva_ao_quadrado(int x)
{
    return x * x;
}

int Calculadora::eleva_ao_cubo(int x)
{
    return x * x * x;
}

void Calculadora::imprime_info()
{
    cout << "o valor da memoria é: " << GetMemoria() << endl;
    cout << "o valor da cor é: " << GetCor() << endl;
}