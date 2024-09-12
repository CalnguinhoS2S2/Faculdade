#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

stringstream b;
vector<string> buffer;
map<string, int> Label;
vector<pair<int, string>> label;

struct tipo{
	int type; //0, 1, 2 --> int, float, char
	string valor; // valor a ser armazenado
	tipo(){type = 0, valor = "";}
	tipo(int a, string x){type = a, valor = x;}
};
map<string, tipo> var;

void cria_label(){ //certo
	int pos = 1;
	label.push_back({0, buffer[0]});
	while(buffer[pos]!="halt"){
		if(buffer[pos]==";"){
			pos++;
			if(!Label.count(buffer[pos])){
				Label[buffer[pos]] = pos;
				label.push_back({pos, buffer[pos]});
			}
		}
		pos++;
	}
}

string print_var(int pos){ //dar uma olhada
	string aux = "";
	for(int i=0; i<(int)buffer[pos].size(); i++) aux += buffer[pos][i];
	if(!var.count(aux)){
		cout<<"ERRO -> variavel nao existe"<<endl;
		exit (0);
	}
	return var[aux].valor;
}

void Print(int pos){ //certo
	if(buffer[pos][0]=='"'){
		char str = buffer[pos][0]=='"';
		int i;
		for(i=1; buffer[pos][i]!='"'; i++){
			str += buffer[pos][i];
		}
		pos++;
		cout<<str<<endl;
	}else{
		string var = print_var(pos);
		cout<<var<<endl;
	}
}

void input_var(string str){ //certo
	if(!var.count(str)){
		string variavel; cin>>variavel;
		if(variavel.size()==1 && ((variavel[0] >= 'A' && variavel[0] >= 'Z') || (variavel[0] >= 'a' && variavel[0] >= 'z'))){
			var[str].type = 2;
			var[str].valor = variavel;
		}
		else{
			bool ok = 0;
			for(int i=0; i<(int)variavel.size(); i++)if(variavel[i]=='.')ok=true;
			if(ok){
				double aux = stod(variavel);
				var[str].type = 1;
				var[str].valor = aux;
			}else{
				int aux = stoi(variavel);
				var[str].valor = aux;
			}
		}
	} return ;
}

bool Input(int pos){ //certo
	string aux = "";
	for(int i=0; i<(int)buffer[pos].size(); i++) aux += buffer[pos][i];
	if(!var.count(aux)){
		input_var(aux);
		return true;
	}
	return false;
}

int  busca_goto(string tt){ //certo
	int l=0, r=(int)label.size()-1, m ;
	while(l<=r){
		m=(l+r)/2;
		if(tt==label[m].ss) return m;
		if(tt<label[m].ss) r=m-1;
		else l=m+1;
	}
	return -1;
}

int Goto(string tt){ //certo
	sort(label.begin(), label.end());
	int pos = busca_goto(tt);
	return pos;
}

bool IF(int pos){
	string a="", cond="", b="";
	bool ok=false, okk=false;
	int i, j, k;
	for(i=0; buffer[pos][i]!='<'||buffer[pos][i]!='>'||buffer[pos][i]!='!'||buffer[pos][i]!='='; i++){
		a+=buffer[pos][i];
		if(buffer[pos][i]=='.') ok=true;
	}
	for(j=i; buffer[pos][j]=='<'||buffer[pos][j]=='>'||buffer[pos][j]=='!'||buffer[pos][j]=='='; j++) cond+=buffer[pos][j];
	for(k=i; buffer[pos][k]=='<'||buffer[pos][k]=='>'||buffer[pos][k]=='!'||buffer[pos][k]=='='; j++){
		b+=buffer[pos][k];
		if(buffer[pos][k]=='.') okk=true;
	}
	if(var.count(a) && var.count(b)){
		if(cond == ">"){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a>b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a>b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a>b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<"){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a<b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a<b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a<b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == ">="){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a>=b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a>=b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a>=b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<="){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a<=b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a<=b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a<=b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "!="){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a!=b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a!=b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a!=b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "=="){
			int typeA = var[a].type, typeB = var[a].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(a==b) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(a==b) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				char x = var[a].valor, y = var[b].valor;
				if(a==b) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
	}else{
		cout<<"Uma das variaveis nao existe"<<endl;
		exit(0);
	}
}

void interpretador(){
	int pos = 0;
	while(buffer[pos]!="halt"){
		if(!Label.count(buffer[pos])){
			cout<<"linha nao existe"<<endl;
			exit(0);
		}else pos++;
		if(buffer[pos]=="rem") for(; buffer[pos]!=";" || buffer[pos]!=":"; pos++); // comentario
		if(buffer[pos]==";" || buffer[pos]==":")pos++; // parada de linha ; ou outro comando em seguida :
		if(buffer[pos]=="print") Print(pos++); // imprimir
		if(buffer[pos]=="input"){ // ler
			bool ok = Input(pos++);
			if(!ok){
				cout<<"ERRO->variavel ja existe"<<endl;
				exit (0);
			}
		}
		if(buffer[pos]=="goto"){ // jumper
			pos++;
			int pp = Goto(buffer[pos]);
			if(pp!=-1){
				pos = pp;
			}else exit (0);
		}
		if(buffer[pos]=="if"){
			pos++;
			i(IF(pos)){
				pos++;
			}
		}
		string aux = "";
		bool ok = false;
		int i;
		for(i=0; i<(int)buffer[pos].size() && !ok; i++){
			aux +=buffer[pos][i];
			if(buffer[pos][i]!='=') ok=true;
		}
		if(!var.count(aux)){ // varivel criada ou variavel criada inicializada
			if(!ok){
				var[aux] = tipo(0, "");
			}else{
				string uax = "";
				bool okk = false;
				for(int j=i+1; j<(int)buffer[pos].size(); i++){
					uax += buffer[pos][j];
					if(buffer[pos][j]=='.') okk = true;
				}
				if(uax.size()==1 && ((uax[0] >= 'A' && uax[0] >= 'Z') || (uax[0] >= 'a' && uax[0] >= 'z'))){
					var[aux].type = 2;
					var[aux].valor = uax;
				}else if(!okk){
					var[aux].type = 0;
					var[aux].valor = uax;
				}else{
					var[aux].type = 1;
					var[aux].valor = uax;
				}
			}
			pos++
		}else{
			
		}
	}
}

void leitura(string file){ //certo
	ifstream a(file);
	if(a.is_open()){
		string linha;
		while(getline(a, linha)){
			string s, tot;
			bool ok = 0;
			stringstream aux(linha);
			while(aux){
				aux >> s;
				if(s[0] == '"' or ok){
					if(!tot.empty()){
						tot += " ";
					}
					tot += s;
					ok = 1;
				} else{
					buffer.push_back(s);
				}
				if(s.back() == '"'){
					ok = 0;
					if(!tot.empty())
						buffer.push_back(tot);
					tot.clear();
				}
			}
			buffer.pop_back();
			buffer.push_back(";");
		}
		a.close();
	}else{
		cout<<"ERRO --> NAO ABRIU O ARQUIVO"<<endl;
		exit (0);
	}
}

signed main(){
	string file = "basic.txt";
	leitura(file);
	interpretador();
}
