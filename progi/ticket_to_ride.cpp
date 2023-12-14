#include <bits/stdc++.h>

//#define sz(x) ((int)x.size())
#define ff first
#define ss second

using namespace std;

const int N = 15;

//-----------------variaveis globais-----------------
map<string, map<string, pair<int, string>>> conexoes;
map<string, map<string, pair<bool, string>>> visitado;
map<string, int> dmao;
set<string> ord;
vector<string> city;
multiset<char> carta_aberta;
stack<char> baralho, descarte;
//---------------------------------------------------

struct bilhete{
		string ori;
		string des;
		int pont;
};

struct jogador{
		string nome; //nome do jogador
		int pontos = 0; //pontos do jogador
		int vagoes = 20; //qtd de trens do jogador
		vector<int> mao; //cartas que o jogador tem na mão
		jogador(){ //construtor
			mao.assign(9,0);
		}
		//c V v b p l A a r  carta
		//0 1 2 3 4 5 6 7 8  posiçao no vetor
};

void vis(){
		visitado["vancouver"]["calgary"] = {0," "};
	visitado["vancouver"]["seattle"] = {0," "};
	visitado["seattle"]["vancouver"] = {0," "};
	visitado["seattle"]["helena"] = {0," "};
	visitado["seattle"]["calgary"] = {0," "};
	visitado["seattle"]["portland"] = {0," "};
	visitado["calgary"]["vancouver"] = {0," "};
	visitado["calgary"]["seattle"] = {0," "};
	visitado["calgary"]["winnipeg"] = {0," "};
	visitado["calgary"]["helena"] = {0," "};
	visitado["portland"]["salt lake city"] = {0," "};
	visitado["portland"]["san francisco"] = {0," "};
	visitado["portland"]["san francisco"] = {0," "};
	visitado["portland"]["seattle"] = {0," "};
	visitado["helena"]["seattle"] = {0," "};
	visitado["helena"]["winnipeg"] = {0," "};
	visitado["helena"]["calgary"] = {0," "};
	visitado["helena"]["salt lake city"] = {0," "};
	visitado["helena"]["denver"] = {0," "};
	visitado["helena"]["omaha"] = {0," "};
	visitado["helena"]["duluth"] = {0," "};
	visitado["winnipeg"]["calgary"] = {0," "};
	visitado["winnipeg"]["helena"] = {0," "};
	visitado["winnipeg"]["duluth"] = {0," "};
	visitado["winnipeg"]["sault st. marie"] = {0," "};
	visitado["san francisco"]["portland"] = {0," "};
	visitado["san francisco"]["portland"] = {0," "};
	visitado["san francisco"]["salt lake city"] = {0," "};
	visitado["san francisco"]["salt lake city"] = {0," "};
	visitado["san francisco"]["los angeles"] = {0," "};
	visitado["san francisco"]["los angeles"] = {0," "};
	visitado["los angeles"]["san francisco"] = {0," "};
	visitado["los angeles"]["san francisco"] = {0," "};
	visitado["salt lake city"]["san francisco"] = {0," "};
	visitado["salt lake city"]["san francisco"] = {0," "};
	visitado["salt lake city"]["portland"] = {0," "};
	visitado["salt lake city"]["helena"] = {0," "};
	visitado["salt lake city"]["denver"] = {0," "};
	visitado["salt lake city"]["denver"] = {0," "};
	visitado["denver"]["salt lake city"] = {0," "};
	visitado["denver"]["salt lake city"] = {0," "};
	visitado["denver"]["helena"] = {0," "};
	visitado["denver"]["omaha"] = {0," "};
	visitado["omaha"]["denver"] = {0," "};
	visitado["omaha"]["helena"] = {0," "};
	visitado["omaha"]["duluth"] = {0," "};
	visitado["duluth"]["omaha"] = {0," "};
	visitado["duluth"]["helena"] = {0," "};
	visitado["duluth"]["winnipeg"] = {0," "};
	visitado["duluth"]["sault st. marie"] = {0," "};
	visitado["sault st. marie"]["duluth"] = {0," "};
	visitado["sault st. marie"]["winnipeg"] = {0," "};
	
}

