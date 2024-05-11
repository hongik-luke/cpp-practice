#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

int V,E;
int checker[20005];
vector<int> v[20005];

void input(){
    
    cin>>V>>E;
    memset(checker,0,sizeof(checker));
    for(int i = 1 ; i <= V ; i++)
        v[i].clear();
    
    int num1,num2;
    for(int i = 0 ;i < E ;i++){
        cin>>num1>>num2;
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    
}

bool dfs(int firstidx){
    checker[firstidx] = 1;
    queue <int> pq;
    pq.push(firstidx);
    
    int now;
    
    while(!pq.empty()){
        now = pq.front();
        pq.pop();
        
        for(int i = 0 ;i < v[now].size() ; i++){
            if(checker[v[now][i]] == 0){
                pq.push(v[now][i]);
                checker[v[now][i]] = -checker[now];
            }
            
            if(checker[v[now][i]] == checker[now])
                return false;
            
        }
    }
    return true;
}

bool getresult(){
    
    for(int i = 1 ; i <= V ; i++)
        if(checker[i] == 0)
            if(!dfs(i)) return false;
    
    return true;
}

int main(void){
    int repeat;
    cin>>repeat;
    for(int i = 0 ; i < repeat ; i++){
        input();
        if(getresult()) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}





