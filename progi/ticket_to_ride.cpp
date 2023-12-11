#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define ff first
#define ss second

using namespace std;

//-----------------variaveis globais-----------------
map<string, map<string, pair<int, string>>> conexoes;
map<string, map<string, pair<bool, string>>> visitado;
map<string, int> dmao;
set<string> ord;
vector<string> city;
set<char> carta_aberta;
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

void dfs(string i){
	//vis[conexoes[i]]=1;
}

//~ void mesa(){
	//~ int cont=0;
	//~ for(auto x:carta_aberta){
		//~ if(x=='c') cont++;
	//~ }
	//~ if(cont>=3){
		//~ for(auto x:carta_aberta) descarte.push(x);
		//~ for(auto x:carta_aberta) cout<<"\n---"<<x<<"---\n";
		//~ carta_aberta.clear();
		//~ cout<<"\n"<<(int)carta_aberta.size()<<"\n";
		//~ while(carta_aberta.size()<6){
			//~ carta_aberta.insert(baralho.top());
			//~ baralho.pop();
		//~ }
	//~ }
//~ }

//~ void acabou_baralho(){
	//~ stack<char> aux;
	//~ while(!baralho.empty()){aux.push(baralho.top());baralho.pop();}
	//~ while(!descarte.empty()){baralho.push(descarte.top());descarte.pop();}
	//~ while(!aux.empty()){baralho.push(aux.top());aux.pop();}
//~ }
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
			//~ mesa();
		}
	}
	
//-------------------jogo começa-------------------
	while(j1.vagoes>5 || j2.vagoes>5){ //o jogo termina quando o numero de vagoes de um jogador for menor ou igual a 5
		//~ if(baralho.size()<=10) acabou_baralho();
		cout<<"cartas na mesa: ";
		for(auto x:carta_aberta)cout<<x<<" ";
		cout<<'\n';
		cout<<j1.nome<<":\n";
		cout<<"c V v b p l A a r\n";
		for(auto x:j1.mao)cout<<x<<" ";
		cout<<'\n';
		cout<<j2.nome<<"\n";
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
			cout<<j1.nome<<":\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j1.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<j2.nome<<";\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j2.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<"Escolha onde ira colocar o vagao(os dois logais e a cor do logal): \n";
			string l1, l2, cor;cin>>l1>>l2>>cor;
			if(cor=="cinza"){
				string usar;
				cout<<"Qual cartas ira usar para colocar no espaco: ";cin>>usar; //lembrando que as conexoes cinzas pode ser usada por qualquer carta, respeitando a regra de que é necessario ter o numero do custo para colocar em tal espaço 
				if(conexoes.count(l1)){
					if(conexoes[l1].count(l2)){
						//essa conexao existe
						if(!visitado[l1][l2].ff){ //vejo se essa conexao ja não foi usada
							j1.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
							visitado[l1][l2] = {1, j1.nome}; //coloco essa conexao para o jogador 1
							j1.mao[dmao[usar]] -= conexoes[l1][l2].ff;
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
							}
						}
					}
				}
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
				if(carta=='c') {j1.mao[0]++;carta_aberta.erase('c');}
				if(carta=='V') {j1.mao[1]++;carta_aberta.erase('V');}
				if(carta=='v') {j1.mao[2]++;carta_aberta.erase('v');}
				if(carta=='b') {j1.mao[3]++;carta_aberta.erase('b');}
				if(carta=='p') {j1.mao[4]++;carta_aberta.erase('p');}
				if(carta=='l') {j1.mao[5]++;carta_aberta.erase('l');}
				if(carta=='A') {j1.mao[6]++;carta_aberta.erase('A');}
				if(carta=='a') {j1.mao[7]++;carta_aberta.erase('a');}
				if(carta=='r') {j1.mao[8]++;carta_aberta.erase('r');}
				carta_aberta.insert(baralho.top());
				baralho.pop();
				//~ mesa();
				cout<<"\ncartas na mesa: ";
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
			cout<<j1.nome<<":\n";
			cout<<"c V v b p l A a r\n";
			for(auto x:j1.mao)cout<<x<<" ";
			cout<<'\n';
			cout<<j2.nome<<";\n";
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
							j1.vagoes -= conexoes[l1][l2].ff; //tiro do jogador o custo para colocar os vagoes numa ferrovia
							visitado[l1][l2] = {1, j2.nome}; //coloco essa conexao para o jogador 1
							j2.mao[dmao[usar]] -= conexoes[l1][l2].ff;
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
							}
						}
					}
				}
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
				if(carta=='c') {j2.mao[0]++;carta_aberta.erase('c');}
				if(carta=='V') {j2.mao[1]++;carta_aberta.erase('V');}
				if(carta=='v') {j2.mao[2]++;carta_aberta.erase('v');}
				if(carta=='b') {j2.mao[3]++;carta_aberta.erase('b');}
				if(carta=='p') {j2.mao[4]++;carta_aberta.erase('p');}
				if(carta=='l') {j2.mao[5]++;carta_aberta.erase('l');}
				if(carta=='A') {j2.mao[6]++;carta_aberta.erase('A');}
				if(carta=='a') {j2.mao[7]++;carta_aberta.erase('a');}
				if(carta=='r') {j2.mao[8]++;carta_aberta.erase('r');}
				carta_aberta.insert(baralho.top());
				baralho.pop();
				//~ mesa();
				cout<<"\ncartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
			}
		}
	}
}