void mapa(){
	conexoes["vancouver"]["calgary"] = {3,"cinza"};
	conexoes["vancouver"]["seattle"] = {1,"cinza"};
	conexoes["seattle"]["vancouver"] = {1,"cinza"};
	conexoes["seattle"]["helena"] = {6,"amarelo"};
	conexoes["seattle"]["calgary"] = {4,"cinza"};
	conexoes["seattle"]["portland"] = {1,"cinza"};
	conexoes["calgary"]["vancouver"] = {3,"cinza"};
	conexoes["calgary"]["seattle"] = {4,"cinza"};
	conexoes["calgary"]["winnipeg"] = {6,"branco"};
	conexoes["calgary"]["helena"] = {4,"cinza"};
	conexoes["portland"]["salt lake city"] = {6,"azul"};
	conexoes["portland"]["san francisco"] = {5,"rosa"};
	conexoes["portland"]["san francisco"] = {5,"verde"};
	conexoes["portland"]["seattle"] = {6,"azul"};
	conexoes["helena"]["seattle"] = {6,"amarelo"};
	conexoes["helena"]["winnipeg"] = {4,"azul"};
	conexoes["helena"]["calgary"] = {4,"cinza"};
	conexoes["helena"]["salt lake city"] = {3,"rosa"};
	conexoes["helena"]["denver"] = {4,"verde"};
	conexoes["helena"]["omaha"] = {5,"vermelho"};
	conexoes["helena"]["duluth"] = {6,"laranja"};
	conexoes["winnipeg"]["calgary"] = {6,"branco"};
	conexoes["winnipeg"]["helena"] = {4,"azul"};
	conexoes["winnipeg"]["duluth"] = {4,"preto"};
	conexoes["winnipeg"]["sault st. marie"] = {6,"cinza"};
	conexoes["san francisco"]["portland"] = {5, "rosa"};
	conexoes["san francisco"]["portland"] = {5, "verde"};
	conexoes["san francisco"]["salt lake city"] = {5,"laranja"};
	conexoes["san francisco"]["salt lake city"] = {5,"branco"};
	conexoes["san francisco"]["los angeles"] = {3,"rosa"};
	conexoes["san francisco"]["los angeles"] = {3,"amarelo"};
	conexoes["los angeles"]["san francisco"] = {3,"rosa"};
	conexoes["los angeles"]["san francisco"] = {3,"amarelo"};
	conexoes["salt lake city"]["san francisco"] = {5,"laranja"};
	conexoes["salt lake city"]["san francisco"] = {5,"branco"};
	conexoes["salt lake city"]["portland"] = {6,"azul"};
	conexoes["salt lake city"]["helena"] = {3,"rosa"};
	conexoes["salt lake city"]["denver"] = {3,"vermelho"};
	conexoes["salt lake city"]["denver"] = {3,"amarelo"};
	conexoes["denver"]["salt lake city"] = {3,"vermelho"};
	conexoes["denver"]["salt lake city"] = {3,"amarelo"};
	conexoes["denver"]["helena"] = {4,"verde"};
	conexoes["denver"]["omaha"] = {4,"rosa"};
	conexoes["omaha"]["denver"] = {4,"rosa"};
	conexoes["omaha"]["helena"] = {5,"vermelho"};
	conexoes["omaha"]["duluth"] = {2,"cinza"};
	conexoes["duluth"]["omaha"] = {2,"cinza"};
	conexoes["duluth"]["helena"] = {6,"laranja"};
	conexoes["duluth"]["winnipeg"] = {4,"preto"};
	conexoes["duluth"]["sault st. marie"] = {3,"cinza"};
	conexoes["sault st. marie"]["duluth"] = {3,"cinza"};
	conexoes["sault st. marie"]["winnipeg"] = {6,"cinza"};
}

