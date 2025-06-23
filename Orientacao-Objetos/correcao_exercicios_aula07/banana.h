#ifndef BANANA_H
#define BANANA_H

#include "fruta.h"

using namespace std;

class Banana: public Fruta {
    private:
        string tipo;
    public:
        Banana(double preco, string tipo);
        string get_tipo() const;
        void set_tipo(string tipo);
};

#endif
