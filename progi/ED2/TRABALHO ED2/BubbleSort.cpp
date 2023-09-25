#include <bits/stdc++.h>
using namespace std;

void BubbleSortNum(vector<pair<int,string>> &lista,int tam){
    for(int fim=tam-1;fim>0;fim--){
        for(int i=0;i<fim;i++){
            if(lista[i].first>lista[i+1].first){
				        pair<int,string> aux;
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
        }
    }
}

void BubbleSortChar(vector<pair<int,string>> &lista,int tam){
    for(int fim=tam-1;fim>0;fim--){
        for(int i=0;i<fim;i++){
            if(lista[i].second>lista[i+1].second){
				        pair<int,string> aux;
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
        }
    }
}