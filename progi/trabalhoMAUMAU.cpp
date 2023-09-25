#include <iostream>
using namespace std;

class node{
	public:
		jogo D;
		node *next;
		static node *montaNode(jogo Dat){
			node *P=new node;
			if(P){
				P->D=Dat;
				P->next=0;
			}
			return P;
		}
		static jogo desmontaNode(node *P){
			jogo x;
			if(P){
				x=P->D;
				delete P;
			}
			return x;
		}
};

class stack{
	public:
		node *top;
		int N;
		stack(){
			top=0;
			N=0;
		}
		~stack(){
			node *P;
			while(top){
				P=top;
				top=top->next;
				node::desmontaNode(P);
			}
		}
		bool push(jogo x){
			node *P=node::montaNode(x);
			if(!P) return false;
			P->next=top;
			top=P;
			N++;
			return true;
		}
		jogo Top(){
			jogo x;
			if(top) x=top->D;
			return x;
		}
		int size(){
			return N;
		}
		bool empty(){
			return !N;
		}
		jogo pop(){
			jogo x;
			if(top){
				node *P=top;
				top=top->next;
				x=node::desmontaNode(P);
				N--;
			}
			return x;
		}
		void clean();
};

class nodelist{
	public:
		trem D;
		nodelist *next;
		nodelist *prev;
		static nodelist *montaNode(trem Dat){
			nodelist *P=new node;
			if(P){
				P->D=Dat;
				P->next=0;
				P->prev=0;
			}
			return P;
		}
		static trem desmontaNode(nodelist *P){
			trem x;
			if(P){
				x=P->D;
				delete P;
			}
			return x;
		}
};

class ClistDE{
	nodelist *head;
	nodelist *It;
	int N;
	ClisteDE(){
		head=0;
		It=0;
		N=0;
	}
	~ClistDE(){
		if(It==0) return;
    	nodelist *P=It;
    	It=It->prev;
    	if(It==P){
        	It=0;
        	head=0;
        	N=0;
        	nodelist::desmontaNode(P);
    	}
    	else{
        	while(p!=It){
            	nodelist *aux=p->next;
            	nodelist::desmontaNode(P);
            	p=aux;
        	}
        	nodelist::desmontaNode(p);
        	It=0;
        	head=0;
        	N=0;
    	}
	}
	bool Insert(trem x){
		nodelist *P=nodelist::montaNode(x);
		if(!P) return false;
		if(!head) head=It=P->next=P->prev=P;
		else{
			P->prev=head->prev;
			P->next=head;
			(head->prev)->next=P;
			head->prev=P;
			head=P;
		}
		N++;
		return true;
	}
	
};
