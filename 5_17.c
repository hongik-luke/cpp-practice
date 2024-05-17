#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
const int IMF = 98765432;
int E;
int capacitiy[60][60]; //a 0 , z 25, A 26 , Z 61
int flow[60][60]; // 
void input(){
    cin>>E;
    char c1,c2;
    int n1,n2,n3;
    for(int i = 0 ; i < E ; i++){
        cin>>c1>>c2>>n3;
        if((int)c1 >= 65 && (int)c1 <= 90)
            n1 = (int)c1 - 39;
        else
            n1 = (int)c1 - 97;
        
        if((int)c2 >= 65 && (int)c2 <= 90)
            n2 = (int)c2 - 39;
        else
            n2 = (int)c2 - 97;

        capacitiy[n1][n2] += n3;
        capacitiy[n2][n1] += n3;
    }

}

int networkFlow(int source , int sink){
    memset(flow,0,sizeof(flow));   
    int totalflow = 0;
    
    while(true){
        vector<int> parent(60,-1);
        queue <int> q;
        parent[source] = source;
        q.push(source);
        while(!q.empty() && parent[sink] == -1){
            int here = q.front();
            q.pop();
            for(int there = 0 ; there < 52 ; there++){
                if(capacitiy[here][there] - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        
        
        if(parent[sink] == -1) break;
        
        int amount = IMF;
        for(int p = sink ; p != source ; p = parent[p])
            amount = min(capacitiy[parent[p]][p] - flow[parent[p]][p],amount);
            
        for(int p = sink ; p != source ; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        
        totalflow += amount;
    }
        
    return totalflow;    
}

int main(void){
    input();
    cout<<networkFlow(26,51);
}



