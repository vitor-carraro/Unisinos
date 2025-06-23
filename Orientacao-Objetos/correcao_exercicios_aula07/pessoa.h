#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
    public:
        Pessoa(string nome, int idade);
        string get_nome() const;
        void set_nome(string nome);
        int get_idade() const;
        void set_idade(int idade);
        virtual void imprime_dados();
};

#endif
