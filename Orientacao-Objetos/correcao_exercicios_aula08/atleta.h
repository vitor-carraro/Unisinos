#ifndef ATLETA_H
#define ATLETA_H

using namespace std;

class Atleta {
    private:
        string nome;
        int idade;
    public:
        Atleta(string nome, int idade);
        Atleta() = default;
        string get_nome() const;
        void set_nome(string nome);
        int get_idade() const;
        void set_idade(int idade);
        virtual void imprime_info();
};

#endif
