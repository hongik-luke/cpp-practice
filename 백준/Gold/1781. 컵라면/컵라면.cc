#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

pair<int,int> v[200100];
int N;

void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>v[i].first>>v[i].second;
        
    sort(v,v+N);
}

int getresult(){
    int result = 0;
    priority_queue <int> pq;
    for(int i = 0 ; i < N ; i++){
        if(pq.empty() || pq.size() < v[i].first){
            pq.push(-v[i].second);
        }
        else{
            if(-pq.top() < v[i].second){
                pq.pop();
                pq.push(-v[i].second);
            }
        }
        
    }
    while(!pq.empty()){
        result += -pq.top();
        pq.pop();
    }
    
    return result;
}

int main(void){
    input();
    cout<<getresult();
}