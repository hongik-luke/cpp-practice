#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define IMF 98765432;
struct pos{
    int value;
    int idx;
};

int V,E;
vector<pos> adj[10010];

void input(){
    cin>>V>>E;
    int n1,n2,n3;
    for(int i = 0 ; i < E ; i++){
        cin>>n1>>n2>>n3;
        pos newpos = {n3,n2};
        adj[n1].push_back(newpos);
        newpos = {n3,n1};
        adj[n2].push_back(newpos);
    }
}
int result = 0;
bool visited[10010];
int dist[10010];
void getresult(){
    for(int i = 0 ; i<= 10010 ;i++)
        dist[i] = IMF;
    memset(visited,false,sizeof(visited));
    
    dist[1] = 0;
    for(int i = 0 ; i < V ; i++){
        int u = 0;
        int min_dist = IMF;
        for(int j = 1 ; j <= V ; j++){
            if(!visited[j] && min_dist > dist[j]){
                min_dist = dist[j];
                u = j;
            }
        }

        result += dist[u];
        visited[u] = true;
        
        for(int j = 0 ; j < adj[u].size() ; j++){
            if(!visited[adj[u][j].idx] && dist[adj[u][j].idx] > adj[u][j].value){
                dist[adj[u][j].idx] = adj[u][j].value;
            } 
        }
        
        
    }
}
int main(void){
    input();    
    getresult();
    cout<<result;
}







