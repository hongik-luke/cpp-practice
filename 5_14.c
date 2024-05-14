#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct pos{
    int value;
    int nextidx;
};

int n = 0;
int m,t,s,g,h;
vector<pos> v[2010];
vector<int> spanning[2010];
vector<int> tarr;

void input(){
    for(int i = 1; i <= n ; i++){
        v[i].clear();
        spanning[i].clear();
    }
    cin>>n>>m>>t;
    cin>>s>>g>>h;
    
    int n1,n2,n3;
    pos new1;
    for(int i = 0 ; i < m ; i++){
        cin>>n1>>n2>>n3;
        new1 = {n3,n2};
        v[n1].push_back(new1);
        new1 = {n3,n1};
        v[n2].push_back(new1);
    }
    for(int i = 0 ; i < t ; i++){
        cin>>n1;
        tarr.push_back(n1);
    }
}


struct npos{
    int value;
    int nowidx;
    int beforeidx;
};
struct cmp{
    bool operator()(npos a ,npos b){
        return a.value >= b.value;
    }
};
bool visited[2010];
void makespanningtree(){
    memset(visited,false,sizeof(visited));
    npos now = {0,s,0};
    npos new1;
    priority_queue<npos,vector<npos>,cmp> pq;
    pq.push(now);
    
    while(!pq.empty()){
        now = pq.top();
        pq.pop();

        if(visited[now.nowidx]) continue;
        
        visited[now.nowidx] = true;
        spanning[now.beforeidx].push_back(now.nowidx);
        
        for(int i = 0 ; i< v[now.nowidx].size() ; i++){
            if(visited[v[now.nowidx][i].nextidx]) continue;
            new1.value = v[now.nowidx][i].value + now.value;
            new1.nowidx = v[now.nowidx][i].nextidx;
            new1.beforeidx = now.nowidx;
            pq.push(new1);
        }
    }
 
}
bool g_hvisited[2010];
void makepassing_g_h(){
    memset(g_hvisited,false,sizeof(g_hvisited));
    g_hvisited[g] = true;
    
    queue <int> pq;
    pq.push(h);
    int now, new1;
    while(!pq.empty()){
        now = pq.front();
        pq.pop();
        
        g_hvisited[now] = true;
        
        for(int i = 0 ; i < spanning[now].size() ; i++){
            new1 = spanning[now][i];
            pq.push(new1);
        }
        
    }
    
    
}
void checkspanning(){
    vector<int> resultv;
    makepassing_g_h();
    for(int i = 0 ; i< tarr.size() ;i++){
        if(g_hvisited[tarr[i]]) resultv.push_back(tarr[i]);
    }
    sort(resultv.begin(),resultv.end());
    
    for(int i = 0 ; i< resultv.size() ;i++) cout<<resultv[i]<<" ";
}



int main(void)
{
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();
        makespanningtree();
        
        checkspanning();
        cout<<"\n";
    }
}