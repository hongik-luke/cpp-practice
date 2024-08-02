#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
int64_t mod =  1000000007;
using namespace std;
int N;
int64_t seg[810000][2]; 

int64_t get_seg(int lo, int hi, int idx, int l ,int r,int temp){
    if(hi < l || r < lo){
        return 0;
    }
    if(l <= lo && hi <= r){
        if(temp == 0)
            return seg[idx][0];
        else
            return seg[idx][1];
    }
    int mid = (lo+hi)/2;
    return get_seg(lo,mid,idx*2+1,l,r,temp) + get_seg(mid+1,hi,idx*2+2,l,r,temp);
}
void update_seg(int lo, int hi, int idx, int findidx){
    if(lo == hi){
        seg[idx][0]++;
        seg[idx][1] += findidx;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx <= mid)
        update_seg(lo,mid,idx*2+1,findidx);
    else
        update_seg(mid+1,hi,idx*2+2,findidx);
    seg[idx][0] = seg[idx*2+1][0] + seg[idx*2+2][0];
    seg[idx][1] = seg[idx*2+1][1] + seg[idx*2+2][1];
}
int64_t get_result(){
    int64_t ret = 1;
    int64_t now;
    cin>>now;
    update_seg(0,200000,0,now);
    for(int i = 1 ; i < N ; i++){
        cin>>now;
        int64_t front_num = get_seg(0,200000,0,0,now-1,0);
        int64_t back_num = get_seg(0,200000,0,now+1,200000,0);
        int64_t front_seg = get_seg(0,200000,0,0,now-1,1);
        int64_t back_seg = get_seg(0,200000,0,now+1,200000,1);
        
        int64_t nowret = (now*front_num-front_seg) + (back_seg - now*back_num);
        nowret %= mod;
        ret *= nowret;
        ret %= mod;
        update_seg(0,200000,0,now);
    }
    return ret;
}
int main(){
    FastIO;
    cin>>N;
    cout<<get_result();
}