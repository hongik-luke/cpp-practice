#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define IMF 98765.4321;
struct pos{
    double value;
    int idx;
};

int V;
vector<pos> adj[110];
double result = 0;

double getd(double x1, double y1, double x2, double y2){
    return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
}
void input(){
    cin>>V;
    vector<pair<double,double>> star;
    double x,y;
    for(int i = 0 ; i < V ; i++){
        cin>>x>>y;
        star.push_back(make_pair(x,y));
    }
    for(int i = 0 ; i < V-1 ; i++){
        for(int j = i+1 ; j < V ; j++){
            double dist;
            pos newpos;
            
            dist = getd(star[i].first, star[i].second, star[j].first, star[j].second);
            
            newpos = {dist,j};
            adj[i].push_back(newpos);
            newpos = {dist,i};
            adj[j].push_back(newpos);
        }
    }
}

bool visited[110];
double dist[110];
void getresult(){
    memset(visited,false,sizeof(visited));
    for(int i = 0 ; i < 110 ;i ++)
        dist[i] = IMF;
    
    dist[0] = 0;
    for(int k = 0 ; k < V ; k++){
        int u = -1;
        double min_dist = IMF;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i] && min_dist > dist[i]){
                min_dist = dist[i];
                u = i;
            }
        }
        
        result += min_dist;
        visited[u] = true;
        
        for(int i = 0 ; i < adj[u].size() ; i++){
            if(visited[adj[u][i].idx]) continue;
            if(dist[adj[u][i].idx] > adj[u][i].value){
                dist[adj[u][i].idx] = adj[u][i].value;
            }
        }
    }
    
    
}
int main(void){
    input();    
    getresult();
    cout<<result;
}







