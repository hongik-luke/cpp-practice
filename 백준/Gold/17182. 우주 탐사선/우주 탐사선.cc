#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,fir;
int adj[12][12];
void input(){
    cin>>N>>fir;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>adj[i][j];
        }
    }
    
    for(int k = 0 ; k < N ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(i == j || i == k || j == k) continue;
                if(adj[i][j] > adj[i][k] + adj[k][j]) adj[i][j] = adj[i][k] + adj[k][j];
            }
        }   
    }
}
int get(int now, int bit){
    if(bit == 0) return 0;
    
    int ret = 987654321;
    for(int i = 0 ; i < N ; i++){
        if((bit & (1<<i)) != 0){
            ret = min(ret, get(i,bit - (1<<i))+adj[now][i]);
        }
    }
    return ret;
}
int main(void){
    input();
    cout<<get(fir,(1<<N)-(1+(1<<fir)));
}