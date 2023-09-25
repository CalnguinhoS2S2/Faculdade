#include <bits/stdc++.h>
using namespace std;
//QuickSort------------------------------------------------------------------------
void troca(pair<int,string> &a,pair<int,string> &b){
    pair<int,string>temp = a;
    a = b;
    b = temp;
}

int metadenum(vector<pair<int,string> > &lista, int low, int high){
    pair<int,string> pivot = lista[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if (lista[j].first <= pivot.first){
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

void QuickSortNum(vector<pair<int,string> > &lista, int low, int high){
    if(low < high){
        int pi = metadenum(lista, low, high);
        QuickSortNum(lista, low, pi - 1);
        QuickSortNum(lista, pi + 1, high);
    }
}

int metadeSTRING(vector<pair<int,string> > &lista, int low, int high){
    pair<int,string> pivot = lista[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(lista[j].second <= pivot.second){
            i++;
            troca(lista[i], lista[j]);
        }
    }
    troca(lista[i+1],lista[high]);
    return (i + 1);
}

void QuickSortSTRING(vector<pair<int,string> > &lista, int low, int high) {
    if (low < high){
        int pi = metadeSTRING(lista, low, high);
        QuickSortSTRING(lista, low, pi - 1);
        QuickSortSTRING(lista, pi + 1, high);
    }
}
//---------------------------------------------------------------------------------

//SelectionSort--------------------------------------------------------------------
void SelectionSortNum(vector<pair<int,string> > &lista,int tam){
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].first<lista[i].first){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}

void SelectionSortSTRING(vector<pair<int,string> > &lista,int tam){
	for(int i=0;i<tam;i++){
		for(int j=i+1;j<tam;j++){
			if(lista[j].second<lista[i].second){
				pair<int,string> aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
}
//---------------------------------------------------------------------------------

int main(){
	vector<pair<int,string> >lista;
	//LEITURA DE ARQUIVO 
	FILE *file = fopen("farinha.txt", "rt");
	if(file==NULL){
		cout<<"Erro";
	}
	string f1,f2;
	char linha[50];
	int cont=0;
	while(fgets(linha, sizeof(linha), file) && cont < 100){
		cont++;
		stringstream ss;
		ss<<linha;
		ss>>f1>>f2;
		int aux=stoi(f1);
		lista.push_back({aux,f2});
		
	}
	fclose(file);
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//QuickSort---------------------------------------------------------------------------
	//ORDENACAO NUMERICA
	srand(time(0));
	double timespentQ = 0.0;
	clock_t beginQ = clock();
	QuickSortNum(lista, 0, lista.size()-1);
	clock_t endQ = clock();
	cout<<"QuickSort NUM"<<endl;
	for(int i=0;i<(int)lista.size();i++) cout<<lista[i].first<<" "<<lista[i].second<<endl;
	timespentQ += (double)(endQ - beginQ) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(7);
    cout<<"Timer: "<<timespentQ<<endl;
	
	//ORDENACAO ALFABETICA
	srand(time(0));
	double timespentQ1 = 0.0;
	clock_t beginQ1 = clock();
	QuickSortSTRING(lista, 0, lista.size()-1);
	clock_t endQ1 = clock();
	cout<<"QuickSort STRING"<<endl;
	for(int i=0;i<(int)lista.size();i++) cout<<lista[i].first<<" "<<lista[i].second<<endl;
	timespentQ1 += (double)(endQ1 - beginQ1) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(7);
    cout<<"Timer: "<<timespentQ1<<endl;
//------------------------------------------------------------------------------------
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//SelectionSort-----------------------------------------------------------------------
	//ORDENACAO NUMERICA
	srand(time(0));
	double timespentS = 0.0;
	clock_t beginS = clock();
	SelectionSortNum(lista, lista.size()-1);
	clock_t endS = clock();
	cout<<"SelectionSort NUM"<<endl;
	for(int i=0;i<(int)lista.size();i++) cout<<lista[i].first<<" "<<lista[i].second<<endl;
	timespentS += (double)(endS - beginS) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(7);
    cout<<"Timer: "<<timespentS<<endl;
    
	//ORDENACAO ALFABETICA
	srand(time(0));
	double timespentS1 = 0.0;
	clock_t beginS1 = clock();
	SelectionSortSTRING(lista, lista.size()-1);
	clock_t endS1 = clock();
	cout<<"SelectionSort STRING"<<endl;
	for(int i=0;i<(int)lista.size();i++) cout<<lista[i].first<<" "<<lista[i].second<<endl;
	timespentS1 += (double)(endS1 - beginS1) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(7);
    cout<<"Timer: "<<timespentS1<<endl;
//------------------------------------------------------------------------------------
cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	ofstream arq1;
	arq1.open("farinha.txt");
	for(int i=0; i<(int)lista.size(); i++){
		f1=to_string(lista[i].first);
		f1+=". "+lista[i].second+"\n";
		arq1<<f1;
	}
	arq1.close();
}
