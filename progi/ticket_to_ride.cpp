#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
using namespace std;

const int maxn = 40;

map<string, map<string, pair<int, string>>> cidades;
bool vis[maxn]={0};
int trens[maxn]={0};
set<string> ord;
vector<string> city={};

void coneccoes(){
	cidades["vancouver"]["seattle"] = (1,"cinza");
	cidades["seattle"]["vancouver"] = (1,"cinza");
	cidades["vancouver"]["calgary"] = (3,"cinza");
	cidades["calgary"]["vancouver"] = (3,"cinza");
	cidades["calgary"]["seattle"] = (4,"cinza");
	cidades["seattle"]["calgary"] = (4,"cinza");
	cidades["calgary"]["winnipeg"] = (6,"branco");
	cidades["calgary"]["helena"] = (4,"cinza");
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
}
