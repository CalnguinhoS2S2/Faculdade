#include <iostream>
using namespace std;

void merge(int *vetor, int ini, int meio, int fim, int *vetAux) {
    int esq=ini, dir=meio;
    for(int i=ini; i<fim; i++) {
        if ((esq < meio) && ((dir>=fim) || (vetor[esq]<vetor[dir]))) {
            vetAux[i] = vetor[esq];
            ++esq;
        }
        else {
            vetAux[i]=vetor[dir];
            ++dir;
        }
    }
    for (int i=ini; i<fim; i++) {
        vetor[i]=vetAux[i];
    }
}

void mergeSort(int *vetor, int inicio, int fim, int *vetorAux) {
    if ((fim - inicio)<2){
    	return;
	}
    int meio=(inicio + fim)/2;
    mergeSort(vetor, inicio, meio, vetorAux);
    mergeSort(vetor, meio, fim, vetorAux);
    merge(vetor, inicio, meio, fim, vetorAux);
}

int main(){
	int tam;
	cin>>tam;
	int vet[tam], aux[tam];
	for(int i=0; i<tam; i++) cin>>vet[i];
	mergeSort(vet, 0, tam, aux);
	for(int i=0; i<tam; i++){
		cout<<vet[i];
		if(i<tam-1) cout<<" ";
	}
}
