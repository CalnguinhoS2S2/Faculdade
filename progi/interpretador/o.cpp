#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

stringstream b;
vector<string> buffer;
map<string, int> Label;
vector<pair<string, int>> label;


void cria_label(){
	int pos = 1;
	label.push_back({buffer[0], 0});
	while(buffer[pos]!="halt"){
		if(buffer[pos]==";"){
			pos++;
			if(!Label.count(buffer[pos])){
				Label[buffer[pos]] = pos;
				label.push_back({buffer[pos], pos});
			}
		}
		pos++;
	}
}

void Print(int pos){
	if(buffer[pos][0]=='"'){
		string str = buffer[pos][0]=='"';
		int i;
		for(i=1; buffer[pos][i]!='"'; i++){
			str += buffer[pos][i];
		}
		pos++;
		cout<<str<<endl;
	}else if(buffer[pos]==)
}

int  busca_goto(string tt){
	int l=0, r=(int)label.size()-1, m ;
	while(l<=r){
		m=(l+r)/2;
		if(tt==label[m].ff) return m;
		if(tt<label[m].ff) r=m-1;
		else l=m+1;
	}
	return -1;
}

int Goto(string tt){
	sort(label.ss.begin(), label.ss.end());
	int pos = busca_goto(tt);
	return pos;
}

void interpretador(){
	int pos = 0;
	while(buffer[pos]!="halt"){
		if(buffer[pos]=="rem") for(; buffer[pos]!=";" || buffer[pos]!=":"; pos++);
		if(buffer[pos]==";")pos++;
		if(buffer[pos]=="print") Prtint(pos++);
		if(buffer[pos]=="goto"){
			pos++;
			int pp = Goto(buffer[pos]);
			if(pp!=-1){
				pos = pp;
			}else break;
		}
	}
}

void leitura(string file){
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
	}else cout<<"ERRO --> NAO ABRIU O ARQUIVO"<<endl;
}

signed main(){
	string file = "basic.txt";
	leitura(file);
	interpretador();
}
