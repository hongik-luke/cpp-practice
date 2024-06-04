#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct disjoint{
    vector <int> parent,rank;
    disjoint(int N) : parent(N),rank(N,1){
        for(int i = 0 ; i < N ; i++){
            parent[i] = i;
        }
    }
    
    int find(int idx){
        if(idx == parent[idx]) return idx;
        return parent[idx] = find(parent[idx]);
    }
    bool marge(int u ,int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return true;
    }
};

int main(void){
    int N,M;
    cin>>N>>M;
    disjoint a(N);
    int n1,n2;
    for(int i = 1 ; i <= M ;i++){
        cin>>n1>>n2;
        if(!a.marge(n1,n2)){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}