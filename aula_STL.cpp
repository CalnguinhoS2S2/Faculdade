#include<bits/stdc++.h>
using namespace std;

// struct cmp{
//     bool operator()(int a, int b) const {return a>b;}
// };

struct comp{
    int a;
    bool operator < (const comp x) const{return a>x.a;}
};

// bool ord(const comp &x, const comp &y){
//     return x.b < y.b;
// }

int main(){
//----------------set---------------------------------
    priority_queue<comp> v;
    //set<comp> v;
    for(int i=0; i<10; i++) v.push({i});
    //for(auto x:v) cout<<x.a<<" ";
    while(!v.empty()){
        cout<<v.top().a<<" ";
        v.pop();
    }
    cout<<endl;
//---------------map-----------------------------------------
    // map<int, int> mp;
    // int a, b; cin>>a>>b;
    // mp.insert(pair<int, int>(a, b));
    // cin>>a>>b;
    // mp[a]=b;

    // for(map<char,int>::iterator it=mp.begin(); it!=mp.end(); ++it){
    //     cout<<it->first<<" => "<<it->second<<'\n';
    // }

    // // for(auto x:mp){
    // //     cout<<x.first<<" "<<x.second<<endl;
    // // }
//----------------multiset-----------------------------------
    // multiset<pair<int, int>> st;
    
    // st.insert({20,2});
    // st.insert({10,0});
    // st.insert({30,0});
    // st.insert({20,1});

    // for(auto x:st){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
//------------operator<-----------------------------------------
    // set<int> st = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // sort(st.rbegin(), st.begin());

    // for(auto x:st){
    //     cout<<x<<endl;
    // }
//------------lambda--------------------------------------------
    // vector<comp> vt = {{1,3}, {1,2}, {2,1}, {3,4}};
    // sort(vt.begin(), vt.end(), [](const comp &x, const comp &y){
    //     if(x.a == y.a) return x.a > y.a;
    //     return x.b < y.b;
    // });

    // for(auto x:vt){
    //     cout<<x.a<<" "<<x.b<<endl;
    // }

    // auto dfs = [&](auto self, int u, int p = -1) -> int { // can also be auto&& if you want to be careful
    // int sum = 1;
    // for (auto v : g[u])
    //     if (v != p) sum += self(self, v, u);
    // return sum;
    // };
    // int sz = dfs(dfs, 0);
//----------terceiro_par_sort--------------------------------------
    // vector<comp> vt = {{1,3}, {1,2}, {2,1}, {3,4}};
    // sort(vt.begin(), vt.end(), ord);

    // for(auto x:vt){
    //     cout<<x.a<<" "<<x.b<<endl;
    // }
//-------------------------priority_queue-------------------------------------
    // priority_queue<int, vector<int>, greater<int>> pq;
    // priority_queue<int> PQ;
    // for(int i=0; i<10; i++){
    //     pq.push(i);
    //     PQ.push(i);
    // }
    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }
    // cout<<endl;
    // while(!PQ.empty()){
    //     cout<<PQ.top()<<" ";
    //     PQ.pop();
    // }
}