#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
using namespace std;

const int maxn = 40;

vector<pair<string, int>> cidades[maxn]; // 36 cidades
bool vis[maxn]={0};
int trens[maxn]={0};
set<string> ord;
vector<string> city={"Caracas", 
	"Bocota", 
	"Boa Vista", 
	"Pico Da Neblina", 
	"Cruzeiro Do Sul", 
	"Lima", 
	"Tabatinga", 
	"Manaus", 
	"Porto Velho", 
	"Rio Branco",
	"La Paz",
	"Belem",
	"Altamira",
	"SA. Dos Carajas",
	"Cuiaba",
	"Campo Grande",
	"Assuncao",
	"Buenos Aires",
	"Sao Luis",
	"Fortaleza",
	"Teresina",
	"Juazeiro",
	"Palmas",
	"Recife",
	"Salvador",
	"Brasilia",
	"Uberlandia",
	"BH",
	"Porto Seguro",
	"Vitoria",
	"Rio de Janeiro",
	"Sao Paulo",
	"Foz Do Iguacu",
	"Curitiba",
	"Porto Alecre",
	"Montevideu"};


void dfs(string i){
	//vis[cidades[i]]=1;
}

int main(){
    int cont=0;
    for(int i=0; i<37; i++){
        string Cids;cin>>Cids;
        ord.insert(Cids);
        if(!ord.count(Cids)) cont++;
        int n;cin>>n; // numero de cidades que uma cidade conecta
        for(int j=0; j<n; j++){
            string a;
            cin>>a;
            cidades[{Cids, cont}].push_back(a);
        }
    }
}
