#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define ff first
#define ss second
using namespace std;

const int maxn=21;

char mt[maxn][maxn];
bool vis[maxn][maxn]={0};
int r, c, dist[maxn][maxn]={0}, vi[4] = {-1, 0, 1, 0}, vj[4] = { 0, 1, 0,-1};

void show(){for(int z=0;z<r;z++){for(int y=0;y<c;y++){cout << mt[z][y] << " \n"[y+1==c];}}cout << "\n";}

void bfs(int i, int j){
	queue<pair<int,int>> q; q.push({i,j});
	while(!q.empty()){
		int x=q.front().ff, y=q.front().ss; q.pop();
		vis[x][y]=1;
		//show();
		for(int k=0;k<4;k++){
			int ni = x+vi[k], nj = y+vj[k];
			if(ni>=0&&ni<r&&nj>=0&&nj<c&&vis[ni][nj]==0&&(mt[ni][nj]=='.'||mt[ni][nj]=='#')){
				dist[ni][nj]=dist[x][y]+1;
				q.push({ni,nj});
			}
		}
	}
}

void bombi(int bomb){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if((dist[i][j]==bomb || dist[i][j]<bomb)&&(mt[i][j]=='.' || mt[i][j]=='#')) mt[i][j]='.';
		}
	}
}

int main(){
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>mt[i][j];
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(mt[i][j]!='.' || mt[i][j]!='#'){
				mt[i][j]='.';
				int bomb=mt[i][j]-48;
				bfs(i, j);
				bombi(bomb);
			}
			memset(dist,0,sizeof(dist));;
		}
	}
	show();
}
