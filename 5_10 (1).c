//연구소 14502

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
struct pos{
    int x;
    int y;
};

int N;
int v[105];
vector<int> resultv;
bool check[105];

void input(){
    cin>>N;
    int num;
    
    for(int i = 1 ; i <= N ; i++){
        cin>>v[i];
    }
    memset(check,false,sizeof(check));
}

void dfs(int firstidx){
    bool is_it_right = false;
    
    vector<int> returnv;
    queue<int> pq;
    pq.push(v[firstidx]);
    returnv.push_back(v[firstidx]);
    
    int now;
    while(!pq.empty()){
        now = pq.front();
        pq.pop();

        if(now == firstidx){
                is_it_right = true;
                break;
            }
        if(check[now]) break;
        
        pq.push(v[now]);
        returnv.push_back(v[now]);
        check[now] = true;
    }
    
    if(is_it_right){
        for(int i = 0 ; i < returnv.size() ; i++)
            resultv.push_back(returnv[i]);
    }
    return;
    
}
bool resultcheck[105]; 

int getresult(){
    for(int i = 1 ; i <= N ; i++){
        memset(check,false,sizeof(check));
        dfs(i);
    }
    
    sort(resultv.begin(),resultv.end());
    
    int cnt = 0;
    memset(resultcheck,false,sizeof(resultcheck));
    for(int i = 0; i < resultv.size() ; i++){
        if(!resultcheck[resultv[i]]){
            resultcheck[resultv[i]] = true;
            cnt++;
        }
    }
    
    
    return cnt;
}


int main(void){
    input();
    cout<<getresult()<<"\n";
    for(int i = 1 ; i <= N ; i++){
        if(resultcheck[i])
            cout<<i<<"\n";
    }

}







