#include <bits/stdc++.h>
#include <queue>
#include <vector>
template<class trem> 
class tNode{
public:
	trem D;
	tNode<trem>* right;
	tNode<trem>* left;
	static tNode<trem>* montaNode(trem dat);
	static trem desmontaNode(tNode<trem>* P);
};
template<class trem>
tNode<trem>* tNode<trem>::montaNode(trem dat){
	tNode<trem>* P = new tNode<trem>;
	if(P){
		P->D=dat;
		P->right=0;
		P->left=0;
	}
	return P;
}
template<class trem>
trem tNode<trem>::desmontaNode(tNode<trem>* P){
	trem x;
	if(P){
		x=P->D;
		delete P;
	}
	return x;
}

template<class trem>
class bTree
{
public:
    tNode<trem>* root;
    int N;
    std::string array;
    bTree(){
        root = 0;
        N = 0;
    }
    ~bTree(){
        bTree<trem>::clear(root);
    }
    bool insert(trem x){
        tNode<trem>* P = tNode<trem>::montaNode(x);
        if(!P)
            return false;
        insert(&root, P);
        N++;
        return true;
    }
    void insert(tNode<trem>** R, tNode<trem>* aux){
        if(!(*R)){
            *R = aux;
            return;
        }
        std::queue<tNode<trem>*> q;
        q.push(*R);
        while(!q.empty()){
            if(q.front()->left) q.push(q.front()->left);
            else{
                q.front()->left = aux;
                return;
            }
            if(q.front()->right) q.push(q.front()->right);
            else{
                q.front()->right = aux;
                return;
            }
            q.pop();
        }
        return;
    }
    void inorder(){
        bTree<trem>::inorder(root);
    }
    void inorder(tNode<trem>*R)
    {
        if (!R)
            return;
        bTree<trem>::inorder(R->left);
        array += std::to_string(R->D);
        bTree<trem>::inorder(R->right);
    }
    void clear(){
        bTree<trem>::clear(root);
        N=0;
    }
    bool check(int i){
		int j, k;
		for(j=0, k=i-1; array[j] == array[k] and j != k; j++, k--);
		return (j == k);
	}
    static void clear(tNode<trem>* R){
        if(R) {
            if(R->left){
                bTree<trem>::clear(R->left);
            }
            if(R->right){
                bTree<trem>::clear(R->right);
            }
            tNode<trem>::desmontaNode(R);
        }
    }
    int size(){
        return N;
    }
};
