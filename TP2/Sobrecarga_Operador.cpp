#include<bits/stdc++.h>
using namespace std;

class fracao
{
private:
    int num, den;
public:
    fracao(){
        num=3;
        den=5;
    }
    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }
    fracao operator * (fracao P){
        fracao aux;
        aux.num= num * P.num;
        aux.den= den * P.den;
        return aux;
    }
};

int main(){
    fracao f1(), f2(), f3();
    //f3=f1*f2;
}