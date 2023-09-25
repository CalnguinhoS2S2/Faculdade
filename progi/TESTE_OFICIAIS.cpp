#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
using namespace std;

int main(){
	set<string> st={"abc", "bac", "cba", "acb"};

	int n; cin>>n;
	while(n--){
		string a; cin>>a;
		if(st.count(a)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}