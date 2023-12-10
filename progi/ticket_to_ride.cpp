#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define ff first
#define ss second

using namespace std;

//-----------------variaveis globais-----------------
map<string, map<string, pair<int, string>>> conexoes;
map<string, map<string, pair<bool, string>>> visitado;
set<string> ord;
vector<string> city;
list<char> carta_aberta;
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
		jogador(){
			mao.assign(9,0);
		}
		//c V v b p l A a r
		//0 1 2 3 4 5 6 7 8
};

void vis(){
	visitado["vancouver"]["calgary"] = {3,"cinza"};
	visitado["vancouver"]["seattle"] = {1,"cinza"};
	visitado["seattle"]["vancouver"] = {1,"cinza"};
	visitado["seattle"]["helena"] = {6,"amarelo"};
	visitado["seattle"]["calgary"] = {4,"cinza"};
	visitado["seattle"]["portland"] = {1,"cinza"};
	visitado["calgary"]["vancouver"] = {3,"cinza"};
	visitado["calgary"]["seattle"] = {4,"cinza"};
	visitado["calgary"]["winnipeg"] = {6,"branco"};
	visitado["calgary"]["helena"] = {4,"cinza"};
	visitado["portland"]["salt lake city"] = {6,"azul"};
	visitado["portland"]["san francisco"] = {5,"rosa"};
	visitado["portland"]["san francisco"] = {5,"verde"};
	visitado["portland"]["seattle"] = {6,"azul"};
	visitado["helena"]["seattle"] = {6,"amarelo"};
	visitado["helena"]["winnipeg"] = {4,"azul"};
	visitado["helena"]["calgary"] = {4,"cinza"};
	visitado["helena"]["salt lake city"] = {3,"rosa"};
	visitado["helena"]["denver"] = {4,"verde"};
	visitado["helena"]["omaha"] = {5,"vermelho"};
	visitado["helena"]["duluth"] = {6,"laranja"};
	visitado["winnipeg"]["calgary"] = {6,"branco"};
	visitado["winnipeg"]["helena"] = {4,"azul"};
	visitado["winnipeg"]["duluth"] = {4,"preto"};
	visitado["winnipeg"]["sault st. marie"] = {6,"cinza"};
	visitado["san francisco"]["portland"] = {5, "rosa"};
	visitado["san francisco"]["portland"] = {5, "verde"};
	visitado["san francisco"]["salt lake city"] = {5,"laranja"};
	visitado["san francisco"]["salt lake city"] = {5,"branco"};
	visitado["san francisco"]["los angeles"] = {3,"rosa"};
	visitado["san francisco"]["los angeles"] = {3,"amarelo"};
	visitado["los angeles"]["san francisco"] = {3,"rosa"};
	visitado["los angeles"]["san francisco"] = {3,"amarelo"};
	visitado["salt lake city"]["san francisco"] = {5,"laranja"};
	visitado["salt lake city"]["san francisco"] = {5,"branco"};
	visitado["salt lake city"]["portland"] = {6,"azul"};
	visitado["salt lake city"]["helena"] = {3,"rosa"};
	visitado["salt lake city"]["denver"] = {3,"vermelho"};
	visitado["salt lake city"]["denver"] = {3,"amarelo"};
	visitado["denver"]["salt lake city"] = {3,"vermelho"};
	visitado["denver"]["salt lake city"] = {3,"amarelo"};
	visitado["denver"]["helena"] = {4,"verde"};
	visitado["denver"]["omaha"] = {4,"rosa"};
	visitado["omaha"]["denver"] = {4,"rosa"};
	visitado["omaha"]["helena"] = {5,"vermelho"};
	visitado["omaha"]["duluth"] = {2,"cinza"};
	visitado["duluth"]["omaha"] = {2,"cinza"};
	visitado["duluth"]["helena"] = {6,"laranja"};
	visitado["duluth"]["winnipeg"] = {4,"preto"};
	visitado["duluth"]["sault st. marie"] = {3,"cinza"};
	visitado["sault st. marie"]["duluth"] = {3,"cinza"};
	visitado["sault st. marie"]["winnipeg"] = {6,"cinza"};
	
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
		if(it!=rad.end()){
			it->ss--;
			baralho.push(it->ff);
			if(it->ss==0){
				rad.erase(it);
			}else{
				it--;
				it->ss--;
				baralho.push(it->ff);
				if(it->ss==0){
					rad.erase(it);
				}
			}
		}
	}
}

