#include <bits/stdc++.h>
using namespace std;

void BubbleSortNum(vector<pair<int,string>> &lista,int tam){
    for(int fim=tam-1;fim>0;fim--){
        for(int i=0;i<fim;i++){
            if(lista[i].first>lista[i+1].first){
				        pair<int,string> aux;
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
        }
    }
}

void BubbleSortChar(vector<pair<int,string>> &lista,int tam){
    for(int fim=tam-1;fim>0;fim--){
        for(int i=0;i<fim;i++){
            if(lista[i].second>lista[i+1].second){
				        pair<int,string> aux;
                aux=lista[i];
                lista[i]=lista[i+1];
                lista[i+1]=aux;
            }
        }
    }
}

void troca(pair<int,string> &a,pair<int,string> &b) {
    pair<int,string>temp = a;
    a = b;
    b = temp;
}

int metadenum(vector<pair<int,string>> &lista, int low, int high) {
    pair<int,string>pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (lista[j].first <= pivot.first) {
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

int metadechar(vector<pair<int,string>> &lista, int low, int high) {
    pair<int,string>pivot = lista[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (lista[j].second <= pivot.second) {
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

void QuickSortNum(vector<pair<int,string>> &lista, int low, int high) {
    if (low < high) {
        int pi = metadenum(lista, low, high);
        QuickSortNum(lista, low, pi - 1);
        QuickSortNum(lista, pi + 1, high);
    }
}

void QuickSortChar(vector<pair<int,string>> &lista, int low, int high){
      if (low < high) {
        int pi = metadechar(lista, low, high);
        QuickSortChar(lista, low, pi - 1);
        QuickSortChar(lista, pi + 1, high);
      }
}

void SelectionSortNum(vector<pair<int,string>> &lista,int tam){
	
	for(int i=0;i<tam-1;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].first<lista[i].first){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}

void SelectionSortChar(vector<pair<int,string>> &lista,int tam){
	
	for(int i=0;i<tam-1;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].second<lista[i].second){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}

int main(){

    double time_spent = 0.0;

    FILE *arq = fopen("lista.txt", "rt");
    char linha[1000],*result;
    string f1,f2,tipo;
    vector<pair<int,string>> lista;
    int opc;

    clock_t begin = clock();
    while (!feof(arq))
    {
      result = fgets(linha, 1000, arq);  
      if (result){
        stringstream ss;
        ss<<linha;
        ss>>f1>>f2;
        lista.push_back({stoi(f1),f2}); //number and string
      }
    }
    fclose(arq);
  

    cout<<"ESCOLHA A FORMA DE ORDENACAO: "<<endl;
    cout<<"1- NUMERICA."<<endl;
    cout<<"2- ALFABETICA."<<endl;
    cout<<"OPCAO: ";
    cin>>opc;

    cout<<endl;

    cout<<"ESCOLHA A ORDENACAO A SER USADA: "<<endl;
    cout<<"BBNUM == BUBBLE_SORT NUMERICO."<<endl; //CORRETO
    cout<<"BBCHAR == BUBBLE_SORT ALFABETICO."<<endl; //CORRETO
    cout<<"SSNUM == SELECTION_SORT NUMERICO."<<endl; //CORRETO
    cout<<"SSCHAR == SELECTION_SORT ALFABETICO."<<endl; //CORRETO
    cout<<"QSNUM == QUICK_SORT NUMERICO."<<endl; //CORRETO
    cout<<"QSCHAR == QUICK_SORT ALFABETICO."<<endl; //CORRETO
    cout<<"TIPO: ";
    cin>>tipo;
    
    cout<<endl;

    if(opc==1 and tipo=="BBNUM")BubbleSortNum(lista,lista.size());
    else if(opc==2 and tipo=="BBCHAR") BubbleSortChar(lista,lista.size());
    else if(opc==1 and tipo=="SSNUM") SelectionSortNum(lista,lista.size());
    else if(opc==2 and tipo=="SSCHAR") SelectionSortChar(lista,lista.size());
    else if(opc==1 and tipo=="QSNUM") QuickSortNum(lista,0,lista.size()-1);
    else if(opc==2 and tipo=="QSCHAR") QuickSortChar(lista,0,lista.size()-1);
    else{
		tipo="INVALIDO";
		cout<<"OPCAO OU TIPO DE ORDENACAO ESCOLHIDA INVALIDA"<<endl;
	}
    
    if(tipo!="INVALIDO"){
        cout<<"ORDENACAO ESCOLHIDA: "<<(opc==1?"NUMERICA ":"ALFABETICA ")<<" "<<tipo<<endl<<endl;
        for(auto k : lista){
            cout<<k.first<<". "<<k.second<<endl;
        }
    }

    cout<<endl;

    ofstream arq1;
    arq1.open("lista.txt");
    //if(arq1.is_open()) cout<<"arquivo aberto"<<endl;
    for(int i=0;i<(int)lista.size();i++){
      f1=to_string(lista[i].first);
      f1+=". "+lista[i].second+'\n';
      arq1<<f1;
    }
    arq1.close();
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(3);
    cout<<"SECONDS: "<<time_spent<<endl;


		//OS TEMPOS FORAM CALCULADOS NO WINDOWS COM O COMPILADOR GEANY(TEMPOS APROXIMADOS)
        //tempo gasto na ordenação(BUBBLESORT) numerica = 6.023
        //tempo gasto na ordenação(BUBBLESORT) afabetica = 4.397

        //tempo gasto na ordenação(SELECTIONSORT) numerica = 4.521
        //tempo gasto na ordenação(SELECTIONSORT) afabetica = 5.159

        //tempo gasto na ordenação(QUICKSORT) numerica = 4.036
        //tempo gasto na ordenação(QUICKSORT) afabetica = 3.673
}