void aleatorizacao_das_cartas(){
	
	map<char, int> rad;
		rad['c']=7; //coringa ou dorada
		rad['V']=6; //verde
		rad['v']=6; //vermelho
		rad['b']=6; //branco
		rad['p']=6; //preto
		rad['l']=6; //laranja
		rad['A']=6; //azul
		rad['a']=6; //amarelo
		rad['r']=6; //rosa
	for(int i=0; i<55; i++){
		char x = rand()%123+65; //pego na um valor de 65('A') á 122('z') da tabela ascii
		auto it = rad.lower_bound(x); //iterator de map<char, int>
		if(it!=rad.end()){ // vejo se estou no ultimo elemento do map
			it->ss--; //tiro uma carta;
			baralho.push(it->ff); //coloco a carta que tirei na pilha
			if(it->ss==0){ //se o numero de cartas que tenho que tirar não é 0
				rad.erase(it); //apago essa carta do meu map
			}
		}else{ //tem só um único valor no meu map
			it--; //faço o iterator apontar para ele
			it->ss--; //tiro a carta
			baralho.push(it->ff); //coloco a carta que tirei na pilha
			if(it->ss==0){ //se o numero de cartas que tenho q tirar não é 0
				rad.erase(it); //apaga a carta do map
			}
		}
	}
}


int gera(string K) {
	map<string, int> num;
	vector<int> id(N), sz(N, 1);
	iota(id.begin(), id.end(), 0);
	vector<tuple<int, string, string, string>> edge;
	for(auto x : visitado) {
		for(auto [a, b] : visitado[x.first]) {	
			if(b.second != K) continue;
			edge.emplace_back(b.first, x.first, a, b.second);
		}
	}
	function<int(int)> find = [&](int x) {
		return (id[x] == x ? x : find(id[x]));
	};
	auto uni = [&](int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return;
		if(sz[x] > sz[y]) swap(x, y);
		id[x] = y;
		sz[y] += sz[x];
	};
	int cnt = 1;
	sort(edge.begin(), edge.end());
	vector<vector<pair<int, int>>> g(N);
	for(auto [c, a, b, d] : edge) {
		if(!num[a]) {
			num[a] = cnt++;
		}
		if(!num[b]) {
			num[b] = cnt++;
		}
		if(find(num[a]) != find(num[b])) {
			uni(num[a], num[b]);
			g[num[a]].emplace_back(num[b], c);
			g[num[b]].emplace_back(num[a], c);
		}
	}
	auto djk = [&](int u) {
		const int inf = 1e9;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.emplace(0, u);
		vector<int> dist(N + 10, -inf);
		dist[u] = 0;
		while(!pq.empty()) {
			auto [a, b] = pq.top();
			if(dist[b] > a) continue;
			for(auto [k, w] : g[a]) {
				if(dist[k] < w + dist[a]) {
					dist[k] = w + dist[a];
					pq.emplace(w + dist[a], k);
				}
			}
		}
		return *max_element(dist.begin(), dist.end());
	};
	int res = 0;
	for(int i = 1; i < cnt; i++) {
		res = max(res, djk(i));
	}
	return res;
	
}


void dfs(string i){
	
}

void mesa(){
	if(carta_aberta.count('c')>=3){
		for(auto x:carta_aberta) descarte.push(x);
		carta_aberta.clear();
		while(carta_aberta.size()<5){
			carta_aberta.insert(baralho.top());
			baralho.pop();
		}
	}
}

void acabou_baralho(){
	stack<char> aux;
	while(!baralho.empty()){aux.push(baralho.top());baralho.pop();}
	while(!descarte.empty()){baralho.push(descarte.top());descarte.pop();}
	while(!aux.empty()){baralho.push(aux.top());aux.pop();}
}

