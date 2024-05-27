#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int value[1010];
int N,K,to_get;
vector<int> v[1010];
int64_t cashe[1010];
void input(){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++){
        cin>>value[i];
    }
    int n1,n2;
    for(int i = 1 ; i <= K ; i++){
        cin>>n1>>n2;
        v[n2].push_back(n1);
    }
    cin>>to_get;
}

int64_t dp(int idx){
    int64_t& ret = cashe[idx];
    if(ret != -1) ret;
    ret = 0;
    
    for(int i = 0 ; i < v[idx].size() ; i++){
        if(cashe[v[idx][i]] != -1) ret = max(ret,cashe[v[idx][i]]);
        else ret = max(ret,dp(v[idx][i]));
    }

    ret += value[idx];
    return ret;
}

int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        memset(cashe,-1,sizeof(cashe));
        for(int i = 0 ; i <1010 ; i++){
            v[i].clear();
        }
        input();
        cout<<dp(to_get)<<"\n";
    }
}