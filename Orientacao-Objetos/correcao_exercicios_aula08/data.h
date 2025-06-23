#ifndef DATA_H
#define DATA_H

using namespace std;

class Data {
    private:
        int dia,
            mes,
            ano;
    public:
        Data(int dia, int mes, int ano);
        Data() = default;
        int get_dia() const;
        void set_dia(int dia);
        int get_mes() const;
        void set_mes(int mes);
        int get_ano() const;
        void set_ano(int ano);
        void imprime_data();
};

#endif
