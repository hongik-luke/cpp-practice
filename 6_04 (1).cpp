#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
struct disjoint{
    vector<int> parent,rank,size;
    disjoint(int N) : parent(N+2),rank(N+2,1), size(N+2,1){
        for(int i = 0; i <= N; i++)
            parent[i] = i;
    }
    int find(int idx){
        if(idx == parent[idx]) return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void marge(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        size[v] = size[u]+size[v];
        if(rank[u] == rank[v]) rank[v]++;
    }
    int getsize(int idx){
        return size[find(idx)];
    }
};

int N;
map<string, int> m;
vector<pair<string,string>> v;
void make_map(){
    v.clear();
    m.clear();
    cin>>N;
    string str1,str2;
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        cin>>str1>>str2;
        v.push_back(make_pair(str1,str2));
        if(m.find(str1) == m.end()){
            m.insert(make_pair(str1,cnt++));
        }
        if(m.find(str2) == m.end()){
            m.insert(make_pair(str2,cnt++));
        }
    }
}
void get_result(){
    int len = v.size();
    disjoint a(2*len);
    pair<string,string> s;
    for(int i = 0 ; i < len ; i++){
        s = v[i];
        int n1 = m[s.first]; int n2 = m[s.second];
        a.marge(n1,n2);
        cout<<a.size[a.find(n1)]<<"\n";
    }
}

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int TC;
    cin>>TC;
    for(int i = 0; i < TC ; i++){
        make_map();
        get_result();
        
    }
}
