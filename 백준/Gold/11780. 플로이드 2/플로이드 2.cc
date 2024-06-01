#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N,M;
vector<int> v[105][105];
int adj[105][105];
void input(){
    memset(adj,0,sizeof(adj));
    cin>>N>>M;
    int n1,n2,n3;
    for(int i  = 1 ; i <= M ; i++){
        cin>>n1>>n2>>n3;
        if(adj[n1][n2] == 0) adj[n1][n2] = n3;
        else adj[n1][n2] = min(n3, adj[n1][n2]);
    }
    for(int i  = 1 ; i <= N ; i++){
        for(int j  = 1 ; j <= N ; j++){
            if(adj[i][j] != 0){
                v[i][j].push_back(i);
                v[i][j].push_back(j);
            }
        }
    }
}
void make_flowid(){
    for(int k = 1 ; k <= N ; k ++)
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++){
                if(i == j) continue;
                if(adj[i][k] != 0 && adj[k][j] != 0 && (adj[i][j] > adj[i][k] + adj[k][j] || adj[i][j] == 0)){
                    v[i][j].clear();
                    for(int m = 0 ; m < v[i][k].size()-1 ; m++) v[i][j].push_back(v[i][k][m]);
                    for(int m = 0 ; m < v[k][j].size() ; m++) v[i][j].push_back(v[k][j][m]);
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
    
}

void print_flowid(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            int len = v[i][j].size();
            cout<<len<<" ";
            for(int k = 0 ; k < len ; k++){
                cout<<v[i][j][k]<<" ";
            }
            cout<<"\n";
        }
    }
}

int main(void){
    input();
    make_flowid();
    print_flowid();
    
}
