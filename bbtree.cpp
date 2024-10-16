#include<bits/stdc++.h>
using namespace std;

class trem{
	public:
		int t=0;
};

class bnode{
	public:
		trem D;
		bnode *right;
		bnode *left;
		static bnode *montaNode(trem dat){
			bnode *P=new bnode;
			if(P){
				P->D=dat;
				P->left=0;
				P->right=0;
			}
			return P;
		}
		static trem desmontaNode(bnode *P){
			trem x;
			if(P){
				x=P->D;
				delete P;
			}
			return x;
		}
};
