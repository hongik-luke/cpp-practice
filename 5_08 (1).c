#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N,M;

bool check[200100];

struct pos{
    int num;
    int times;
};

struct cmp {
    bool operator()(pos a, pos b) {
        if( a.times == b.times) return a.num > b.num;
        else return a.times > b.times;
    }
};

int find(){
    priority_queue<pos, vector<pos>, cmp> pq; 
    pos now,new1;
    
    now.num = N;
    now.times = 0;
    pq.push(now);
    check[N] = true;
    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        //cout<<now.num<<" "<<now.times<<"\n";
        if(now.num == M)
            return now.times;
            
        new1.times = now.times;
        if(now.num*2 < 200001 && check[now.num*2] == false){
            new1.num = now.num*2;
            pq.push(new1);
            check[new1.num] = true;
        }
        
        
        new1.times = now.times+1;
        if(now.num -1 >= 0 && check[now.num-1] == false){
            new1.num = now.num -1;
            pq.push(new1);
            check[new1.num] = true;
        }
        
        if(now.num +1 < 200001 && check[now.num+1] == false){
            new1.num = now.num +1;
            pq.push(new1);
            check[new1.num] = true;
        }
       
        
    }
}

int main(void){
    cin>>N>>M;
    memset(check,false,sizeof(check));
    cout<<find();
}







