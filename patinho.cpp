#include <bits/stdc++.h>
using namespace std;
char mt[1000][1000];
bool vis[1000][1000];
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1},x,y,cont,m,n;

void flood(int i,int j){
    cont++;
    vis[i][j]=true;

    for(int k=0;k<4;k++){
        x=dx[k]+i;
        y=dy[k]+j;
        if(x>=0 && x<m && y>=0 && y<n &&mt[x][y]=='P' && !vis[x][y]){
            flood(x,y);
        } 
    }
}

int main(){
    
    int c,prog,per;
    
    cin>>c;
    while(c--){
        cin>>m>>n;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mt[i][j];
            }
        }
        
        prog=0,per=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and mt[i][j]=='P'){
                    cont=0;
                    flood(i,j);
                    if(cont==2) prog++;
                    else if(cont==1) per++;
                } 
            }
        }
        cout<<per<<endl;
        cout<<prog<<"vamos programar!!"<<endl;
        memset(vis,false,sizeof(vis));
    }
}