void dfs(string i){
	//vis[conexoes[i]]=1;
}

int main(){
	mapa();
	aleatorizacao_das_cartas();
	jogador j1, j2;
	cin>>j1.nome>>j2.nome;
	for(int i=0; i<15; i++){
		char carta;
		if(i%2==0 && i<10){
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
		}else if(i%2!=0 && i<10){
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
		if(i>9){
			carta_aberta.push_back(baralho.top());
			baralho.pop();
		}
	}
	
//-------------------jogo começa-------------------
	while(j1.vagoes!=5){
		cout<<"cartas na mesa: ";
		for(auto x:carta_aberta)cout<<x<<" ";
		cout<<'\n';
		cout<<j1.nome<<":\n";
		cout<<"c V v b p l A a r\n";
		for(auto x:j1.mao)cout<<x<<" ";
		cout<<'\n';
		cout<<j2.nome<<";\n";
		cout<<"c V v b p l A a r\n";
		for(auto x:j2.mao)cout<<x<<" ";
		int opcao;
		cout<<"\n-------------------Primeiro jogador-------------------\n";
		cout<<"colocar vagoes ou comprar cartas (1---2): ";cin>>opcao;
		if(opcao==1){
			auto it = conexoes;
			for(auto it){
				cout<<it.ff<<"---"it.ss<<" = custo:"<<it.ss.ff<<" cor:"<<it.ss.ss;<<'\n';
			}
			cout<<'\n';
			cout<<"Escolha onde ira colocar o vagao(os dois logais e a cor do logal): \n";
			string l1, l2, cor;cin>>l1>>l2>>cor;
			if(conexoes.count({l1,l2}))
			
		}else if(opcao==2){
			int compra;
			char carta;
			cout<<"Comprar do baralho ou ta mesa (1---2): ";cin>>compra;
			if(compra==1){
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
			}else{
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
				cout<<"Escolha uma carta dentre as que estao na mesa: ";
				char carta;cin>>carta;
				if(carta=='c') j1.mao[0]++;
				if(carta=='V') j1.mao[1]++;
				if(carta=='v') j1.mao[2]++;
				if(carta=='B') j1.mao[3]++;
				if(carta=='p') j1.mao[4]++;
				if(carta=='l') j1.mao[5]++;
				if(carta=='A') j1.mao[6]++;
				if(carta=='a') j1.mao[7]++;
				if(carta=='r') j1.mao[8]++;
				carta_aberta.erase(carta);
				carta_aberta.push_back(baralho.top());
				baralho.pop();
			}
		}
		
		cout<<"\n-------------------Segundo jogador-------------------\n";
		cout<<"colocar vagoes ou comprar cartas (1---2): ";cin>>opcao;
		if(opcao==1){
			
		}else if(opcao==2){
			int compra;
			char carta;
			cout<<"Comprar do baralho ou ta mesa (1---2): ";cin>>compra;
			if(compra==1){
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
			}else{
				cout<<"cartas na mesa: ";
				for(auto x:carta_aberta)cout<<x<<" ";
				cout<<'\n';
				cout<<"Escolha uma carta dentre as que estao na mesa: ";
				char carta;cin>>carta;
				if(carta=='c') j2.mao[0]++;
				if(carta=='V') j2.mao[1]++;
				if(carta=='v') j2.mao[2]++;
				if(carta=='B') j2.mao[3]++;
				if(carta=='p') j2.mao[4]++;
				if(carta=='l') j2.mao[5]++;
				if(carta=='A') j2.mao[6]++;
				if(carta=='a') j2.mao[7]++;
				if(carta=='r') j2.mao[8]++;
				carta_aberta.erase(carta);
				carta_aberta.push_back(baralho.top());
				baralho.pop();
			}
		}
	}
}
