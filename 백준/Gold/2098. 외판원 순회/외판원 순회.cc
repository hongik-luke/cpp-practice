#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int IMF = 987654321;
int N;
int adj[16][16];
int all_done;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>adj[i][j];
        }
    }
    all_done = (1<<N)-1;
}

int cashe[16][1<<16];
int getone(int start, int now, int visited){
    if(visited == all_done){
        if(adj[now][start] == 0) return IMF;
        else return adj[now][start];
    }
    int& ret = cashe[now][visited];
    if(ret != -1) return ret;
    ret = IMF;
    
    for(int i = 0 ; i < N ; i++){
        if(adj[now][i] == 0) continue;
        if(visited & (1 << i)){
            continue;
        }

        ret = min(ret,getone(start,i,visited + (1<<i))+adj[now][i]);
    }
    return ret;
    
}

int main(void){
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<getone(0,0,(1<<0));
}
