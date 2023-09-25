#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

using namespace std;

const int maxn = 100025;

vector<int> adj[maxn];
bool vis[maxn]={0};
int dist[maxn]={0};

void bfs(int ori){
	
	vis[ori]=1;
	queue<int> q; q.push(ori);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int x :adj[u]){
			if(vis[x]==0){
				dist[x] = dist[u]+1;
				vis[x] = 1;
				q.push(x);
			}
		}
	}
}

void dfs(int v){
	vis[v]=1;
	for(int x :adj[v])
		if(vis[x]==0) dfs(x);
}

int main () {
	
	fast;
	int v, e, q, ori; cin >> v >> e >> q;
	for(int i=0, x, y;i<e;i++){
		cin >> x >> y;
		adj[x].push_back(y);
	}
	cin >> ori;
	//~ bfs(ori);
	dfs(ori);
	for(int i=0, x; i<q;i++){
		cin >> x;
		cout << vis[x] << " \n"[i+1==q];
	}
}

/*
2<= v,e,q <= 10e5

2 <= ai,bi,ci,di <=v

ai->bi

v e q
ai bi

ci
di 


4 4 3  n_vertice n_arestas n_perguntas
1 2
2 3
3 1
4 1
1 origem
2
3
4



1 : 2
2 : 3
3 : 1



1 2
*/