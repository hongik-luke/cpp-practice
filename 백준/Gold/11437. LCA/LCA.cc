#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M;
pair<int,int> check[10010];
vector<int> adj[50010];
int parent[50010];
int height[50010];
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 1 ; i < N ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    cin>>M;
    for(int i = 0 ; i < M ; i++){
        cin>>check[i].first>>check[i].second;
    }
}
void get_parent_high(int idx, int high){
    for(int i = 0 ; i < adj[idx].size() ; i++){
        if(adj[idx][i] == parent[idx]) continue;
        parent[adj[idx][i]] = idx;
        height[adj[idx][i]] = high+1;
        get_parent_high(adj[idx][i], high+1);
    }
}
void print_check(){
    for(int i = 0 ; i < M ; i++){
        int a = check[i].first;
        int b = check[i].second;
        while(1){
            if(a == b){
                cout<<a<<"\n";
                break;
            }
            if(height[a] >= height[b]) a = parent[a];
            else b = parent[b];
        }
    }
}
int main(void){
    input();
    parent[1] = 1; height[1] = 1;
    get_parent_high(1,1);
    print_check();
}