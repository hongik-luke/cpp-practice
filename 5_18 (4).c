#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int IMF = 987654321;


struct pos{
    int idx;
    int value;

};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }
};

vector <pos> adj[1010];
int N,M,T;
vector <int> elec;
int result = 0;
void input(){
    cin>>N>>M>>T;
    int n1,n2,n3;
    pos npos;
    for(int i = 0 ; i< T ; i++){
        cin>>n1;
        elec.push_back(n1);
    }
    for(int i = 0 ; i< M ; i++){
        cin>>n1>>n2>>n3;
        npos = {n2,n3};
        adj[n1].push_back(npos);
        npos = {n1,n3};
        adj[n2].push_back(npos);
    }


    
}

bool visited[1010];
void primemaybe(){
    memset(visited,false,sizeof(visited));
    priority_queue<pos,vector<pos>,cmp> pq;
    pos cpos,npos;
    
    for(int i = 0 ; i < elec.size() ; i++){
        cpos = {elec[i],0};
        pq.push(cpos);
    }
    
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        //cout<<cpos.idx<<" "<<cpos.value<<"\n";
        if(visited[cpos.idx])continue;
        visited[cpos.idx] = true;
        result += cpos.value;
        
        for(int i = 0 ;i < adj[cpos.idx].size() ; i++){
            if(visited[adj[cpos.idx][i].idx]) continue;
            
            npos = {adj[cpos.idx][i].idx, adj[cpos.idx][i].value};
            pq.push(npos);
        }
        
    }
    
    
}

int main(void){
    input();
    primemaybe();
    cout<<result;

}

