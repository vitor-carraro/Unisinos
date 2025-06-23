#include <iostream>

using namespace std;

class retangulo{

    public:
        retangulo(int _base, int _altura);
        retangulo();
        int GetArea();
        int GetBase();
        int GetAltura();
        void SetBase(int _base);
        void SetAltura(int _altura);
    private:
        int base;
        int altura;
        int area(int _base, int _altura);
};

retangulo::retangulo(int _base, int _altura){
        base = _base;
        altura = _altura;
    }

retangulo::retangulo(){
        base = 0;
        altura = 0;
    }

int retangulo::GetArea()
{
    return area(base, altura);
}

int retangulo::GetBase()
{
    return base;
}

int retangulo::GetAltura()
{
    return altura;
}

void retangulo::SetBase(int _base)
{
    base = _base;
}

void retangulo::SetAltura(int _altura)
{
    altura = _altura;
}

int retangulo::area(int _base, int _altura)
{
    int area;
    area = _base * _altura;
    return area;
}

int main(){

    retangulo oRetangulo;

    cout << "o reteangulo tem base " << oRetangulo.GetBase() << ", tem altura " << oRetangulo.GetAltura() << " e area igual a: " << oRetangulo.GetArea() << endl; 
    
    char R;
    
    cout << "você deseja trocar de valores?(S/N) ";
    cin >> R;

    if (R == 'S'){
        int baseNova, alturaNova;
        cout << "Digite o valor da base nova: ";
        cin >> baseNova;
        cout << "Digite o valor da altura nova: ";
        cin >> alturaNova;
        oRetangulo.SetBase(baseNova);
        oRetangulo.SetAltura(alturaNova);
        
        cout << "o reteangulo tem base: " << oRetangulo.GetBase() << ", tem altura: " << oRetangulo.GetAltura() << " e area igual a: " << oRetangulo.GetArea() << endl;  
    }

    return 0;    
    
}