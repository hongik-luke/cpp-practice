#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M;
struct disjoint{
    vector<int> parent,rank;
    disjoint(int N) : parent(N+1),rank(N+1,1){
        for(int i = 0; i < N ; i++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(parent[u] == u) return u;
        else return parent[u] = find(parent[u]);
    }
    bool merge(int u,int v){
        u = find(u), v = find(v);
        if(u == v) return false;
        
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
        return true;
    }
};

int main(void){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1,n2;
    cin>>N>>M;
    disjoint NL(N);
    int result = 0;
    for(int i = 0 ;i < M ; i++){
        cin>>n1>>n2;
        if(!NL.merge(n1,n2)) result++;
    }
    vector<int> v;
    for(int i = 1 ; i <= N ; i++)
        v.push_back(NL.find(i));
    sort(v.begin(),v.end());
    int len = v.size();
    for(int i = 0 ; i < len -1; i++)
        if(v[i] != v[i+1]) result++;
    cout<<result;
    
}