
//~ ▀██▀─▄███▄─▀██─██▀██▀▀█
//~ ─██─███─███─██─██─██▄█
//~ ─██─▀██▄██▀─▀█▄█▀─██▀█
//~ ▄██▄▄█▀▀▀─────▀──▄██▄▄█

//~ —–-—▒▒▒▒▒▒▒▒▒▒
//~ —–-▒███████████▒
//~ —▒████▒▒▒▒▒▒▒███▒
//~ -▒████▒▒▒▒▒▒▒▒▒███▒……………….▒▒▒▒▒▒
//~ -▒███▒▒▒▒▒███▒▒▒███▒…………..▒██████▒
//~ -▒███▒▒▒▒██████▒▒███▒……….▒██▒▒▒▒██▒
//~ —▒███▒▒▒███████▒▒██▒…….▒███▒▒█▒▒██▒
//~ —–▒███▒▒████████▒██▒…▒███▒▒███▒▒██▒
//~ ——–▒██▒▒██████████▒▒███▒▒████▒▒██▒
//~ ———▒██▒▒██████████████▒████▒▒██▒
//~ ———-▒██▒▒█████████████████▒▒██▒
//~ ————▒██▒▒██████████████▒▒██▒
//~ ————–▒██▒▒████████████▒▒██▒
//~ —————-▒██▒▒██████████▒▒██▒
//~ —————–▒██▒▒████████▒▒██▒
//~ ——————-▒██▒▒██████▒▒██▒
//~ ———————▒██▒▒████▒▒██▒
//~ ———————-▒██▒▒███▒▒█▒
//~ ————————▒██▒▒█▒▒█▒
//~ ————————-▒██▒▒▒█▒
//~ —————————▒██▒█▒
//~ —————————♥♥♥♥♥♥
//~ —————————-♥♥♥♥♥
//~ ——————————♥♥♥
//~ —————————-—♥♥
//~ ———————————♥


#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

stringstream b;
vector<string> buffer;
map<string, int> Label;
vector<pair<int, string>> label;
vector<string> vt;
vector<int> p;

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
	buffer[0] = "label";
	while(buffer[pos]!="halt"){
		if(buffer[pos]==";"){
			pos++;
			if(!Label.count(buffer[pos])){
				Label[buffer[pos]] = pos;
				label.push_back({pos, buffer[pos]});
				buffer[pos] = "label";
			}
		}
		pos++;
	}
}

