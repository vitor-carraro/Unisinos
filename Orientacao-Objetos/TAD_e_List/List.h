#include <iostream>

using namespace std;

template <typename T>
class List {
    private:
        T* p;
        int size;
        int count;
        int first;
        int last;
    public:
        List(int s);
        void add(const T &value);
        T getLast() const;
        void emptyList();
        void fullList();
        void insert(int posicao, const T &value);
};

template <typename T>
List<T>::List(int s)
{
    p = new T[s];
    size = s;
    count = 0;
    first = 0;
    last = -1;
}

template <typename T>
inline void List<T>::add(const T &value)
{
    if(count < size){
        p[count] = value;
        last = count;
        count++;
    }
}

template <typename T>
inline T List<T>::getLast() const
{
    if(count > 0){
        return p[count - 1];
    }
}

template <typename T>
inline void List<T>::emptyList()
{
    if (last == -1){
        cout << "List vazia";
    }else{
        cout << "List não vazia"
    }
}

template <typename T>
inline void List<T>::fullList()
{
    if(cout == size){
        cout << "List cheia"
    }
}

template <typename T>
void List<T>::insert(int posicao, const T &value)
{
    if(posicao <= size){
        switch (posicao)
        {
            case posicao <= last:
                p[posicao] = value;
                break;
            default:
                p[last + 1] = value;
                last++;
                cout++; 
                break;
        }
    }
    
}
