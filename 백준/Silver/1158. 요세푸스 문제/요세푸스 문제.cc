#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,K;
queue <int> pq;
queue <int> resultq;
void getresult(){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++)
        pq.push(i);
    int i = 0;
    while(!pq.empty()){
        i++;
        int n = pq.front();
        pq.pop();
        
        if(i % K == 0)
            resultq.push(n);
        else
            pq.push(n);
    }
}
int main(void){
    getresult();
    cout<<"<";
    for(int i = 0 ; i < N-1 ; i++){
        cout<<resultq.front()<<", ";
        resultq.pop();
    }
    cout<<resultq.front()<<">";
       
}