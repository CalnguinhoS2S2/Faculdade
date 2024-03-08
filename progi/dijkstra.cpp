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

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

// parametros:
// G = grafo 
// source = vertice onde vamos comecar o dijkstra 
// destination = vertice onde queremos chegar a partir do source

pair<vector<int>, int> dijkstra(vector<vector<pair<int, int>>> const& G, int source, int destination) {
   vector<int> par(size(G), -1);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; Q.emplace(0, source);
   vector<int> D(size(G), INF); D[source] = 0;
   while(!empty(Q)) {
      auto [cost, cur] = Q.top(); Q.pop();

      if(D[cur] < cost) continue; 

      // se a resposta de agr for melhor do que o peso na priority
      // quer dizer que nao tem como melhorar mais essa resposta

      for(auto [nxt, weight] : G[cur]) {
         if(D[nxt] > weight + cost) {

            // quer dizer que vale a pena pegar essa aresta 
            // entao eu vou pegar essa aresta e atualizar o pai desse cara 
            // e vou colocar esse cara nra priority pra poder rodar a partir dele

            D[nxt] = weight + cost;
            Q.emplace(D[nxt], nxt);
            par[nxt] = cur;
         }
      }
   }

   // quando eu sair daqui eu tenho os valores corretos
   // agr so falta recuperar o caminho

   // como o dijkstra rodou a partir do vertice 'source' 
   // ele vai ter o caminho de source para todos os outros vertices 
   // entao pra recuperar o caminho eu simplesmente vou passar
   // pelo caminho ao contrario, começando do vertice aonde eu quero chegar

   vector<int> path;
   int cur = destination;
   while(cur != -1) {
      path.emplace_back(cur);
      cur = par[cur];
   }

   // o vetor path vai ter o caminho do fim ate o comeco
   // entao vamos usar um reverse pra ter o caminho do comeco ate o fim

   reverse(begin(path), end(path));

   // essa funcao vai retornar o caminho e o custo para chegar ate aquele vertice
   // eh so um modelo pra vc enteder, ent tem varias coisas que da pra fazer diferente
   // mas acho que da pra ter uma nocao boa de como implementar a partir disso daqui

   return pair<vector<int>, int>(path, D[destination]);
}

auto main() -> signed {

}
