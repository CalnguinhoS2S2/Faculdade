#include <bits/stdc++.h>

using namespace std;

class dev {
public:
    int *vet;
    int size;
    dev(int n) {
        size = n;
        vet = new int[size];
    }
    ~dev() {
        delete[] vet;
        cout  << "\ndestructor " << "davi ;)\n";
    }
    void inserir() {
        for(int i = 0 ; i < size; i++) {
            cin >> vet[i];
        }
    }
    void imprimir() {
        for(int i = 0; i < size ; i++)
            cout << "vet[" << i << "] "<< vet[i] << endl;
    }
    void multiplica(dev v) {
        for(int i = 0 ; i < size; i++) {
            vet[i] = vet[i] * v.vet[i];
        }
    }
    void multiplica(int a) { //dev v
        for(int i = 0 ; i < size; i++) {
            vet[i] = vet[i] * a;  //tanto dev com this-> funciona;
        }
    }
};

int main(){
    dev t(5) , t2(5);
    t.inserir();
    t2.inserir();
    t.multiplica(t2);
    t.imprimir();
    return 0;
}