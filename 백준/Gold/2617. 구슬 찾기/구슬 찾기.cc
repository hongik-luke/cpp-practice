#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int N,M,mid;
vector<int> light[103];
vector<int> heavy[103];
int resultcnt = 0;

void input(){
    cin>>N>>M;
    mid = (N+1)/2;
    int n1,n2;
    for(int i = 0 ;i < M ; i++){
        cin>>n1>>n2;
        heavy[n2].push_back(n1);
        light[n1].push_back(n2);
    }
}

bool check[103];
int dfs(int type,int idx){
    memset(check,false,sizeof(check));
    
    int now;
    int cnt = 0;
    
    queue<int> q;
    q.push(idx);
    check[idx] = true;
    
    while(!q.empty()){
        now = q.front();
        q.pop();

        cnt++;
        if(type == 1){
            for(int i = 0 ; i < light[now].size() ; i++){
                if(check[light[now][i]]) continue;
                
                q.push(light[now][i]);
                check[light[now][i]] = true;
            }
        }
        else{
            for(int i = 0 ; i < heavy[now].size() ; i++){
                if(check[heavy[now][i]]) continue;
                
                q.push(heavy[now][i]);
                check[heavy[now][i]] = true;
            }
        }
    }
    return cnt;
}

void getresult(){
    for(int i = 1 ; i<= N ;i++){
        if(dfs(1,i) > mid){
            resultcnt++;
            continue;
        }
        if(dfs(0,i) > mid){
            resultcnt++;
        }
    }
}

int main(void){
    input();
    getresult();
    cout<<resultcnt<<"\n";
}
