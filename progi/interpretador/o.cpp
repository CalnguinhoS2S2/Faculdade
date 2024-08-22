#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
const int MAXN=1e9;
map<string, int> mp;
vector<vector<string>> vt;


enum token_tipo(){
	token_add, // soma
	token_sub, // subtracao
	token_mul, // multiplicacao
	token_div, // divisao
	token_EOF, // fim de arquivo
	token_if, // se
	token_var, // numero
	token_name, //  nome var
	token_goto, // goto
	token_string, // texto entre aspas
	token_print, // imprima
	token_input, // leia
	token_rec, // '='
	token_rem, // comentario em basic
	token_halt // comando halt
	token_con // comando :
}

struct Token{
	token_tipo tipo;
	string nometipo;
}

class Criacao_tokens{
public:
	string str;
    size_t i;
	Criacao_tokens(string &str):str(str), i(0) {}
	Token nexttoken(){
		while(i<str.size()&&str[i]==' ')i++;
		if(i>str.size()) return {token_EOF, ""};
		if(str.compare(i, 5, "print")==0){
			i+=5;
			return {token_print, "print"};
		}
		if(str.compare(i, 5, "input")){
			i+=5;
			return {token_input, "input"};
		}
		if(str[i]=='+'){
			i++;
			return {token_add, "+"};
		}
		if(str[i]=='-'){
			i++;
			return {token_sub, "-"};
		}
		if(str[i]=='*'){
			i++;
			return {token_mul, "*"};
		}
		if(str[i]=='/'){
			i++;
			return {token_div, "/"};
		}
		if(str[i]=='='){
			i++;
			return {token_rec, "="};
		}
		if(str.compare(i, 4, "goto")==0){
			i+=4;
			return {token_goto, "goto"};
		}
		if(str.compare(i, 2, "if")==0){
			i+=2;
			return {token_if, "if"};
		}
		if(isdigit(str[i])){
			string aux;
			while(i<str.size()&&isdigit(str[i])) aux+=str[i++];
			return {token_var, aux};
		}
		if(isalpha(str[i])){
			string aux;
			while(i<str.size()&&isalpha(str[i])) aux+=str[i++];
			return {token_name, aux};
		}
		if(str[i]=='"'){
			string aux;
			while(i<str.size()&&str[i]!='"') aux+=str[i++];
			return {token_string, aux};
		}
		if(str.compare(i, 3, "rem")){
			i+=3;
			return {token_rem, "rem"};
		}
		if(str[i]==':'){
			i++;
			return {token_con, ":"};
		}
	}
}

class interpretador{
public:
	void interpret(vector<vector<string>> &rts){
		for(int i=0; i<vt.size(); i++){
			for(int j=0; j<vt[i].size()){
				if(vt[i][j]=="rem"){
					for(int k=j+1; k<vt[i].size(); k++){
						if(vt[i][k]==":"){
							
						}
					}
				}
			}
		}
	}
}

void leitura(){
	ifstream a(file);
	if(!a.is_open()) cout<<"ERRO --> NAO ABRIU O ARQUIVO"<<endl;
	stringstream b << a.rdbuf();
	int tam=b.size();
	vt=vector<vector<int>> (tam);
	string aux;
	int i=0, j=0;
	while(b>>aux){
		if(aux!=" "){
			if(aux=="\n")i++; j=0;
			else{
				vt[i][j]=aux;
				j++;
			}
		}
	}
}

signed main(){
	string file = "basic.txt";
	leitura();
	interpretador inte;
	for(int i=0; i<vt.size(); i++){
		for(int j=0; j<vt[i].size(); j++){
			inte.interpret(vt[i][j]);
		}
	}
}
