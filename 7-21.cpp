#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int N;
vector<int> v[500010];
int arr[500010][3];
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 0; i < N-1 ; i++){
        cin>>n1>>n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }
    for(int i = 1; i <= N ; i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
}
int64_t cashe[500010][3];
char ret[500010];
int64_t get(int idx, int t, int beforeidx){
    
    if(cashe[idx][t] != -1) return cashe[idx][t];
    int64_t& ret = cashe[idx][t];
    ret = arr[idx][t];
    
    int len = v[idx].size();
    for(int i = 0; i < len ; i++){
        if(v[idx][i] == beforeidx) continue;
        ret += max(get(v[idx][i],(t+1)%3,idx), get(v[idx][i],(t+2)%3,idx));
    }
    return ret;
}
void find_ret(int idx,int before, int beforeidx){
    int len = v[idx].size();
    if(cashe[idx][(before+1)%3] >= cashe[idx][(before+2)%3]){
        if((before+1)%3 == 0) ret[idx] = 'R';
        if((before+1)%3 == 1) ret[idx] = 'G';
        if((before+1)%3 == 2) ret[idx] = 'B';
        for(int i = 0; i < len ; i++){
            if(v[idx][i] == beforeidx) continue;
            find_ret(v[idx][i],(before+1)%3,idx);
        }
    }
    else{
        if((before+2)%3 == 0) ret[idx] = 'R';
        if((before+2)%3 == 1) ret[idx] = 'G';
        if((before+2)%3 == 2) ret[idx] = 'B';
        for(int i = 0; i < len ; i++){
            if(v[idx][i] == beforeidx) continue;
            find_ret(v[idx][i],(before+2)%3,idx);
        }
    }
}
int main(void){
    FASTIO;
    
    input();
    memset(cashe,-1,sizeof(cashe));
    int64_t n1 = max(get(1,0,0),get(1,1,0));
    int64_t n2 = max(get(1,2,0),n1);
    cout<<n2<<"\n";
    
    for(int i = 0 ;i < 3; i++){
        if(cashe[1][i] == n2){
            find_ret(1,(i+1)%3,0);
        }
    }
    
    for(int i = 1; i <= N ; i++){
        cout<<ret[i];
    }
}