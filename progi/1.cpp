#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define ff first
#define ss second
using namespace std;

const int maxn=21;
int cnt=0;
char mt[maxn][maxn];
bool vis[maxn][maxn]={0};
int r, c, dist[maxn][maxn]={0}, vi[4] = {-1, 0, 1, 0}, vj[4] = { 0, 1, 0,-1};
vector<pair<int, int>> coor;

void show(){for(int z=0;z<r;z++){for(int y=0;y<c;y++){cout << mt[z][y];}cout<<'\n';}cout << '\n';}

void bfs(){
	for(auto x:coor){
		cout<<x.ff<<' '<<x.ss<<endl;
		vis[x.ff][x.ss]=1;
		dist[x.ff][x.ss]=0;
		mt[x.ff][x.ss]='.';
		int bomb=mt[x.ff][x.ss]-48;
		queue<pair<int, int>> q; q.push({x.ff, x.ss});
		while(!q.empty()){
			int i=q.front().ff, j=q.front().ss; q.pop();
			for(int k=0; k<4; k++){
				int ni=i+vi[k], nj=j+vj[k];
				if(ni>=0&&ni<=bomb&&nj>=0&&nj<bomb&&vis[ni][nj]==0&&(mt[ni][nj]=='.'||mt[ni][nj]=='#')){
					vis[ni][nj]=1;
					dist[ni][nj]=dist[i][j]+1;
					if(dist[ni][nj]!=0&&dist[ni][nj]<=bomb) mt[ni][nj]='.';
					q.push({ni, nj});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>mt[i][j];
			if(mt[i][j]!='.' && mt[i][j]!='#'){
				coor.push_back({i, j});
			}
		}
	}
	bfs();
	show();
}
