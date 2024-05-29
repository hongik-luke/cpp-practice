#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N,K,M,L;
int pre_sub[15];
int classes[12];
void input(){
    cin>>N>>K>>M>>L;
    for(int i = 0 ; i < N ; i++){
        int n;
        cin>>n; 
        int num = 0,prenum = 0;
        for(int j = 0 ; j < n ; j++){
            cin>>num;
            prenum += (1<<(num));
        }
        pre_sub[i] = prenum;
    }

    for(int i = 0 ; i < M ; i++){
        int n;
        cin>>n;
        int num = 0,prenum = 0;
        for(int j = 0 ; j < n ; j++){
            cin>>num;
            prenum += (1<<(num));
        }
        classes[i] = prenum;
    }

    
}
int bitcnt(int N){
    if(N == 0) return 0;
    return N%2 + bitcnt(N/2);
}
int cashe[15][1<<15];
int get(int semester, int taken){
    if(bitcnt(taken) >= K){
        return 0;
    }
    if(semester == M) return 9876543;
    
    int& ret = cashe[semester+1][taken];
    if(ret != -1) return ret;
    ret = 9876543;
    ret = min(ret,get(semester+1,taken));
    
    int cantake = (classes[semester] & ~taken);
    
    for(int i = 0 ; i < N ; i++){
        if((cantake & (1<<i)) && (taken & pre_sub[i]) != pre_sub[i]){
            cantake = cantake & ~(1<<i);
        }
    }    
    
    for(int take = cantake ; take > 0 ; take = (take-1) & cantake){
        if(bitcnt(take) > L) continue;
        ret = min(ret,get(semester+1,taken | take)+1);
    }
    return ret;
}

int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();
        memset(cashe,-1,sizeof(cashe));
        int result = get(0,0);
        if(result < 9876) cout<<result<<"\n";
        else cout<<"IMPOSSIBLE"<<"\n";    
    }
    
}