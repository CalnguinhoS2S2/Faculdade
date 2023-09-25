#include <bits/stdc++.h>
using namespace std;

const int maxn=10;

int main(){
    string instrucao;
    vector<string> vec[maxn], pipeline[maxn];
    map<int, string>mp;
    memset(pipeline, '0', sizeof(pipeline));
    mp[1]="IF";mp[2]="ID";mp[3]="EX";mp[4]="MEM";mp[5]="WB";mp[6]="B";
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
    for(int i=0; i<n; i++){
        for(int j=i+1; j<6; j++){
            pipeline[i][j]=mp[j];
        }
    }
}