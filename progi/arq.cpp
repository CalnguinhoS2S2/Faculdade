#include <bits/stdc++.h>
using namespace std;

const int maxn=10;

int main(){
    string instrucao;
    vector<string> vec[maxn], pipeline[maxn];
    vector<string>mp={"IF","ID","EX","MEM","WB","B"};
    memset(pipeline, '0', sizeof(pipeline));
    int c=0, n=0;
    getline(cin, instrucao);
    while(instrucao.size()){
        stringstream ss(instrucao);
        string aux;
        while(ss>>aux){
            int tam=aux.size();
            if(aux[tam-1]==','){
                string aux2;
                for(int i=0; i<aux.size()-1; i++) aux2+=aux[i];
                vec[c].push_back(aux2);
            } else vec[c].push_back(aux);
        }
        c++;n++;
        getline(cin, instrucao);
    }
    cout<<"------------------\n\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<vec[i].size(); j++){
            cout<<vec[i][j]<<" \n"[j+1==vec[i].size()];
        }
    }
    cout<<"------------------\n\n";
    cout<<"PIPELINE: \n";//for(int i=0; i<6; i++) cout<<mp[i]<<" ";
    cout<<"------------------\n\n";
    for(int i=0; ; ){// eu n sei o pq q isso aqui n ta dando certo
        for(int j=0; j<5; j++){
            pipeline[i][j]=mp[j];
        }
    }
    // esse for de cima ta certo mas por algum motivo estou acessando posição invalida na minha matriz ou no meu vetor;
    string ajuda;
    for(int i=1; i<n; i++){
        int cc=0;
        for(int j=i; j<n;){
            pipeline[i][j]=mp[cc];
            cc++;
            if((vec[i-1][0]!="JUMP" || vec[i-1][0]!="JZ") &&((vec[i-1][1]==vec[i][j+1]) || (vec[i-1][1]==vec[i][j+2]))){
                int k=j-1;
                while(pipeline[i-1][k]!="WB"){
                    pipeline[i][k]=mp[5];
                    k++;
                }
            }
            if(vec[i-1][0]=="JZ" || vec[i-1][0]=="JUMP"){
                cout<<"HAZARD DE CONTROLE\n";
                break;
            }
            if(vec[i-1][j]==vec[i][j+1] || vec[i-1][j]==vec[i][j+2]){
                ajuda="HS";
                int k=j;
                while(pipeline[i-1][k]!="WB"){
                    pipeline[i][k]=mp[5];
                    k++;
                }
            }
        }
    }
    if(ajuda=="HS")cout<<"HAZARD DE ESTRUTURA\n";
}
