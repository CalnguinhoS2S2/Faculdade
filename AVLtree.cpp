#include <iostream>
#include <algorithm>
using namespace std;
class trem{
	public:
		int t=0;
};

class Tnode{
	public:
		trem D;
		int fb;
		Tnode *left;
		Tnode *right;
		static Tnode *montaNode(trem Dat){
			Tnode *P=new Tnode;
			if(P){
				P->D=Dat;
				P->left=0;
				P->right=0;

			}
			return P;
		}
		static trem desmontaNode(Tnode *P){
			trem x;
			if(P){
				x=P->D;
				delete P;
			}
			return x;
		}
};

class AVLtree{
	public:
		Tnode root;
		int N;
		trem Min(){
			if(!root){
				trem X;
				return X;
			}
			return Rmin(root);
		}
		
		trem Rmin(Tnode *R){
			if(R->left) return Rmin(R->right);
			return R->D;
		}
		
		trem Max(){
			if(!root){
				trem X;
				return X;
			}
			return Rmax(root);
		}
		
		trem Rmax(Tnode *R){
			if(R->right) return Rmax(R->left);
			return R->D;
		}
		
		int H(Tnode *root){
			int l=H(R->left);
			int r=H(R->right);
			return 1+max(l, r);
		}
		
		AVLtree(){
			root=0;
			N=0;
		}
		
		~AVLtree(){
			clear(&root, n);
		}
		
		void clear(Tnode **p, int &n){
			if(*p==0) return;
            if((*p)->right) clear(&(*p)->right,n);
            if((*p)->left) clear(&(*p)->left,n);
            if(*p==root) root=0;
            if(*p) node::desmontaNode((*p));
            n=0;
		}
		
		Tnode *search(Tnode *R, int X){
			if(!R || (R->D).t==X) return R;
			if(X>(R->D).t) return search(R->left, X);
			return search(R->right, X);
		}
		
		static void RSD(Tnode **R){
			Tnode *a=*R;
			Tnode *b=a->left;
			a->left=b->right;
			b->right=a;
			*R=b;
			b->fb=a->fb=0;
		}
		
		static void RSE(Tnode **R){
			Tnode *a=*R;
			Tnode *b=a->righ;
			a->right=b->left;
			b->left=a;
			*R=b;
			b->fb=a->fb=0;
		}
		
		static void RDD(Tnode**R){
			Tnode *a=*R;
			Tnode *b=a->left;
			Tnode *c=b->right;
			b->right=c->left;
			a->left=c->right;
			c->right=a;
			c->left=b;
			*R=c;
			if(c->fb==0) a->fb=b->fb=0;
			else{
				if(c->fb==-1){
					b->fb=c->fb=0;
					a->fb=1;
				}
				else{
					c->fb=a->fb=0;
					b->fb=-1;
				}
			}
		}
		
		static void RDE(Tnode**R){
			Tnode *a=*R;
			Tnode *b=a->right;
			Tnode *c=b->left;
			b->left=c->right;
			a->right=c->left;
			c->left=a;
			c->righ=b;
			*R=c;
			if(c->fb==0) a->fb=b->fb=0;
			else{
				if(c->fb==1){
					b->fb=c->fb=0;
					a->fb=-1;
				}
				else{
					c->fb=a->fb=0;
					b->fb=1;
				}
			}
		}
		
		static bool insert(Tnode **R, Tnode *aux){
			if(*R){
				*R=aux;
				aux->fb=0;
				return false;
			}
			if(((*R)->D).t==(aux->D).t){
				Tnode::desmontaNode(aux);
				return false;
			}
			if((aux->D).t<((*R)->D).t){
				//insere p/ esquerda
				if(AVLtree::insert(&(*R)->D), aux){
					//aumenta sub esquerda
					if((*R)->fb==0){
						(*R)->fb=-1;
						return true;
					}
					if((*R)->fb==1){
						(*R)->fb=0;
						return false;
					}
					if(((*R)->left)->fb==-1){
						AVLtree::RSD(R);
						return false;
					}
					//RDD
					AVLtree::RDD(R);
					return false;
				}
				//foi p/ esquerda e retornou false
				return false;
			}
			if(AVL::insert(&((*R)->right), aux){
				//sub direita cresceu
				if((*R)->fb==-1){
					(*R)->fb=0;
					return false;
				}
				if((*R)->fb==0){
					(*R)->fb=1;
					return true;
				}
				if(((*R)->right)->fb==1){
					AVLtree::RSE(R);
					return false;
				}
				//RDE;
				AVLtree::RDE(R);
				return false;
			}
		}
		
		static bool erase(Tnode **R, trem X, Tnode **aux){
			if(!(*R)) return false;
			if(X.t<((*R)->D).t){
				//esquerda
				 if(AVLtree::erase(&((*R)->left), X, aux)){
                    if((*R)->fb==-1){
                        (*R)->fb=0;
                        return true;
                    }
                    if((*R)->fb==0){
                        (*R)->fb=1;
						return false;
                    }
                    if(((*R)->right)->fb>=0){
                        AVLtree::RSE(R);
                        return true;
                    }
                    AVLTree::RDE(R);
                    return true;
                }
                return false;
			}
			if(X.t>((*R)->D).t){
				//direita
				if(AVLtree::erase(&((*R)->right), X, aux)){
                    if((*R)->fb==1){
                        (*R)->fb=0;
                        return true;
                    }
                    if((*R)->fb==0){
                        (*R)->fb=-1;
                        return false;
                    }
                    if(((*R)->left)->fb<=0){
                        AVLtree::RSD(R);
                        return true;
                    }
                    AVLtree::RDD(R);
                    return true;
                }
                return false;
			}
			if(!(*R)->left){
                *aux=*R;
                *R=(*R)->right;
                return true;
            }
            if(!(*R)->right){
                *aux=*R;
                *R=(*R)->left;
                return true;
            }
            Tnode M=AVLtree::Rmin((*R)->right);
            swap(M->D, (*R)->D);
            if(AVLtree::erase(&((*R)->right), X, aux)){
                if((*R)->fb==1){
                    (*R)->fb=0;
                    return true;
                }
                if((*R)->fb==0){
                    (*R)->fb=-1;
                    return false;
                }
                if(((*R)->left)->fb<=0){
                    AVLtree::RSD(R);
                    return true;
                }
                AVLtree::RDD(R);
                return true;
            }
            return false;
		}
		
		bool insert(trem X){
			Tnode *P=Tnode::montaNode(X);
			if(!P) return false;
			if(AVLtree::insert(&root, P)){
				N++;
				return true;
			}
			return false;
		}
		
		bool erase(trem X){
			if(!root) return false;
			Tnode *P=0;
			AVLtree::erase(&root, X, &P);
			if(!P==0){
				N--;
				Tnode::desmontaNode(P);
				return true;
			}
			return false;
		}
};
