#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
using namespace std;

const int maxn = 40;

map<string, map<string, int>> cidade;
bool vis[maxn]={0};
int trens[maxn]={0};
set<string> ord;
vector<string> city={};

void iago{
	cidades["vancouver"]["seattle"] = 1;
	cidades["seattle"]["vancouver"] = 1;
	cidades["vancouver"]["calgary"] = 3;
	cidades["calgary"]["vancouver"] = 3;
	cidades["calgary"]["seattle"] = 4;
	cidades["seattle"]["calgary"] = 4;
	cidades["calgary"]["winnipeg"] = 6;
	cidades["calgary"]["helena"] = 4;
	cidades["portland"]["salt lake city"] = 6;
	cidades["portland"]["san francisco"] = 5;
	cidades["helena"]["seattle"] = 6;
	cidades["helena"]["winnipeg"] = 4;
	cidades["helena"]["calgary"] = 4;
	cidades["helena"]["salt lake city"] = 3;
	cidades["helena"]["denver"] = 4;
	cidades["helena"]["omaha"] = 5;
	cidades["helena"]["duluth"] = 6;
	cidades["winnipeg"]["calgary"] = 6;
	cidades["winnipeg"]["helena"] = 4;
	cidades["winnipeg"]["duluth"] = 4;
	cidades["winnipeg"]["sault st. marie"] = 6;
	cidades["portland"]["seattle"] = 1;
	cidades["san francisco"]["portland"] = 5;
	cidades["san francisco"]["salt lake city"] = 5;
	cidades["san francisco"]["los angeles"] = 3;

}

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
