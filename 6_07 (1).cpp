#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M;
pair<int,int> check[100010];
vector<int> adj[100010];
int parent[100010][23];
int height[100010];
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
        if(adj[idx][i] == parent[idx][0]) continue;
        parent[adj[idx][i]][0] = idx;
        height[adj[idx][i]] = high+1;
        get_parent_high(adj[idx][i], high+1);
    }
}
void get_p(){
    for(int k = 1 ; k <= 22 ; k++){
        for(int i = 1 ; i <= N ; i++){
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }
}
void print_check(){
    for(int i = 0 ; i < M ; i++){
        int n1 = check[i].first; 
        int n2 = check[i].second;
        if(height[n1] < height[n2]) swap(n1,n2);
        int dif = height[n1] - height[n2];

        for(int k = 22 ; k >= 0 ; k--){
            if(((1<<k) & dif) != 0){
                n1 = parent[n1][k]; 
            }
        }

        if(n1 != n2){
            for(int k = 22 ; k >= 0 ; --k )
                if(parent[n1][k] != 0 && parent[n1][k] != parent[n2][k]){
                    n1 = parent[n1][k];
                    n2 = parent[n2][k];
                }
            if(parent[n1][0] != 0) n1 = parent[n1][0];
        }
 
        cout<<n1<<"\n";
    }

    
}
int main(void){
    input();
    parent[1][0] = 0; height[1] = 0;
    get_parent_high(1,0);
    get_p();
    print_check();
}
