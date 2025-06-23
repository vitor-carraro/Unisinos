#include<iostream>

#include "Nadador.h"

using namespace std;

Nadador::Nadador(string nome, int idade, string categoria) : Atleta(nome , idade)
{
    this->categoria = categoria;
}

void Nadador::SetCategoria()
{
    this->categoria = categoria;
}

string Nadador::GetCategoria()
{
    return categoria;
}

void Nadador::imprime_info()
{
    imprime_info();
    cout << "A categoria do Nadador é: " << categoria << endl;
}
