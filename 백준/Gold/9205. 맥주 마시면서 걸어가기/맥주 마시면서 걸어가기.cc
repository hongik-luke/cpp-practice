#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct pos{
    int x;
    int y;
};

int V;
int adj[110][110];

pos firstpos;
pos beer[110];
pos lastpos;

void input(){
    fill(&adj[0][0], &adj[105][105], 0);
    
    cin>>V;
    int x1,y1;
    cin>>x1>>y1;
    firstpos = {x1,y1};
    for(int i = 1 ; i <= V ; i++){
        cin>>beer[i].x>>beer[i].y;
    }
    cin>>x1>>y1;
    lastpos = {x1,y1};
    
    for(int i = 1 ; i <= V ; i++){
        if(abs(beer[i].x - firstpos.x)+abs(beer[i].y - firstpos.y) <= 1000 ) adj[0][i] = 1;
    }
    
    for(int i = 1 ; i <= V ; i++){
        if(abs(beer[i].x - lastpos.x) + abs(beer[i].y - lastpos.y) <= 1000 ) adj[i][V+1] = 1;
    }
    
    if(abs(lastpos.x - firstpos.x)+abs(lastpos.y - firstpos.y) <= 1000 ) adj[0][V+1] = 1;
    
    for(int i = 1 ; i <= V ; i++){
        for(int j = i+1 ; j <= V ; j++){
            if(abs(beer[i].x - beer[j].x) + abs(beer[i].y - beer[j].y) <= 1000 ){
                adj[j][i] = 1;
                adj[i][j] = 1;
            }
        }
    }
    

}

bool getresult(){
    for(int k = 0 ; k <= V+2 ;k++){
        for(int i = 0 ; i <= V+1 ;i++){
            for(int j = 0 ; j <= V+1 ;j++){
                if(i == j) continue;
                
                if(adj[i][j] == 1 || (adj[i][k] + adj[k][j] == 2) ) adj[i][j] = 1;
            }
        }
    }
    if(adj[0][V+1] == 1) return true;
    else return false;
    
    
}
int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();    
        if(getresult()) cout<<"happy"<<"\n";
        else cout<<"sad"<<"\n";
    }
}