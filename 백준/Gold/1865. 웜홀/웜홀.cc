// 해결한 거 같긴한데 왜인지 이유는 모르겠다.
// 이럴땐 벨만 포드 쓰면돼~ 해서 그냥 쓰는 느낌
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

struct pos {
    int value;
    int idx;
};
int IMF = 98765432;
int F = 9876543;
int N,M,W;

vector<pos> v[510];
void input(){
    cin>>N>>M>>W;
    int n1,n2,n3;
    pos newpos;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        newpos = {n3,n2-1};
        v[n1-1].push_back(newpos);
        newpos = {n3,n1-1};
        v[n2-1].push_back(newpos);
    }
    for(int i = 0 ; i < W ; i++){
        cin>>n1>>n2>>n3;
        newpos = {-n3,n2-1};
        v[n1-1].push_back(newpos);
    }
    
}

bool getresult(){
    vector<int> distance(N,IMF);
    distance[0] = 0;
    bool check;
    
    for(int iter = 0 ; iter < N ; iter++){
        check = true;
        for(int here = 0 ; here < N ; here++){
            for(int j = 0 ; j < v[here].size() ; j++){
                int there = v[here][j].idx;
                int cost = v[here][j].value;
                
                if(distance[there] > distance[here] + cost){
                    check = false;
                    distance[there] = distance[here] + cost;
                }
            }
        }
        if(check) return false;
    }
    return true;
}

int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ;i++){
        input();
        if(getresult()) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
        for(int i = 0 ; i <= N ; i++)
            v[i].clear();
    }
}