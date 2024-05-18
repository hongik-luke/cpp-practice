#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int nowidx;
    int value;
    int originalidx;
};

int N,M,K;
vector<pos> adj[100010];
vector<int> place;
bool testplace[100010];


void input(){
    cin>>N>>M>>K;
    pos npos;
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        npos = {n2,n3,n2};
        adj[n1].push_back(npos);
    }
    for(int i = 0 ; i < K ; i++){
        cin>>n1;
        testplace[n1] = true;
    }
    for(int i = 1 ; i <= N ;i++){
        if(!testplace[i]) place.push_back(i);
    }
    
}
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }  
};

int cashe[100010];
void daikstra(){
    testplace[0] = true;
    memset(cashe,-1,sizeof(cashe));
    pos cpos,npos;
    priority_queue <pos,vector<pos>,cmp> pq;

    for(int i = 0 ; i < place.size() ; i++){
        cpos = {place[i],0,place[i]};
        pq.push(cpos);
    }
    
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        
        if(cashe[cpos.originalidx] != -1) continue; //이미 찾은 친구라면 꺼지고
        
        //cout<<cpos.nowidx<<" "<<cpos.value<<" "<<cpos.originalidx<<"\n";
        
        if(testplace[cpos.nowidx]){ // 찾았으면 캐시 저장하고 꺼지고
            cashe[cpos.originalidx] = cpos.value;
            continue;
        }

        
        if(cashe[cpos.nowidx] != -1){  // 지금인덱스가 캐시가 있는 인덱스면 그 값대로 넣어주고 (지금 인덱스말고 다른 경로랑 비교해야함)
            npos = {0 , cpos.value + cashe[cpos.nowidx] , cpos.originalidx};
            pq.push(npos);
        }
        else{
            for(int i = 0 ; i < adj[cpos.nowidx].size() ; i++){
                npos = {adj[cpos.nowidx][i].nowidx, adj[cpos.nowidx][i].value + cpos.value, cpos.originalidx};
                pq.push(npos);
            }
        }
    }
    int maxvalue = 0;
    for(int i = 1 ; i <= N ; i++ ){
        if(testplace[i]) continue;
        maxvalue = max(maxvalue,cashe[i]);
    }
    for(int i = 1 ; i <= N ; i++ ){
        if(maxvalue == cashe[i]){
            cout<<i<<"\n"<<cashe[i];
            return;
        }
    }
}

int main(void){
    input();
    daikstra();
}

