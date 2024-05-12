//14503 내일해보기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N,M;
vector<int> v[110];

void input(){
    cin>>N>>M;
    int num1,num2;
    for(int i = 0; i < N+M ; i++){
        cin>>num1>>num2;
        v[num1].push_back(num2);
    }
    for(int i = 1 ; i <= 99 ; i++){
        if(v[i].size() == 0){
            for(int j = 1 ; j <= 6 ; j++){
                v[i].push_back(i+j);
            }
        }
    }
}

struct pos{
    int num;
    int cnt;
};
struct cmp{
    bool operator()(pos a, pos b){
        return a.cnt > b.cnt;
    }
};

bool check[110];
int bfs(){
    memset(check,false,sizeof(check));
    int nowcnt;
    pos now,new1;
    now = {1,0};
    priority_queue <pos,vector<pos>,cmp> pq;
    pq.push(now);
    check[1] = true;
    
    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        //cout<<now.num<<" "<<now.cnt<<"\n";
        nowcnt = now.cnt;
        
        new1.cnt = now.cnt + 1;
        for(int i = 0 ; i < v[now.num].size() ; i++){
            new1.num = v[now.num][i];
            
            if(v[now.num].size() == 1){
                new1.cnt = now.cnt;
                pq.push(new1);
                break;
            }
            if(new1.num == 100) return new1.cnt;
            else if(new1.num > 100 || check[new1.num]) continue;
            else{
                pq.push(new1);
                check[new1.num] = true;
            }
        }
    }
}


int main(void){
    input();
    cout<<bfs();
}





