#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,K;
int64_t dp[100010];
int64_t seg[400010];
void make_seg(int lo, int hi, int idx){
    if(lo == hi){
        seg[idx] = dp[lo];
        return;
    }
    int mid = (lo+hi)/2;
    make_seg(lo,mid,idx*2+1);
    make_seg(mid+1,hi,idx*2+2);
    seg[idx] = max(seg[idx*2+1],seg[idx*2+2]);
}

void change_seg(int lo, int hi, int idx,int findidx, int64_t num){
    if(lo == hi){
        seg[idx] = num;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx <= mid)
        change_seg(lo,mid,idx*2+1,findidx,num);
    else
        change_seg(mid+1,hi,idx*2+2,findidx,num);
    seg[idx] = max(seg[idx*2+1],seg[idx*2+2]);
}
int64_t get_seg(int lo, int hi, int idx,int l ,int r){
    if(hi < l || r < lo){
        return 0;
    }
    if(l <= lo && hi <= r){
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    return max(get_seg(lo,mid,idx*2+1,l,r), get_seg(mid+1,hi,idx*2+2,l,r));
}
void insert(){
    cin>>N>>K;
    for(int i = 1 ;i <= N ; i++){
        cin>>dp[i];
    }
    make_seg(1,N,0);
}

void get_dp(int idx){
    int maxidx = min(idx+K,N);
    dp[idx] = max(dp[idx], dp[idx]+get_seg(1,N,0,idx+1,maxidx));
    change_seg(1,N,0,idx,dp[idx]);
    return;
}
int main(){
    FastIO;
    insert();
    int64_t ret = -99999999999999;
    for(int i = N-1 ; i > 0 ; i--){
        get_dp(i);
    }
    for(int i = 1 ;i <= N ; i++){
        ret = max(ret,dp[i]);
    }
    cout<<ret;
}