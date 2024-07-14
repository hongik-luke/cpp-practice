#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
vector<int> adj[200005];
int arr[200005];
int cashe[200005][3]; // cashe[i][0] - 종속 x  / cashe[i][1] - 위에 애랑 종속 / cashe[i][2] - 밑에 애랑 종속
void input(){
    cin>>N;
    int n1;
    for(int i = 2 ; i <= N ; i++){
        cin>>n1;
        adj[n1].push_back(i);
    }
    for(int i = 1 ; i <= N ; i++){
        cin>>n1;
        arr[i] = n1;
    }
}
int get(int idx, int temp){
    if(cashe[idx][temp] != -1) return cashe[idx][temp];
    int &ret = cashe[idx][temp];
    ret = 0;
    int len = adj[idx].size();
    if(temp == 0 || temp == 1){
        for(int i = 0 ; i < len ; i++){
            ret += max(get(adj[idx][i],0),get(adj[idx][i],2));
        }    
    }
    
    if(temp == 2){
        int now_ret = 0;
        for(int i = 0 ; i < len ; i++){
            now_ret += max(get(adj[idx][i],0),get(adj[idx][i],2));
        }
        
        for(int i = 0 ; i < len ; i++){
            int now_retr = now_ret + arr[idx]*arr[adj[idx][i]] + get(adj[idx][i],1) - max(cashe[adj[idx][i]][0],cashe[adj[idx][i]][2]);
            ret = max(ret,now_retr);
        }
    }
    //cout<<idx<<" "<<temp<<" "<<ret<<"\n";
    return ret;
}

int main(void){
    FASTIO;
    input();
    memset(cashe ,-1 ,sizeof(cashe));
    cout<<max(get(1,0),get(1,2));
}

