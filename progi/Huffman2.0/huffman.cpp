#include <bits/stdc++.h>
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);
using namespace std;

class bnode{
	public:
	bnode *left; //n� a esquerda
	bnode *right; //n� a direita
	int f; //frequ�ncia da letra
	char letra; //letra
	bnode(){
		left=right=NULL;
		f=0,
		letra='%';
	}
	bnode(int ff, char l){
		this->left = this->right = NULL;
		this->f =ff;
		this->letra = l;
	}
};

class huff{
	public:
	priority_queue<pair<int,bnode*>, vector<pair<int,bnode*>>, greater<pair<int,bnode*>>> fila;
	map<char, int> mp; //map para armazena a frequ�ncia da letra
	map<char, string> cdo;//map para armazenar a a letra e o seu codigo em bi
	void cod(bnode *root, string aux){
		if(root->left==0 && root->right==0){
			cdo[root->letra]=aux;
			//return;
		}
		if(root->left) cod(root->left, aux+"0");
		if(root->right) cod(root->right, aux+"1");
		
	}
	huff(){
		string aux, cd;
		while(cin>>cd){
			aux+=cd+" ";
		}
		
		for(int i=0; i<(int)aux.size(); i++){
			if(aux[i]!=' ') mp[aux[i]]++;
		}
		for(auto i: mp){
			bnode * x = new bnode;
			x->letra = i.first,x->f=i.second;
			x->left;
			x->right;
			fila.push({i.second,x});
		}
		
		if((int)aux.size() == 1) {
            auto t = new bnode;
            t->left = fila.top().second;
            t->right = NULL; 
            fila.pop();
        }
		while((int)fila.size() > 1) {
            bnode *r = fila.top().second;
            fila.pop();
            bnode *l = fila.top().second;
            fila.pop();
            bnode *t = new bnode ;
            t->left= r;
            t->right= l;
            t->f=r->f + l->f;
            t->letra='%';
            fila.push({t->f,t});
        }
        cod(fila.top().second, "");
        for(auto [a, b]: cdo){
			cout<<a<<"---"<<b<<endl;
		}
        
		for(int i=0; i<(int)aux.size(); i++){
			if(aux[i]==' ' && i<(int)aux.size()-2) cout<<"*";
			else cout<<cdo[aux[i]];
		}
	}
};

int main(){
	entrada saida
	huff();
}