string print_var(int pos){ //certo
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
		string str ="";
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
		}else{
			bool ok = 0;
			for(int i=0; i<(int)variavel.size(); i++)if(variavel[i]=='.')ok=true;
			if(ok){
				var[str].type = 1;
				var[str].valor = variavel;
			}else{
				var[str].type = 0;
				var[str].valor = variavel;
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
		if(tt==label[m].ss){
			return label[m].ff;
		}
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

bool IF(int pos){ // certo
	string a="", cond="", b="";
	int i, j, k;
	for(i=0; buffer[pos][i]!='<'&&buffer[pos][i]!='>'&&buffer[pos][i]!='!'&&buffer[pos][i]!='='; i++){
		a+=buffer[pos][i];
	}
	for(j=i; buffer[pos][j]=='<'||buffer[pos][j]=='>'||buffer[pos][j]=='!'||buffer[pos][j]=='='; j++) cond+=buffer[pos][j];
	for(k=j; k<(int)buffer[pos].size(); k++){
		b+=buffer[pos][k];
	}
	if(var.count(a) && var.count(b)){ // comparacao de duas variaveis
		if(cond == ">"){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x>y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x>y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x>y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<"){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x<y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x<y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x<y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == ">="){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x>=y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x>=y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x>=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<="){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x<=y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x<=y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x<=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "!="){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x!=y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x!=y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x!=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "=="){
			int typeA = var[a].type, typeB = var[b].type;
			if(typeA==0 && typeB==0){
				int x = stoi(var[a].valor), y = stoi(var[b].valor);
				if(x==y) return true;
				return false;
			}else if(typeA==1 && typeB==1){
				double x = stod(var[a].valor), y = stod(var[b].valor);
				if(x==y) return true;
				return false;
			}else if(typeA==2 && typeB==2){
				string x = var[a].valor, y = var[b].valor;
				if(x==y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
	}if(var.count(b) && !var.count(a)){ // se b variavel
		if(cond == ">"){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x>y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x>y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x>y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<"){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x<y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x<y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x<y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == ">="){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x>=y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x>=y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x>=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<="){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x<=y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x<=y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x<=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "!="){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x!=y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x!=y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x!=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "=="){
			int typeB = var[b].type;
			if(typeB==0){
				int x = stoi(a), y = stoi(var[b].valor);
				if(x==y) return true;
				return false;
			}else if(typeB==1){
				double x = stod(a), y = stod(var[b].valor);
				if(x==y) return true;
				return false;
			}else if(typeB==2){
				string x = a, y = var[b].valor;
				if(x==y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
	}if(var.count(a) && !var.count(b)){ // se a variavel
		if(cond == ">"){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x>y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x>y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x>y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<"){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x<y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x<y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x<y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == ">="){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x>=y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x>=y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x>=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "<="){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x<=y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x<=y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x<=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "!="){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x!=y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x!=y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x!=y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
		if(cond == "=="){
			int typeA = var[a].type;
			if(typeA==0){
				int x = stoi(var[a].valor), y = stoi(b);
				if(x==y) return true;
				return false;
			}else if(typeA==1){
				double x = stod(var[a].valor), y = stod(b);
				if(x==y) return true;
				return false;
			}else if(typeA==2){
				string x = var[a].valor, y = b;
				if(x==y) return true;
				return false; 
			}else{
				cout<<"Comparacao nao pode ser feita"<<endl;
				exit(0);
			}
		}
	}else{
		cout<<"A variavel "<<a<<" nao existe"<<endl;
		exit(0);
	}
	return false;
}

string operacao(){
	string op;
	if(var.count(vt[p[0]-1])&&!var.count(vt[p[0]+1])){ // A + 10
		if(var[vt[p[0]-1]].type == 0){ // add sub int
			int x = stoi(var[vt[p[0]-1]].valor), y = stoi(vt[p[0]+1]),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]-1]].type == 1){ // add sub float
			double x = stod(var[vt[p[0]-1]].valor), y = stod(vt[p[0]+1]),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]-1]].type == 2){ // add float
			string res;
			if(vt[p[0]]=="+"){
				res = var[vt[p[0]-1]].valor + vt[p[0]+1];
			}else{
				cout<<"Nao pode sub de CHAR";
				exit(0);
			}
			op = res;
			return op;
		}
	}else if(!var.count(vt[p[0]-1])&&var.count(vt[p[0]+1])){ // 10 + A
		if(var[vt[p[0]+1]].type == 0){ // add sub int
			int x = stoi(vt[p[0]-1]), y = stoi(var[vt[p[0]+1]].valor),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]+1]].type == 1){ // add sub float
			double x = stod(vt[p[0]-1]), y = stod(var[vt[p[0]+1]].valor),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]+1]].type == 2){ // add CHAR
			string res;
			if(vt[p[0]]=="+"){
				res = vt[p[0]-1] + var[vt[p[0]+1]].valor;
			}else{
				cout<<"Nao pode sub de CHAR";
				exit(0);
			}
			op = res;
			return op;
		}
	}else if(var.count(vt[p[0]-1])&&var.count(vt[p[0]+1])){ // A + B
		if(var[vt[p[0]+1]].type == 0){ // add sub int
			int x = stoi(var[vt[p[0]-1]].valor), y = stoi(var[vt[p[0]+1]].valor),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]+1]].type == 1){ // add sub float
			double x = stod(var[vt[p[0]-1]].valor), y = stod(var[vt[p[0]+1]].valor),
			res;
			if(vt[p[0]]=="+"){
				res = x + y;
			}else{
				res = x - y;
			}
			op = to_string(res);
			return op;
		}
		if(var[vt[p[0]+1]].type == 2){ // add CHAR
			string res;
			if(vt[p[0]]=="+"){
				res = var[vt[p[0]-1]].valor + var[vt[p[0]+1]].valor;
			}else{
				cout<<"Nao pode sub de CHAR";
				exit(0);
			}
			op = res;
			return op;
		}
	}else{ // 10 + 10
		string x = vt[p[0]-1], y = vt[p[0]+1],
		res;
		if(x.size()==1 && y.size()==1){
			if(vt[p[0]]=="+") res = x + y;
			else{
				cout<<"Nao pode sub de CHAR";
				exit(0);
			}
			op = res;
			return op;
		}else{
			bool ok = false, okk = false;
			for(char i : x) if(i=='.') ok=true;
			for(char i : y) if(i=='.') okk=true;
			if(!ok && !ok){
				int xx = stoi(x), yy = stoi(y),
				res;
				if (vt[p[0]]=="+") res = xx + yy;
				else res = xx - yy;
				cout<<res<<endl;
				op = to_string(res);
				cout<<op<<endl;
				return op;
			}else if(ok && okk){
				double xx = stod(x), yy = stod(y),
				res;
				if(vt[p[0]]=="+") res = xx + yy;
				else res = xx - yy;
				op = to_string(res);
				return op;
			}
		}
	}
	if(p.size()>1){
		for(int i=1; i<(int)p.size(); i++){
			if(var.count(vt[p[i]+1])){ // variavel
				if(var[vt[p[i]+1]].type == 0){
					int x = stoi(op), y = stoi(var[vt[p[i]+1]].valor),
					res;
					if(vt[p[i]]=="+") res = x + y;
					else res = x - y;
					op = to_string(res);
					return op;
				}else if(var[vt[p[i]+1]].type == 1){
					double x = stod(op), y = stod(var[vt[p[i]+1]].valor),
					res;
					if(vt[p[i]]=="+") res = x + y;
					else res = x - y;
					op = to_string(res);
					return op;
				}else if(var[vt[p[i]+1]].type == 2){
					string x = op, y = vt[p[i]+1],
					res;
					if(vt[p[i]]=="+") res = x + y;
					else{
						cout<<"Nao pode sub de CHAR";
						exit(0);
					}
					op = res;
					return op;
				}
			}else{ // nao variavel
				string aux = vt[p[i]+1];
				if(aux.size()==1){
					string x = op, y = vt[p[i]+1],
					res;
					res = x + y;
					op = res;
					return op;
				}else{
					bool ok = false;
					for(char k:aux)if(k=='.') ok=true;
					if(!ok){
						int x = stoi(op), y = stoi(vt[p[i]+1]),
						res;
						res = x + y;
						op = to_string(res);
						return op;
					}else{
						double x = stod(op), y = stod(vt[p[i]+1]),
						res;
						res = x + y;
						op = to_string(res);
						return op;
					}
				}
			}
		}
	}
	return op;
}

