#include <bits/stdc++.h>
using namespace std;
class vet{
	public:
		int *vetor;
		int size;
		vet(int n){
			vetor=new int[n];
			size=n;
		}
		~vet(){
			delete[] vetor;
            cout<<"\noi!!!\n";
		}
		
		void inser(){
			cout<<"Elementos do vetor: ";
			for(int i=0; i<size; i++){
				cin>>vetor[i];
			}
		}
		
		void multi(vet &a){
			for(int i=0; i<size; i++){
				vetor[i]=vetor[i]*a.vetor[i];
				//cout<<vetor[i]<<"ab"<<a.vetor[i]<<" ";
			}
		}
		
		void multi(int A){
			for(int i=0; i<size; i++){
				vetor[i]=vetor[i]*A;
			}
		}
		void show(){
			for(int i=0; i<size; i++){
				cout<<vetor[i]<<" \n"[i+1==size];
			}
		}
		void copi(vet &a){
			for(int i=0; i<size; i++)vetor[i]=a.vetor[i];
		}
};

int main(){
	int n, a;
	cin>>n;
	vet vet1(n), vet2(n), vet3(n);
	vet1.inser();
	vet2.inser();
	vet3.copi(vet1);
    vet1.multi(vet2);
    //cout<<endl;
	cout<<"Multiplicacao do vetor 1 e vetor 2: ";
	vet1.show();
    cout<<"Escolha uma produto escalar: ";
    cin>>a;cout<<endl;
	cout<<"Produto escalar do vetor 1: ";
	vet3.multi(a);
	vet3.show();
	cout<<"Produto escalar do vetor 2: ";
	vet2.multi(a);
	vet2.show();
	return 0;
}