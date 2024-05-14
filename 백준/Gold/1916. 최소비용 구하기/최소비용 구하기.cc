#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector<pair<int,int>> v[1010];
int start, finish;
bool visited[1010];
void input(){
    cin>>N>>M;
    int num1,num2,num3;
    for(int i = 0 ; i < M ; i++){
        cin>>num1>>num2>>num3;
        v[num1].push_back(make_pair(num3,num2));
    }
    cin>>start>>finish;
    memset(visited,false,sizeof(visited));
}


int getresult(){
    pair<int,int> c,n;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        //cout<<c.first<<" "<<c.second<<"\n";
        if(c.second == finish) return -c.first;
        if(visited[c.second]) continue;
        visited[c.second] = true;
        
        for(int i = 0 ; i < v[c.second].size() ; i++){
            if(visited[v[c.second][i].second]) continue;
            
            n = v[c.second][i];
            n.first =  (-n.first) + c.first;
            pq.push(n);
        }
    }
}

int main(void){
    input();
    cout<<getresult();
    
}