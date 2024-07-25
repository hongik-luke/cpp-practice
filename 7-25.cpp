#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N,M;
int cntarr[105];
bool check[105];
vector<pair<int,int>> v[105];
void input(){
    cin>>N>>M;
    int n1,n2,n3;    
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        v[n1].push_back({n2,n3});
        cntarr[n2]++;
    }
}
int cnt[105];
void get(){
    int arr[105];
    int qc = 0;
    
    queue<int> q;    
    q.push(N);
    check[N] = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        
        arr[qc++] = c;
        check[c] = true;
        
        int len = v[c].size();
        for(int i = 0; i < len ; i++){
            cntarr[v[c][i].first]--;
        }
        
        for(int i = 1 ; i <= N ; i++){
            if(check[i]) continue;
            if(cntarr[i] == 0){
                q.push(i);
                check[i] = true;
            }
        }
    }    




    memset(cnt,0,sizeof(cnt));
    cnt[N] = 1;
    for(int i = 0 ; i < N ; i++){
        int now = arr[i];
        if(cnt[now] == 0) continue;
        
        int len = v[now].size();
        for(int j = 0 ; j < len ; j++){
            cnt[v[now][j].first] += v[now][j].second*cnt[now];
        }
        if(len != 0) cnt[now] = 0;
    }
}
int main(){
    input();
    get();
    for(int i = 1 ;i <= N ; i++){
        if(cnt[i] == 0) continue;
        cout<<i<<" "<<cnt[i]<<"\n";
    }
}