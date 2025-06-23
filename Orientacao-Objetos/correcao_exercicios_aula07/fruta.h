#ifndef FRUTA_H
#define FRUTA_H

using namespace std;

class Fruta {
    private:
        double preco;
    public:
        Fruta(double preco);
        double get_preco() const;
        void set_preco(double preco);
        double calcula_preco(double taxa);
};

#endif
