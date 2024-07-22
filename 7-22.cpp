#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N,M,D,E;
int64_t arr[100010];
vector<pair<int,int>> v[100010];
void input(){
    cin>>N>>M>>D>>E;
    for(int i = 1 ; i <= N ; i++){
        cin>>arr[i];
    }
    int n1,n2,n3;
    for(int i = 1 ; i <= M ; i++){
        cin>>n1>>n2>>n3;
        v[n1].push_back({n2,n3});
        v[n2].push_back({n1,n3});
    }
}
struct cmp{
    bool operator()(pair<int,int64_t> a ,pair<int,int64_t> b){
        return a.second > b.second;
    }
};

int64_t from[100010];
int64_t to[100010];

void get_from_to(){
    pair<int,int64_t> c,n; // 앞 idx , 뒤 누적?거리
    priority_queue<pair<int,int64_t>, vector<pair<int,int64_t>>, cmp> pq;
    
    c = {1,0};
    pq.push(c);
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        
        if(from[c.first] != -1) continue;
        from[c.first] = c.second;
        
        int len = v[c.first].size();
        for(int i = 0 ; i < len ; i++ ){
            if(from[v[c.first][i].first] != -1 || arr[v[c.first][i].first] <= arr[c.first] ) continue;
            pq.push({v[c.first][i].first, c.second+v[c.first][i].second});
        }
    }
    
    c = {N,0};
    pq.push(c);
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        
        if(to[c.first] != -1) continue;
        to[c.first] = c.second;
        
        int len = v[c.first].size();
        for(int i = 0 ; i < len ; i++ ){
            if(to[v[c.first][i].first] != -1 || arr[v[c.first][i].first] <= arr[c.first] ) continue;
            pq.push({v[c.first][i].first, c.second+v[c.first][i].second});
        }
    }
}

int main() {
    input();
    memset(from,-1,sizeof(from));
    memset(to,-1,sizeof(to));
    get_from_to();

    bool flag = false;
    int64_t ret = -999999999999999;
    for(int i = 2 ; i < N ; i++){
        if(from[i] == -1 || to[i] == -1) continue;
        ret = max(ret, arr[i]*E - D*(from[i]+to[i]));
        flag = true;
    }
    if(flag) cout<<ret;
    else cout<<"Impossible";
}