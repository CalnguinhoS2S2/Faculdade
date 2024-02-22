#include <bits/stdc++.h>
#define entra freopen("input.txt", "r", stdin);
#define sai freopen("output.txt", "w", stdout);
#define sz(x) ((int)x.size())
#define ff first
#define ss second
typedef long long ll;

using namespace std;

const int maxn=1e6;

vector<int> pai;
vector<pair<ll, ll>> adj[maxn];
ll dist[maxn];
int n, m;

void djk(int x){
	pai.push_back(x+1);
	for(int i=0; i<maxn; i++) dist[i]=1e6;
	dist[x]=0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, x});
	while(!pq.empty()){
		pair<ll, ll> u=pq.top(); pq.pop();
		if(dist[u.ss]<u.ff)continue;
		bool check=true;
		for(pair<ll, ll> aux: adj[u.ss]){
			ll xx=aux.ff, px=aux.ss;
			if(u.ff+px<dist[xx]){
				if(xx+1==n) check=false;
				if(check) pai.push_back(xx+1);
				dist[xx]=u.ff+px;
				pq.push({u.ff+px, xx});
			}
		}
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int a, b, c;cin>>a>>b>>c;
		adj[a-1].push_back({b-1,c});
		adj[b-1].push_back({a-1,c});
	}
	djk(0);
	cout<<dist[n-1]<<endl;
	for(auto x:pai) cout<<x<<" ";
}
