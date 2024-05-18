#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int IMF = 98765432;
int N,M,K;
int adj[255][255];
vector<pair<int,int>> checking;
int resultcnt = 0;

void input(){
    fill(&adj[0][0], &adj[253][253],IMF);
    cin>>N>>M;
    int n1,n2,n3;
    for(int i = 0 ;i < M ; i++){
        cin>>n1>>n2>>n3;
        if(n3 == 1){
            adj[n1][n2] = 0;
            adj[n2][n1] = 0;
        }
        else{
            adj[n1][n2] = 0;
            adj[n2][n1] = 1;
        }
    }
    for(int i = 1 ;i <= N ; i++) adj[i][i] = 0;
    cin>>K;
    for(int i = 0 ; i < K ; i++){
        cin>>n1>>n2;
        checking.push_back(make_pair(n1,n2));
    }
    
}


void floid(){
    for(int k = 1; k <= N ; k++){
        for(int i = 1; i <= N ; i++){
            for(int j = 1; j <= N ; j++){
                if(i == j) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

void getresult(){
    for(int i = 0 ;i < checking.size() ; i++){
        cout<<adj[checking[i].first][checking[i].second]<<"\n";
    }
}

int main(void){
    input();
    floid();
    getresult();
    
}