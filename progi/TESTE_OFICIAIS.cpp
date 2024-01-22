#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define ff first
#define ss second
using namespace std;

const int maxn=1e5;

vector<int> adj[maxn];
bool vis[maxn]={0};

void dfs(int v){
	vis[v]=1;
	for(auto x:adj[v]){
		if(!vis[x]) dfs(x);
	}
}

int main(){
	int n; cin>>n;
	cout<<'\n';
	while(n--){
		int cont=0;
		char nome;cin>>nome;
		int tam=nome-64;
		vector<int> aux;
		for(int i=0; i<tam; i++){
			aux.push_back(i);
		}
		cin.ignore();
		string token;
		getline(cin,token);
		while(sz(token)){
			adj[token[1]-65].push_back(token[2]-65);
			getline(cin,token);
		}
		for(auto x:aux){
			if(!vis[x]){
				dfs(x);
				cont++;
			}
		}

		for(auto x:aux)cout<<x<<' ';
		cout<<'\n';
		for(int i=0; i<tam; i++)cout<<vis[i]<<' ';
		cout<<'\n';
		cout<<cont<<"\n\n";
	}
}
