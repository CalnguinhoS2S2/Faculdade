#include <bits/stdc++.h>
using namespace std;

void SelectionSortNum(vector<pair<int,string>> &lista,int tam){
	
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].first<lista[i].first){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}

void SelectionSortChar(vector<pair<int,string>> &lista,int tam){
	
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].second<lista[i].second){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}