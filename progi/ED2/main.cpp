#include "RBTree.h"

int item, posicao;

RBTree arvore;


int isValidItem()
{
    int item=-1;
    string strItem;

    while (1)
    {
        cout << endl << "Digite um numero inteiro positivo : ";
        getline(cin, strItem);
        try
        {
             item=atoi(strItem.c_str());

             if (item>=0)
             {
                return item;
             }
             else
                throw strItem;
        }
        catch (string strItem)
        {
              cout << endl << endl << "Valor invalido: " << strItem << endl;
              cout << "Tecle algo para continuar..." << endl;
              cin.ignore();
        }
    }
}


int isValidPosition(int tamLista)
{
    int posicao=-1;
    string strPosicao;

    while (1)
    {
        cout << endl << "Digite uma posicao valida : ";
        getline(cin,strPosicao);
        try
        {
             posicao=atoi(strPosicao.c_str());
             if (posicao==1 && tamLista==0)
             {
                   return posicao;
             }
             else
                if ( posicao>=1 && posicao <= tamLista )
                {
                   return posicao;
                }
                else
                    throw strPosicao;
        }
        catch (string strPosicao)
        {
              cout << endl << endl << "Posicao invalida: " << strPosicao << endl;
              cout << "Tecle algo para continuar..." << endl;
              cin.ignore();
        }
    }
}


int main()
{
    int opcao=-1;
    string op;

    while (1)
    {
		cout << "              RB TREE" << endl;
		cout << "            (ARVORE RB)   " << endl << endl;
		cout << "       ###############################################" << endl;
		cout << "       ##                                           ##" << endl;
		cout << "       ##      [Selecione uma operacao]             ##" << endl;
		cout << "       ##                                           ##" << endl;
		cout << "       ##   1  - Insert Node                        ##" << endl;
		cout << "       ##   2  - Clear Tree                         ##" << endl;
		cout << "       ##   3  - Depth Search (In Order)            ##" << endl;
		cout << "       ##   4  - Depth Search (Pre Order)           ##" << endl;
		cout << "       ##   5  - Depth Search (Pos Order)           ##" << endl;
		cout << "       ##   6  - Print Tree                         ##" << endl;
		cout << "       ##   7  - Print Number of Elements           ##" << endl;
		cout << "       ##   8  - Exit                               ##" << endl;
		cout << "       ##                                           ##" << endl;
		cout << "       ###############################################" << endl;
		cout << endl;
		cout << "Digite a opcao: ";
			getline(cin,op);
		   opcao=atoi(op.c_str());
		   if (opcao > 0 && opcao <= 8){
				if(opcao==1){
					item=isValidItem();
					 arvore.insert(item);
				 }
				else if(opcao==2){
					arvore.clearTree();
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				else if(opcao==3){
					arvore.inorder();
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				else if(opcao==4){
					arvore.preorder();
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				else if(opcao==5){
					arvore.posorder();
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				 else if(opcao==6){
					arvore.prettyPrint();
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				else if(opcao==7){
					cout << arvore.getN() << endl;
					cout << "Tecle algo para continuar..." << endl;
					cin.ignore();
				}
				else if(opcao==8) {
					return 0;
				}
			}
		   else{
			  cout << endl << endl << "Opcao invalida: " << op << endl;
			  cout << "Tecle algo para continuar..." << endl;
			  cin.ignore();
		  }
	  }
    return 0;
}
