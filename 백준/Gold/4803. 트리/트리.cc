#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M;
bool visited[505];
vector<int> v[505];
bool input(){
    memset(visited,false,sizeof(visited));
    for(int i = 0; i < 505 ; i++){
        v[i].clear();
    }
    cin>>N>>M;
    if(N == 0 && M == 0) return false;
    int n1,n2;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    return true;
}

bool getone(int f){
    pair<int,int> c;  //first 자기 인덱스 // second 전 인덱스
    c = make_pair(f,f);
    queue<pair<int,int>> pq;
    pq.push(c);
    while(!pq.empty()){
        c = pq.front();
        pq.pop();
        
        if(visited[c.first]) return false;
        visited[c.first] = true;
        
        for(int i = 0 ; i < v[c.first].size() ; i++){
            if(v[c.first][i] == c.second) continue;
            pq.push(make_pair(v[c.first][i], c.first));
        }
    }
    return true;
}
int getthem(){
    int cnt = 0;
    bool flag  = false;
    for(int i = 1 ; i <= N ; i++){
        if(visited[i]) continue;
        if(!getone(i)) cnt--;
        cnt++;
    }
    return cnt;
}
int main(void){
    int TC = 0;
    while(1){
        TC++;
        if(!input()) return 0;
        int ret = getthem();
        if(ret == 0)   cout << "Case " << TC << ": No trees.\n";
        else if(ret == 1)  cout << "Case " << TC << ": There is one tree.\n";
        else    cout << "Case " << TC << ": A forest of " << ret <<" trees.\n";
    }
}