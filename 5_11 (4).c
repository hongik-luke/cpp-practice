//14503 내일해보기
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N;
vector<int> scorev[51];
vector<int> friend1[51];

void input(){
    cin>>N;
    int num1,num2;
    while(1){
        cin>>num1>>num2;
        if(num1 == -1 && num2 == -1) break;
        
        friend1[num1].push_back(num2);
        friend1[num2].push_back(num1);
    }
}

struct p{
    int idx;
    int score;
};

bool checkboard[55];
int bfs(int idx){
    int nowscore;
    p nowp, newp;
    nowp = {idx,0};
    queue <p> pq; 
    
    pq.push(nowp);
    checkboard[idx] = true;
    
    while(!pq.empty()){
        nowp = pq.front();
        pq.pop();
        nowscore = nowp.score;
        
        newp.score = nowp.score+1;
        for(int i = 0 ; i < friend1[nowp.idx].size() ; i++){
            newp.idx = friend1[nowp.idx][i];
            if(checkboard[newp.idx]) continue;
            
            pq.push(newp);
            checkboard[newp.idx] = true;
        }
        
    }
    
    return nowscore;
}


void getone(){
    int nowscore;
    for(int i = 1; i <= N ; i++){
        memset(checkboard,false,sizeof(checkboard));
        nowscore = bfs(i);
        scorev[nowscore].push_back(i);
    }
}

void getresult(){
    getone();
    
    for(int i = 1 ; i < 51 ; i++){
        if(scorev[i].size() != 0){
            cout<<i<<" "<<scorev[i].size()<<"\n";
            sort(scorev[i].begin(),scorev[i].end());
            for(int j = 0 ; j < scorev[i].size() ; j++)
                cout<<scorev[i][j]<<" ";
            
            break;
        }
    }
}

int main(void){
    input();
    getresult();
}





