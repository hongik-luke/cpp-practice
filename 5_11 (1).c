#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

int N,M;

vector<int> comp[320100];
int checker[320100];

void input(){
    cin>>N>>M;
    int num1,num2;
    for(int i = 0 ; i < M ; i++){
        cin>>num1>>num2;
        comp[num1].push_back(num2);
        checker[num2]++;
    }
}

void getresult(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1 ; i <= N ;i++)
        if(checker[i] == 0) pq.push(i);
    int now;    
    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        
        cout<<now<<" ";
        
        for(int i = 0 ; i < comp[now].size() ; i++){
            int nownow = comp[now][i];
            checker[nownow]--;
            
            if(checker[nownow] == 0)
                pq.push(nownow);
        }
        
    }
}

int main(void){
    input();
    getresult();
}







