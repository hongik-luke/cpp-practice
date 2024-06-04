#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct disjoint{
    vector<int> parent,rank;
    disjoint(int N) : parent(N+3),rank(N+3,1){
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
        if(rank[u] == rank[v]) rank[v]++;
    }
};

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    disjoint a(N);
    int n1,n2,n3;
    for(int i = 0; i < M ; i++){
        cin>>n1>>n2>>n3;
        if(n1 == 0){
            a.marge(n2,n3);
        }
        if(n1 == 1){
            if(a.find(n2) == a.find(n3)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
}