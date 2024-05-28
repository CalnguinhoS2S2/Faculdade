#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())
#define ff first
#define ss second

const int INTERACAO = 100; // numero de interações q sera feita
const int MAX_CIDADES = 5; // numero de cidades
const int NUM_FOR = MAX_CIDADES; // numero de formigas
const double ALPHA = 1; // parâmetro de influencia da distância
const double BETA = 1; // parâmetro de influencia do feromônio
const double Q = 10; // constante de atualização de feromônio
const double EVAPORACAO = 0.01;

vector<pair<int, int>> adj[MAX_CIDADES];
vector<bool> visitado(MAX_CIDADES, false);
vector<double> probabilidade(MAX_CIDADES, 0);
vector<vector<double>>feromonio(MAX_CIDADES, vector<double>(MAX_CIDADES, 0.1));
vector<int> MelhorCaminho;



int main(){
    int menorCusto=INT_MIN;
    //crio as conecxões das cidades com os suas respectivas distâncias 
    for(int i=0; i<MAX_CIDADES; i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }


    for(int i=0; i<INTERACAO; i++){

    }
}
