#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
pair<int,int> adj[210][210]; // first - value , second - firstidx (앞 인덱스 - 뒤 인덱스 이동)
void input(){
    memset(adj,0,sizeof(adj));
    int M;
    cin>>N>>M;
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        adj[n1][n2] = make_pair(n3,n2);
        adj[n2][n1] = make_pair(n3,n1);
    }
    
}
void flowid(){
    for(int k = 1 ; k <= N ; k++){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                if(i == j || adj[i][k].first == 0 || adj[k][j].first == 0) continue;
                if(adj[i][j].first == 0 || adj[i][j].first > adj[i][k].first + adj[k][j].first){
                    adj[i][j].first = adj[i][k].first + adj[k][j].first;
                    adj[i][j].second = adj[i][k].second;
                }
                
            }
        }
    }
}

void print(){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            if(i == j) cout<<"- ";
            else cout<<adj[i][j].second<<" ";
        }
        cout<<"\n";
    }
}
int main(void){
    input();
    flowid();
    print();
}




