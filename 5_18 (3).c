#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int IMF = 987654321;
int N,M,T;

int adj[305][305];
int result[40010][2];
void input(){
    fill(&adj[0][0],&adj[303][303],IMF);
    cin>>N>>M>>T;
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        if(adj[n1][n2] == IMF)
            adj[n1][n2] = n3;
        else
            adj[n1][n2] = max(adj[n1][n2],n3);
        
    }
    for(int i = 0 ; i < T ; i++){
        cin>>result[i][0]>>result[i][1];
    }
    
}

void flowid(){
    for(int k = 1 ; k <= N ; k++)
        for(int i = 1 ; i <= N ; i++)
            for(int j = 1 ; j <= N ; j++){
                if(i == j || i == k || k == j || adj[i][k] == IMF || adj[k][j] == IMF) continue;

                if(adj[i][j] == IMF)
                    adj[i][j] = max(adj[i][k],adj[k][j]);
                else
                    adj[i][j] = min(adj[i][j] ,max(adj[i][k],adj[k][j]));
                
            }

    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            if(adj[i][j] == IMF) adj[i][j] = -1;

}

int main(void){
    input();
    flowid();
    for(int i = 0 ; i < T ; i++)
        cout<<adj[result[i][0]][result[i][1]]<<"\n";
}

