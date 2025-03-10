#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define pb push_back
#define endl "\n"

char mt[1001][1001];
int n, m;
bool vis[1001][1001];
int ps[1001][1001];
int maior = INT_MIN;
int di[] = {-1,-1,0,1,1,1,0,-1}, dj[] = {0,1,1,1,0,-1,-1,-1};
map<char, int> alf = {{'A',0},{'B',1},{'C',2},{'D',3},{'E',4},{'F',5},{'G',6},{'H',7},{'I',8},{'J',9},{'K',10},{'L',11},{'M',12},{'N',13},{'O',14},{'P',15},{'Q',16},{'R',17},{'S',18},{'T',19},{'U',20},{'V',21},{'W',22},{'X',23},{'Y',24},{'Z',25}};
string alff = "ABCDEFGHIJKLMNOPQRSTUVHXYZ";

void bfs(int i, int j){
  int tt=alf[mt[i][j]];
  ps[i][j] = 1;
  
	queue<pair<int,int>> q; q.push({i,j});
	while(!q.empty()){
    cout<<"TT-->"<<tt<<endl;
    cout<<alff[tt]<<"-->"<<alff[tt+1]<<endl;
		int x = q.front().ff, y = q.front().ss;q.pop();
		vis[x][y]=1;
		for(int k=0;k<8;k++){
			int ni = x+di[k], nj = y+dj[k];
			if(ni>=0&&ni<n&&nj>=0&&nj<m){
        if(vis[ni][nj]==0&&mt[ni][nj]==alff[tt+1]){
          tt++;
          ps[ni][nj]=ps[x][y]+1;
          q.push({ni,nj});
          if(maior<ps[ni][nj]) maior = ps[ni][nj];
        }
			}
		}
	}
}

signed main(){
  memset(vis,false,sizeof(vis));
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mt[i][j];
        }
    }
    bfs(n-1,m-1);
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        cout<<ps[i][j]<<" ";
      }
      cout<<endl;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         memset(vis,false,sizeof(vis));
    //         memset(ps,0,sizeof(ps));
    //         bfs(i,j);
    //     }
    // }
    cout<<maior<<endl;
}