void expressao(int pos, string str, int i){
	// estou olhando a expressao
	int x=i;
	string aux = "";
	bool ok = false;
	for(; x<(int)buffer[pos].size(); x++){
		aux += buffer[pos][x];
		if(buffer[pos][x]=='+'||buffer[pos][x]=='-')ok = true;
	}
	if(!ok){ // se nao for uma expressao de soma ou subtracao
		if(!var.count(str)){ // se variavel nao existe
			if(var.count(aux)){ // A = N
				var[str].type = var[aux].type;
				var[str].valor = var[aux].valor;
			}else{ //A = (qualquer atribuicao)
				if((int)aux.size()==0 && ((aux[0] >= 'A' && aux[0] >= 'Z') || (aux[0] >= 'a' && aux[0] >= 'z'))){
					var[str].type = 2;
					var[str].valor = aux; 
				}else{
					bool okk=0;
					for(int k=0; k<(int)aux.size(); k++) if(aux[k]=='.') okk = true;
					if(!okk){
						var[str].type = 0;
						var[str].valor = aux;
					}else{
						var[str].type = 1;
						var[str].valor = aux;
					}
				}
			}
		}else{ // se variavel existe
			if(var.count(aux)){
				var[str].valor = var[aux].valor;
			}else{
				if((int)aux.size()==0 && ((aux[0] >= 'A' && aux[0] >= 'Z') || (aux[0] >= 'a' && aux[0] >= 'z'))){
					var[str].valor = aux; 
				}else{
					bool okk=0;
					for(int k=0; k<(int)aux.size(); k++) if(aux[k]=='.') okk = true;
					if(!okk){
						var[str].valor = aux;
					}else{
						var[str].valor = aux;
					}
				}
			}
		}
	}else{ // se for uma expressao de soma ou subtracao
		int j = 0;
		string ajd = "", a="";
		for(; j<(int)aux.size(); j++){
			if(aux[j]=='+'||aux[j]=='-'){
				a+=aux[j];
				p.push_back(j-1);
				vt.push_back(ajd);
				vt.push_back(a);
				ajd="", a="";
			}else{
				ajd +=aux[j];
			}
		}
		vt.push_back(ajd);
		string op = operacao();
		var[str].valor = op;
	}
}


