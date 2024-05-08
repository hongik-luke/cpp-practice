#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N,M;
int result_cnt = 0;
int check[100100];

struct pos{
    int first;
    int second;
};

int find(){
    int result = 200000;
    bool is_it_over = false;
    
    queue<pos> pq;
    pos now,new1;
    now.first = N;
    now.second = 0;

    pq.push(now);
    check[N] = 0;
    
    while(!pq.empty()){
        
        now = pq.front();
        pq.pop();
        
        if(result < now.second) continue;

        if(now.first == M){
            is_it_over = true;
            result_cnt++;
            result = now.second;
        }
        if(is_it_over) continue;
        
        if(now.first-1 >= 0) {
            new1.first = now.first-1;
            new1.second = now.second+1;
            if(check[new1.first] == -1 || check[new1.first] == new1.second){
                pq.push(new1);
                check[new1.first] = new1.second;
            }
        }
        
        if(now.first+1 <= 100000){
            new1.first = now.first+1;
            new1.second = now.second+1;
            if(check[new1.first] == -1 || check[new1.first] == new1.second){
                pq.push(new1);
                check[new1.first] = new1.second;
            }
        }
        
        if(now.first*2 <= 100000) {
            new1.first = now.first*2;
            new1.second = now.second+1;
            if(check[new1.first] == -1 || check[new1.first] == new1.second){
                pq.push(new1);
                check[new1.first] = new1.second;
            }
        }
        
    }
    
    return result;
}

int main(void){
    cin>>N>>M;
    memset(check,-1,sizeof(check));
    cout<<find()<<"\n"<<result_cnt;
}







