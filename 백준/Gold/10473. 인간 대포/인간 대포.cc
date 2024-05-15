#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;


struct pos{
    double x;
    double y;
};
    
int m;
double firstx,firsty;
double lastx,lasty;
vector <pos> v; //v[0] - 도착지  , v[1]~ 대포 
void input(){
    cin>>firstx>>firsty;
    cin>>lastx>>lasty;
    pos newpos = {lastx,lasty};
    v.push_back(newpos);
    
    cin>>m;
    double x1,y1;
    for(int i = 0 ; i < m ; i++){
        cin>>x1>>y1;
        newpos = {x1,y1};
        v.push_back(newpos);
    }
}
double gettime(double x_1, double y_1, double x_2, double y_2){ return double(sqrt((y_2-y_1)*(y_2-y_1) + (x_2-x_1)*(x_2-x_1))) / 5;}
double gettime_to_cannon(double x_1, double y_1, double x_2, double y_2){return abs(sqrt((y_2-y_1)*(y_2-y_1) + (x_2-x_1)*(x_2-x_1)) -50)/5;}

struct qpos{
    double times;
    int idx;
};
struct cmp{
    bool operator()(qpos a ,qpos b){
        return a.times > b.times ;
    }
};
bool visited[110];
double getresult(){
    priority_queue <qpos,vector<qpos>,cmp> pq;
    qpos now,new1;
    for(int i = 0 ; i< v.size() ; i++){
        now = {gettime(firstx,firsty,v[i].x,v[i].y),i};
        pq.push(now);
    }
    
    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        if(now.idx == 0) return now.times;
        if(visited[now.idx]) continue;
        visited[now.idx] = true;
        for(int i = 0 ; i < v.size() ; i++){
            if(i == now.idx) continue;
            new1 = {gettime_to_cannon(v[now.idx].x, v[now.idx].y, v[i].x, v[i].y) + now.times + 2,i};
            pq.push(new1);
        }
    }
}
int main(void){
    input();
    printf("%0.6f",getresult());
}