int main(){
	mapa(); // função para criar o mapa do jogo
	aleatorizacao_das_cartas(); // função para aleatorizar o baralho
	dmao["cinza"]=0;
	dmao["verde"]=1;
	dmao["vermelho"]=2;
	dmao["branco"]=3;
	dmao["preto"]=4;
	dmao["laranja"]=5;
	dmao["azul"]=6;
	dmao["amarelo"]=7;
	dmao["rosa"]=8;
	jogador j1, j2; //criei um objeto na struct jogador
	cout<<"Nome dos dois Jogadores: ";
	cin>>j1.nome>>j2.nome; //nome dos jogadores
	for(int i=0; i<15; i++){ // distribuindo cartas para os dois jogadores e colocando cartas na mesa de compra
		char carta;
		if(i%2==0 && i<10){ //dando cartas pares para o primeiro jogador
			carta = baralho.top();
			baralho.pop();
			if(carta=='c') j1.mao[0]++;
			if(carta=='V') j1.mao[1]++;
			if(carta=='v') j1.mao[2]++;
			if(carta=='B') j1.mao[3]++;
			if(carta=='p') j1.mao[4]++;
			if(carta=='l') j1.mao[5]++;
			if(carta=='A') j1.mao[6]++;
			if(carta=='a') j1.mao[7]++;
			if(carta=='r') j1.mao[8]++;
		}else if(i%2!=0 && i<10){ //dando cartas impares para o segundo jogador
			carta = baralho.top();
			baralho.pop();
			if(carta=='c') j2.mao[0]++;
			if(carta=='V') j2.mao[1]++;
			if(carta=='v') j2.mao[2]++;
			if(carta=='B') j2.mao[3]++;
			if(carta=='p') j2.mao[4]++;
			if(carta=='l') j2.mao[5]++;
			if(carta=='A') j2.mao[6]++;
			if(carta=='a') j2.mao[7]++;
			if(carta=='r') j2.mao[8]++;
		}
		if(i>9){ //colocando 5 cartas na mesa de compra
			carta_aberta.insert(baralho.top());
			baralho.pop();
			mesa();
		}
	}
	
//-------------------jogo começa-------------------
	int tt=1;
	while(tt--){ //o jogo termina quando o numero de vagoes de um jogador for menor ou igual a 5
		if(baralho.size()<=10) acabou_baralho();
		cout<<"cartas na mesa: ";
		for(auto x:carta_aberta)cout<<x<<" ";
		cout<<'\n';
		cout<<j1.nome<<":  Vagoes:"<<j1.vagoes<<"\n";
		cout<<"c V v b p l A a r\n";
		for(auto x:j1.mao)cout<<x<<" ";
		cout<<'\n';
		cout<<j2.nome<<":  Vagoes:"<<j2.vagoes<<"\n";
		cout<<"c V v b p l A a r\n";
		for(auto x:j2.mao)cout<<x<<" ";
		int opcao;
		cout<<"\n-------------------Primeiro jogador-------------------\n";
		cout<<"colocar vagoes ou comprar cartas (1---2): ";cin>>opcao;
		if(opcao==1){
			for(auto i:conexoes){
				for(auto j:i.ss){
					cout<<i.ff<<"---"<<j.ff<<" = custo:"<<j.ss.ff<<" cor:"<<j.ss.ss<<'\n';
				}
			}
			cout<<'\n';
			cout<<j1.nome<<":  Vagoes:"<<j1.vagoes<<"\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j1.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<j2.nome<<":  Vagoes:"<<j2.vagoes<<"\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j2.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<"Escolha onde ira colocar o vagao(os dois logais e a cor do logal): \n";
			string l1, l2, cor;
			cin.ignore();
			getline(cin, l1);
			getline(cin, l2);
			cin>>cor;
			if(cor=="cinza"){
				string usar;
				cout<<"Qual cartas ira usar para colocar no espaco: ";cin>>usar; //lembrando que as conexoes cinzas pode ser usada por qualquer carta, respeitando a regra de que é necessario ter o numero do custo para colocar em tal espaço 
				if(conexoes.count(l1)){
					if(conexoes[l1].count(l2)){
						//essa conexao existe
						if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
							j1.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
							visitado[l1][l2] = {0, j1.nome}; //coloco essa conexao para o jogador 1
							j1.mao[dmao[usar]] -= conexoes[l1][l2].ff;
							if(conexoes[l1][l2].ff==1) j1.pontos+=1;
							if(conexoes[l1][l2].ff==2) j1.pontos+=2;
							if(conexoes[l1][l2].ff==3) j1.pontos+=4;
							if(conexoes[l1][l2].ff==4) j1.pontos+=7;
							if(conexoes[l1][l2].ff==5) j1.pontos+=10;
							if(conexoes[l1][l2].ff==6) j1.pontos+=15;
						}
					}
				}
			}else{
				char usar;
				cout<<"Usar o coringa (y/n): ";cin>>usar;
				if(usar=='y'){
					int num;
					cout<<"Quantos ira usar: ";cin>>num;
					if(conexoes.count(l1)){
						if(conexoes[l1].count(l2)){
							//essa conexao existe
							if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
								j1.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
								visitado[l1][l2] = {1, j1.nome}; //coloco essa conexao para o jogador 1
								j1.mao[0] = num - j1.mao[0];
								num = conexoes[l1][l2].ff - num;
								j1.mao[dmao[cor]] -= num;
								if(conexoes[l1][l2].ff==1) j1.pontos+=1;
								if(conexoes[l1][l2].ff==2) j1.pontos+=2;
								if(conexoes[l1][l2].ff==3) j1.pontos+=4;
								if(conexoes[l1][l2].ff==4) j1.pontos+=7;
								if(conexoes[l1][l2].ff==5) j1.pontos+=10;
								if(conexoes[l1][l2].ff==6) j1.pontos+=15;
							}
						}
					}
				}else{
					if(conexoes.count(l1)){
						if(conexoes[l1].count(l2)){
							//essa conexao existe
							if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
								j1.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
								visitado[l1][l2] = {1, j1.nome}; //coloco essa conexao para o jogador 1
								j1.mao[dmao[conexoes[l1][l2].ss]] -= conexoes[l1][l2].ff;
								if(conexoes[l1][l2].ff==1) j1.pontos+=1;
								if(conexoes[l1][l2].ff==2) j1.pontos+=2;
								if(conexoes[l1][l2].ff==3) j1.pontos+=4;
								if(conexoes[l1][l2].ff==4) j1.pontos+=7;
								if(conexoes[l1][l2].ff==5) j1.pontos+=10;
								if(conexoes[l1][l2].ff==6) j1.pontos+=15;
							}
						}
					}
				}
				cout<<'\n';
				cout<<j1.nome<<":  Vagoes:"<<j1.vagoes<<"\n";
				cout<<"c V v b p l A a r\n";
				for(auto x:j1.mao)cout<<x<<" ";
				cout<<'\n';
				cout<<j2.nome<<":  Vagoes:"<<j2.vagoes<<"\n";
				cout<<"c V v b p l A a r\n";
				for(auto x:j2.mao)cout<<x<<" ";
				cout<<'\n';
			}
			
		}else if(opcao==2){
			int compra;
			char carta;
			cout<<"Comprar do baralho ou ta mesa (1---2): ";cin>>compra;
			if(compra==1){ //comprando carta do baralho
				carta = baralho.top();
				baralho.pop();
				if(carta=='c') j1.mao[0]++;
				if(carta=='V') j1.mao[1]++;
				if(carta=='v') j1.mao[2]++;
				if(carta=='B') j1.mao[3]++;
				if(carta=='p') j1.mao[4]++;
				if(carta=='l') j1.mao[5]++;
				if(carta=='A') j1.mao[6]++;
				if(carta=='a') j1.mao[7]++;
				if(carta=='r') j1.mao[8]++;
			}else{ //comprando carta na mesa
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
				cout<<"Escolha uma carta dentre as que estao na mesa: ";
				cin>>carta;
				if(carta=='c') {j1.mao[0]++;auto it=carta_aberta.find('c'); carta_aberta.erase(it);}
				if(carta=='V') {j1.mao[1]++;auto it=carta_aberta.find('V'); carta_aberta.erase(it);}
				if(carta=='v') {j1.mao[2]++;auto it=carta_aberta.find('v'); carta_aberta.erase(it);}
				if(carta=='b') {j1.mao[3]++;auto it=carta_aberta.find('b'); carta_aberta.erase(it);}
				if(carta=='p') {j1.mao[4]++;auto it=carta_aberta.find('p'); carta_aberta.erase(it);}
				if(carta=='l') {j1.mao[5]++;auto it=carta_aberta.find('l'); carta_aberta.erase(it);}
				if(carta=='A') {j1.mao[6]++;auto it=carta_aberta.find('A'); carta_aberta.erase(it);}
				if(carta=='a') {j1.mao[7]++;auto it=carta_aberta.find('a'); carta_aberta.erase(it);}
				if(carta=='r') {j1.mao[8]++;auto it=carta_aberta.find('r'); carta_aberta.erase(it);}
				carta_aberta.insert(baralho.top());
				baralho.pop();
				mesa();
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
			}
		}
		cout<<"\n-------------------Segundo jogador-------------------\n";
		cout<<"colocar vagoes ou comprar cartas (1---2): ";cin>>opcao;
		if(opcao==1){
			for(auto i:conexoes){
				for(auto j:i.ss){
					cout<<i.ff<<"---"<<j.ff<<" = custo:"<<j.ss.ff<<" cor:"<<j.ss.ss<<'\n';
				}
			}
			cout<<'\n';
			cout<<j1.nome<<":  Vagoes:"<<j1.vagoes<<"\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j1.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<j2.nome<<":  Vagoes:"<<j2.vagoes<<"\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j2.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<"Escolha onde ira colocar o vagao(os dois logais e a cor do logal): \n";
			string l1, l2, cor;cin>>l1>>l2>>cor;
			if(cor=="cinza"){
				string usar;
				cout<<"Qual cartas ira usar para colocar no espaço: ";cin>>usar; //lembrando que as conexoes cinzas pode ser usada por qualquer carta, respeitando a regra de que é necessario ter o numero do custo para colocar em tal espaço 
				if(conexoes.count(l1)){
					if(conexoes[l1].count(l2)){
						//essa conexao existe
						if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
							j2.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
							visitado[l1][l2] = {0, j2.nome}; //coloco essa conexao para o jogador 1
							j2.mao[dmao[usar]] -= conexoes[l1][l2].ff;
							if(conexoes[l1][l2].ff==1) j2.pontos+=1;
							if(conexoes[l1][l2].ff==2) j2.pontos+=2;
							if(conexoes[l1][l2].ff==3) j2.pontos+=4;
							if(conexoes[l1][l2].ff==4) j2.pontos+=7;
							if(conexoes[l1][l2].ff==5) j2.pontos+=10;
							if(conexoes[l1][l2].ff==6) j2.pontos+=15;
						}
					}
				}
			}else{
				char usar;
				cout<<"Usar o coringa (y/n): ";cin>>usar;
				if(usar=='y'){
					int num;
					cout<<"Quantos ira usar: ";cin>>num;
					if(conexoes.count(l1)){
						if(conexoes[l1].count(l2)){
							//essa conexao existe
							if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
								j2.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
								visitado[l1][l2] = {1, j2.nome}; //coloco essa conexao para o jogador 2
								j2.mao[0] = num - j2.mao[0];
								num = conexoes[l1][l2].ff - num;
								j2.mao[dmao[cor]] -= num;
								if(conexoes[l1][l2].ff==1) j2.pontos+=1;
								if(conexoes[l1][l2].ff==2) j2.pontos+=2;
								if(conexoes[l1][l2].ff==3) j2.pontos+=4;
								if(conexoes[l1][l2].ff==4) j2.pontos+=7;
								if(conexoes[l1][l2].ff==5) j2.pontos+=10;
								if(conexoes[l1][l2].ff==6) j2.pontos+=15;
							}
						}
					}
				}else{
					if(conexoes.count(l1)){
						if(conexoes[l1].count(l2)){
							//essa conexao existe
							if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
								j2.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
								visitado[l1][l2] = {1, j2.nome}; //coloco essa conexao para o jogador 2
								j2.mao[dmao[conexoes[l1][l2].ss]] -= conexoes[l1][l2].ff;
								if(conexoes[l1][l2].ff==1) j2.pontos+=1;
								if(conexoes[l1][l2].ff==2) j2.pontos+=2;
								if(conexoes[l1][l2].ff==3) j2.pontos+=4;
								if(conexoes[l1][l2].ff==4) j2.pontos+=7;
								if(conexoes[l1][l2].ff==5) j2.pontos+=10;
								if(conexoes[l1][l2].ff==6) j2.pontos+=15;
							}
						}
					}
				}
				cout<<'\n';
				cout<<j1.nome<<":  Vagoes:"<<j1.vagoes<<"\n";
				cout<<"c V v b p l A a r\n";
				for(auto x:j1.mao)cout<<x<<" ";
				cout<<'\n';
				cout<<j2.nome<<":  Vagoes:"<<j2.vagoes<<"\n";
				cout<<"c V v b p l A a r\n";
				for(auto x:j2.mao)cout<<x<<" ";
				cout<<'\n';
			}
			
		}else if(opcao==2){
			int compra;
			char carta;
			cout<<"Comprar do baralho ou ta mesa (1---2): ";cin>>compra;
			if(compra==1){ //comprando carta do baralho
				carta = baralho.top();
				baralho.pop();
				if(carta=='c') j2.mao[0]++;
				if(carta=='V') j2.mao[1]++;
				if(carta=='v') j2.mao[2]++;
				if(carta=='B') j2.mao[3]++;
				if(carta=='p') j2.mao[4]++;
				if(carta=='l') j2.mao[5]++;
				if(carta=='A') j2.mao[6]++;
				if(carta=='a') j2.mao[7]++;
				if(carta=='r') j2.mao[8]++;
			}else{ //comprando carta da mesa
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
				cout<<"Escolha uma carta dentre as que estao na mesa: ";
				char carta;cin>>carta;
				if(carta=='c') {j2.mao[0]++;auto it=carta_aberta.find('c'); carta_aberta.erase(it);}
				if(carta=='V') {j2.mao[1]++;auto it=carta_aberta.find('V'); carta_aberta.erase(it);}
				if(carta=='v') {j2.mao[2]++;auto it=carta_aberta.find('v'); carta_aberta.erase(it);}
				if(carta=='b') {j2.mao[3]++;auto it=carta_aberta.find('b'); carta_aberta.erase(it);}
				if(carta=='p') {j2.mao[4]++;auto it=carta_aberta.find('p'); carta_aberta.erase(it);}
				if(carta=='l') {j2.mao[5]++;auto it=carta_aberta.find('l'); carta_aberta.erase(it);}
				if(carta=='A') {j2.mao[6]++;auto it=carta_aberta.find('A'); carta_aberta.erase(it);}
				if(carta=='a') {j2.mao[7]++;auto it=carta_aberta.find('a'); carta_aberta.erase(it);}
				if(carta=='r') {j2.mao[8]++;auto it=carta_aberta.find('r'); carta_aberta.erase(it);}
				carta_aberta.insert(baralho.top());
				baralho.pop();
				mesa();
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
			}
		}
	}
	//final do jogo
	int maiorJ1, maiorJ2;
	maiorJ1=gera(j1.nome);
	maiorJ2=gera(j2.nome);
	if(maiorJ1>maiorJ2) j1.pontos+=10;
	else if(maiorJ2>maiorJ1){
		j2.pontos+=10;
	}
	
	if(j1.pontos>j2.pontos)cout<<j1.nome<<" WINS\n";
	else cout<<j2.nome<<" WINS\n";
}
