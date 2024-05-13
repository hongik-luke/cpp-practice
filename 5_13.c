#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N;
int graph_high[100010];
void input(){
    cin>>N;
    graph_high[0] = -1;
    for(int i = 1 ; i <= N ; i++){
        cin>>graph_high[i];
    }
    graph_high[N+1] = -1;
}


int search(int firstidx ,int lastidx){
    if(firstidx == lastidx) return graph_high[firstidx];
    
    int mid = (firstidx+lastidx) / 2;
    int maxresult = max(search(firstidx,mid) ,search(mid+1,lastidx));
    
    int nowfirst = mid;
    int nowlast = mid+1;
    int nowhigh = min(graph_high[nowfirst], graph_high[nowlast]);
    while(1){
        maxresult = max(maxresult,nowhigh*(nowlast-nowfirst+1));
        if(nowfirst == firstidx && nowlast == lastidx) break;
        else if(nowfirst == firstidx){
            nowlast++;
            nowhigh = min(nowhigh, graph_high[nowlast]);
        }
        else if(nowlast == lastidx){
            nowfirst--; 
            nowhigh = min(nowhigh, graph_high[nowfirst]);
        }
        else if(graph_high[nowfirst-1] > graph_high[nowlast+1]){
            nowfirst--; 
            nowhigh = min(nowhigh, graph_high[nowfirst]);
        }
        else{
            nowlast++;
            nowhigh = min(nowhigh, graph_high[nowlast]);
        }
    }
    
    return maxresult;
}

int main(void){
    input();
    cout<<search(1,N);
}



