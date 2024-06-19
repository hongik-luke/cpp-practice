#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
vector<int> front_v[505];
vector<int> back_v[505];
int N,M;
void input(){
    cin>>N>>M;
    int n1,n2;
    for(int i = 0 ; i < M; i++){
        cin>>n1>>n2;
        front_v[n1].push_back(n2);
        back_v[n2].push_back(n1);
    }
}
bool check[505];
bool get(int idx){
    memset(check,false,sizeof(check));
    check[idx] = true;
    int len;
    int c;
    
    queue<int> frontq;
    len = front_v[idx].size();
    for(int i = 0 ; i < len ; i++){
        frontq.push(front_v[idx][i]);
        check[front_v[idx][i]] = true;
    }
    
    while(!frontq.empty()){
        c = frontq.front();
        frontq.pop();
        
        len = front_v[c].size();
        for(int i = 0 ; i < len ; i++){
            if(check[front_v[c][i]]) continue;
            frontq.push(front_v[c][i]);
            check[front_v[c][i]] = true;
        }
    }
    
    
    queue<int> backq;
    len = back_v[idx].size();
    for(int i = 0 ; i < len ; i++){
        backq.push(back_v[idx][i]);
        check[back_v[idx][i]] = true;
    }
    
    while(!backq.empty()){
        c = backq.front();
        backq.pop();
        
        len = back_v[c].size();
        for(int i = 0 ; i < len ; i++){
            if(check[back_v[c][i]]) continue;
            backq.push(back_v[c][i]);
            check[back_v[c][i]] = true;
        }
    }
    
    for(int i = 1 ; i <= N ; i++){
        if(!check[i]) return false;
    }
    return true;
}
int main(void){
    input();
    int cnt = 0;
    for(int i = 1 ; i <= N ; i++)
        if(get(i)) cnt++;
    cout<<cnt;
}