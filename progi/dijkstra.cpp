typedef long long ll;
const int maxv = 25;
ll dist[maxv];
vector<pair<int,int>> adj[maxv]; //first sendo para onde eu vou, second sendo o custo da viagem
void dijkstra(int o){
    for(int i=0;i<maxv;i++){
        dist[i] = LLONG_MAX;
    }
    dist[o] = 0LL;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0LL, o});
    while(!pq.empty()){
        pair<ll, int> u = pq.top();
        pq.pop();
        if(dist[u.second]<u.first) continue;
        for(pair<ll, int> ax : adj[u.second]){
            int x = ax.first;
            ll px = ax.second;
            if(u.first+px<dist[x]){
                dist[x] = u.first+px;
                pq.push({u.first+px, x});
            }
        }
        
    }
    
    
}
