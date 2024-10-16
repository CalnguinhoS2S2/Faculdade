#include "pilha.h"
#include "node.h"
#include "trem.h"
#include <iostream>

using namespace std;

static node::montaNode(trem Dat){
	node *P=new node;
	if(P){
		P->D=Dat;
		P->next=0;
	}
	return P;
}

static trem node::desmontaNode(node *P){
	if(p){
		trem x=P->D;
		delete P;
		return x;
	}
}

stack::stack(){
	top=N=0;
}

stack::~stack(){
	node *P;
	while(top){
		p=top;
		top=top->next;
		node::desmontaNode(P);
	}
}

bool stack::push(trem x){
	node *P=montaNode(x);
	if(!P) return false;
	P->next=top;
	top=P;
	N++;
	return true;
}

int stack::top(){
	trem x;
	if(top) x=top->D;
	return x;
}

trem stack::pop(){
	trem x;
	if(top){
		node *P=top;
		top=top->next;
		x=node::desmontaNode(P);
		n--;
	}
	return x;
}

int stack::size(){
	return N;
}

bool stack::empty(){
	return !top;;
}

int main(){
	stack p;
	cout<<p.size();
}
