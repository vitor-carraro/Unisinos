#ifndef ATLETA_H
#define ATLETA_H

using namespace std;

class Atleta
{
private:
    string nome;
    int idade;
public:
    Atleta(string nome, int idade);
    void SetNome(string nome);
    void SetIdade(int idade);
    string GetNome();
    int GetIdade();
    virtual void imprime_info();
};


#endif
