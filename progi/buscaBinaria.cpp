#include <iostream>
#include <algorithm>
using namespace std;

int BuscaBinaria(int *vet, int num, int tam){ // modo interativo
    int pi=0, pf=tam-1, pos;
    while(pi<=pf){
    	pos=(pi+pf)/2; //dividindo o vetor ao meio
        if(num==vet[pos]) return pos; //retornando a posição do numero se ele for encontrado
        if(num<vet[pos]) pf=pos-1; //o numero esta a esquerda do meio
        else pi=pos+1; // o numero esta a direita do meio
    }
    return -1; //numero ñ encontrado
}

int buscaBinaria(int *vet, int num, int PI, int PF){ // modo recursivo
	int pi=PI, pf=PF-1, pos;
	pos=(pi+pf)/2; //dividindo o vetor ao meio
	if(num==vet[pos]) return pos; //retornando a posição do numero se ele for encontrado
	if(pi>=pf) return -1; //numero ñ encontrado
	else{
		if(num<vet[pos]) return buscaBinaria(vet, num, pos+1, pf); //o numero esta a direita do meio 
		else return buscaBinaria(vet, num, pi, pos-1); //o numeor esta a esquerda do meio
	}
}

int main(){
	int tam; //tamanho do vetor
	cin>>tam;
	int vet[tam], n;
	for(int i=0; i<tam; i++){ //preencher o vetor
		cin>>vet[i];
	}
	cin>>n;
	sort(vet, vet+tam); //ordena o vetor
	cout<<"Interativo: "<<BuscaBinaria(vet, n, tam)<<endl; //posição do numero
	cout<<"Recursivo: "<<buscaBinaria(vet, n, 0, tam)<<endl; // posição do numero
}
