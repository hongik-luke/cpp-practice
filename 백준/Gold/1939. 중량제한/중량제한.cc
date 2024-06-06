#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct disjoint{
    vector<int> parent,rank;
    disjoint(int N) : parent(N+2),rank(N+2,1){
        for(int i = 0 ; i <= N ; i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }
    void merge(int u ,int v){
        u = find(u) ; v = find(v);
        if(u == v) return;
        
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return;
    }
};
int f,l;
typedef pair<int,pair<int,int>> pos;
vector<pos> v;
int N,M;
void input(){
    cin>>N>>M;
    int n1,n2,n3;
    pos a;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        a = {n3,{n1,n2}};
        v.push_back(a);
    }
    sort(v.begin(),v.begin()+M);
    cin>>f>>l;
}
int get(){
    disjoint a(N);
    for(int i = v.size()-1 ; i >= 0 ; i--){
        a.merge(v[i].second.first, v[i].second.second);
        if(a.find(f) == a.find(l)) return v[i].first;
    }
    return -1;
}
int main(void){
    input();
    cout<<get();
}