#include <bits/stdc++.h>
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "QuickSort.cpp"

using namespace std;

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
  

    cout<<"ESCOLHA A FORMA DE ORDENAÇÃO: "<<endl;
    cout<<"1- NUMÉRICA."<<endl;
    cout<<"2- ALFABÉTICA."<<endl;
    cout<<"opção: ";
    cin>>opc;

    cout<<endl;

    cout<<"ESCOLHA A ORDENAÇAO A SER USADA: "<<endl;
    cout<<"BBNUM == BUBBLE_SORT NUMÉRICO."<<endl; //CORRETO
    cout<<"BBCHAR == BUBBLE_SORT ALFABÉTICO."<<endl; //CORRETO
    cout<<"SSNUM == SELECTION_SORT NÚMERICO."<<endl; //CORRETO
    cout<<"SSCHAR == SELECTION_SORT ALFABÉTICO."<<endl; //CORRETO
    cout<<"QSNUM == QUICK_SORT NÚMERICO."<<endl; //CORRETO
    cout<<"QSCHAR == QUICK_SORT ALFABÉTICO."<<endl; //CORRETO
    cout<<"tipo: ";
    cin>>tipo;
    
    cout<<endl;

    if(opc==1 and tipo=="BBNUM")BubbleSortNum(lista,lista.size());
    else if(opc==2 and tipo=="BBCHAR") BubbleSortChar(lista,lista.size());
    else if(opc==1 and tipo=="SSNUM") SelectionSortNum(lista,lista.size());
    else if(opc==2 and tipo=="SSCHAR") SelectionSortChar(lista,lista.size());
    else if(opc==1 and tipo=="QSNUM") QuickSortNum(lista,0,lista.size()-1);
    else if(opc==2 and tipo=="QSCHAR") QuickSortChar(lista,0,lista.size()-1);
    else tipo="INVÁLIDO";cout<<"OPÇÃO OU TIPO DE ORDENAÇÃO INVALIDO."<<endl;
    
    if(tipo!="INVÁLIDO"){
        cout<<"ORDENAÇÃO ESCOLHIDA: "<<(opc==1?"NÚMERICA ":"ALFABÉTICA ")<<" "<<tipo<<endl<<endl;
        for(auto k : lista){
            cout<<k.first<<". "<<k.second<<endl;
        }
    }

    cout<<endl;

    ofstream arq1;
    arq1.open("lista.txt");
    if(arq1.is_open()) cout<<"arquivo aberto"<<endl;
    for(int i=0;i<(int)lista.size();i++){
        f1=lista[i].first+"48"+lista[i].second;
        cout<<f1<<endl;
        //arq1<<f1;
    }
    arq1.close();

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(3);
    cout<<"seconds: "<<time_spent<<endl;

        //tempo gasto na ordenação(BUBBLESORT) numerica = 0.000
        //tempo gasto na ordenação(BUBBLESORT) afabetica = 0.000

        //tempo gasto na ordenação(SELECTIONSORT) numerica = 0.000
        //tempo gasto na ordenação(SELECTIONSORT) afabetica = 0.000

        //tempo gasto na ordenação(QUICKSORT) numerica = 0.000
        //tempo gasto na ordenação(QUICKSORT) afabetica = 0.000
}