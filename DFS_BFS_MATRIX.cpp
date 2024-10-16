#include <iostream>
#include <queue>

#define ff first
#define ss second

using namespace std;

bool vis[20][20]={0};
char mt[20][20];
int vi[4] = {-1, 0, 1, 0}, vj[4] = { 0, 1, 0,-1},n,m,ps[20][20]={0},c=1;

void show(){
	
	for(int z=0;z<n;z++)
		for(int y=0;y<m;y++)
			cout << ps[z][y] << " \n"[y+1==m];
	cout << "\n";
}

void dfs(int i, int j){
	vis[i][j] = 1;
	show();
	for(int k=0;k<4;k++){
		int ni = i+vi[k], nj = j+vj[k];
		if(ni>=0&&ni<n&&nj>=0&&nj<n&&vis[ni][nj]==0&&mt[ni][nj]=='.'){
			ps[ni][nj]=ps[i][j]+1;
			dfs(ni,nj);
		}
	}
}

void bfs(int i, int j){
	ps[i][j]=0;
	queue<pair<int,int>> q; q.push({i,j});
	while(!q.empty()){
		int x = q.front().ff, y = q.front().ss;q.pop();
		vis[x][y]=1;
		show();
		for(int k=0;k<4;k++){
			int ni = x+vi[k], nj = y+vj[k];
			if(ni>=0&&ni<n&&nj>=0&&nj<m&&vis[ni][nj]==0&&mt[ni][nj]=='.'){
				ps[ni][nj]=ps[x][y]+1;
				q.push({ni,nj});
			}
		}
	}
}


int main (){
	int q;
	cin >> n >> m >> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mt[i][j];
		}
	}
	int oi, oj; cin >> oi >> oj;
	bfs(oi, oj);
	for(int i=0,x,y;i<q;i++){
		cin >> x >> y;
		cout << ps[x][y] << "\n";
 	}
}