#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int IMF = 98765432;
int V,E;
int adj[110][110];
void input(){
    fill(&adj[0][0],&adj[105][105],0);
    
    cin>>V>>E;
    int n1,n2,n3;
    
    for(int i = 0 ; i < E ; i++){
        cin>>n1>>n2>>n3;
        if(adj[n1][n2] == 0) adj[n1][n2] = n3;
        else adj[n1][n2] = min(adj[n1][n2] ,n3);
    }
    
}

void getflowid(){
    for(int k = 1 ; k <= V ; k++){
        for(int i = 1 ; i <= V ; i++){
            for(int j = 1 ; j <= V ; j++){
                if(i == j) continue;
                if(adj[i][k] == 0 || adj[k][j] == 0) continue;
                if(adj[i][j] == 0) adj[i][j] = adj[i][k] + adj[k][j];
                else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i = 1 ; i <= V ; i++){
        for(int j = 1 ; j <= V ; j++){
            cout<<adj[i][j]<<" ";  
        }
        cout<<"\n";
    }
}

int main(void){
    input();
    getflowid();
}
