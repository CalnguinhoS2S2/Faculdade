#include <bits/stdc++.h>
using namespace std;

class bnode{
	public:
		int D;
		bnode *right;
		bnode *left;
		static bnode *montaNode(int dat){
			bnode *P=new bnode;
			if(P){
				P->D=dat;
				P->left=0;
				P->right=0;
			}
			return P;
		}
		static int desmontaNode(bnode *P){
			int x;
			if(P){
				x=P->D;
				delete P;
			}
			return x;
		}
};

class btreeEsp{
	public:
		bnode *root;
		int N, h;
		vector<int> sCARA;
		btreeEsp(){
			root=0;
			N=h=0;
		}
		
		~btreeEsp(){
			clear(&root, N);
		}
		bool insert(int x){
			bnode *P= bnode::montaNode(x);
			if(!P) return false;
			
			btreeEsp::insert(&root, P);
			N++;
			return true;
		}
		void insert(bnode **R, bnode *aux){
			if(!(*R)){
				*R=aux;
				return;
			}
			queue<bnode*> fila;
			fila.push(*R);
			while(!fila.empty()){
				bnode* r = fila.front();
				fila.pop();
				if(r->left) fila.push(r->left);
				else{
					r->left=aux;
					break;
				}
				if(r->right) fila.push(r->right);
				else{
					r->right=aux;
					break;
				}
			}
		}
		void InORDER(){
			btreeEsp::InORDER(root);
		}
		void InORDER(bnode *R){
			if(!R) return;
			btreeEsp::InORDER(R->left);
			sCARA.push_back(R->D);
			btreeEsp::InORDER(R->right);
		}
		void clear(bnode **p, int &n){
			if(*p==0) return;
            if((*p)->right) clear(&(*p)->right,N);
            if((*p)->left) clear(&(*p)->left,N);
            if(*p==root) root=0;
            if(*p) bnode::desmontaNode((*p));
            N=0;
		}
		int H(){
			return btreeEsp::H(root);
			
		}
		int H(bnode *R){
			if(!R) return 0;
			int l=H(R->left);
			int r=H(R->right);
			return 1+max(l, r);
		}
		bool palindro(int n){
			int i, j;
			for(i=0, j=n-1; sCARA[i]==sCARA[j] && i!=j; i++, j--);
			return (i==j);
		}
};

int main(){
	btreeEsp bb;
	int n, elementos;
	cout<<"Numeros de elementos:\n";
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>elementos;
		bb.insert(elementos);
	}
	bb.InORDER();
	if(pow(2, bb.H())-1 == n){
		//cout<<"oi\n";
		if(bb.palindro(n)) cout<<"Eh espelhada\n";
		else cout<<"Nao eh espelhada\n";
	}
	else cout<<"Nao eh espelhada\n";
}
