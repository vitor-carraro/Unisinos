#ifndef COMPETICAO_H
#define COMPETICAO_H

#include "Data.h"

using namespace std;

class Competicao
{
private:
    string nome;
    Data data;
public:
    Competicao(string nome, Data data);
    void SetNome(string nome);
    void SetData(Data data);
    string GetNome();
    Data GetData();
    void imprime_data();
};

#endif