void interpretador(){
	int pos = 0;
	while(buffer[pos]!="halt"){
		if(buffer[pos]==";"||buffer[pos]==":"||buffer[pos]=="label") pos++;
		if(buffer[pos]=="rem") while(buffer[pos]!=";"&&buffer[pos]!=":") pos++;
		if(buffer[pos]=="print"){ // imprimir
			pos++;
			Print(pos);
			pos++;
		}
		if(buffer[pos]=="input"){ // ler
			pos++;
			bool ok = Input(pos);
			if(!ok){
				cout<<"ERRO->variavel ja existe"<<endl;
				exit (0);
			}
			pos++;
		}
		if(buffer[pos]=="goto"){ // jumper
			pos++;
			int pp = Goto(buffer[pos]);
			if(pp!=-1){
				pos = pp;
				cout<<pos<<"--->"<<buffer[pos]<<endl;
			}else{
				cout<<"Impossivel acessar a linha "<<pos<<endl;
				exit(0);
			}
			pos++;
		}
		if(buffer[pos]=="if"){
			pos++;
			if(IF(pos)){
				pos++;
				if(buffer[pos]=="goto"){
					pos++;
					int pp = Goto(buffer[pos]);
					if(pp!=-1){
						pos = pp;
					}else{
						cout<<"Impossivel acessar a linha "<<pos<<endl;
						exit(0);
					}
				}else if(buffer[pos]=="print"){
					Print(pos++);
				}else{
					string aux="";
					int i;
					for(i=0; buffer[pos][i]!='='; i++){
						aux += buffer[pos][i];
					}
					expressao(pos, aux, i);
					pos++;
				}
			}else{
				while(buffer[pos]!=";") pos++;
				pos++;
			}
		}
		// varivel criada ou variavel criada inicializada e calculo de expressao
		if(buffer[pos]!="goto"&&buffer[pos]!="if"&&buffer[pos]!="input"&&buffer[pos]!="rem"&&buffer[pos]!="label"&&buffer[pos]!="print"&&buffer[pos]!=";"&&buffer[pos]!=":"&&buffer[pos]!="halt"&&buffer[pos][0]!='"'){
			string aux = "";
			bool ok = false;
			int j;
			for(int i=0; buffer[pos][i]!='='; i++) aux += buffer[pos][i];
			for(j=0; j<(int)buffer[pos].size()&&!ok; j++) if(buffer[pos][j]=='=') ok = true;
			if(ok){
				expressao(pos, aux, j);
				while(buffer[pos]!=";")pos++;
			}else{
				cout<<"ERRO --> expressao nao existe"<<endl;
				exit(0);
			}
		}
		pos++;
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
	cria_label();
	interpretador();
}
