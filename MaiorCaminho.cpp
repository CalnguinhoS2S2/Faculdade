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

class btree{
	public:
		bnode *root;
		int N, h;
		int MC= INT_MIN;
		
		btree(){
			root=0;
			N=h=0;
		}
		
		~btree(){
			clear(&root, N);
		}
		
		bool insert(int x){
			bnode *P= bnode::montaNode(x);
			if(!P) return false;
			
			btree::insert(&root, P);
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
		
		void clear(bnode **p, int &n){
			if(*p==0) return;
            if((*p)->right) clear(&(*p)->right,N);
            if((*p)->left) clear(&(*p)->left,N);
            if(*p==root) root=0;
            if(*p) bnode::desmontaNode((*p));
            N=0;
		}
		
		int H(){
			return btree::H(root);
		}
		
		int H(bnode *R){
			if(!R) return 0;
			int l=H(R->left);
			int r=H(R->right);
			return 1+max(l, r);
		}
		
		int MaiorCaminho(){
			btree::MaiorCaminho(root);
			return MC;
		}
		
		int MaiorCaminho(bnode *R){
			if(!R) return 0;
			int l=MaiorCaminho(R->left);
			int r=MaiorCaminho(R->right);
			if((R->left || R->right) && MC<l+r+R->D){
				MC=l+r+R->D;
			}
			if(r>l) return r+R->D;
			return l+R->D;
		}
};

int main(){
	
	btree bb;
	int n, elementos;
	cout<<"Numero de elementos da arvore: ";
	cin>>n;
	while(n--){
		cin>>elementos;
		bb.insert(elementos);
	}
	cout<<"O MAIOR Caminho dessa arvore eh: "<<bb.MaiorCaminho()<<endl;
}
