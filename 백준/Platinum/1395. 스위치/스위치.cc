#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,M;
int seg[400000][2];
void propagate(int idx, int lo ,int hi){
    if(seg[idx][1] != 0){
        seg[idx][0] = (hi-lo+1) - seg[idx][0];
        if(lo != hi){
            if(seg[idx*2][1] == 1) seg[idx*2][1] = 0;
            else seg[idx*2][1] = 1;
            if(seg[idx*2+1][1] == 1) seg[idx*2+1][1] = 0;
            else seg[idx*2+1][1] = 1;
        }
        seg[idx][1] = 0;
    }
}
int change(int idx, int lo ,int hi, int l, int r){

    propagate(idx,lo,hi);
    if(hi < l || r < lo){
        return seg[idx][0];
    }
    if(l <= lo && hi <= r){
        seg[idx][1] = 1;
        propagate(idx,lo,hi);
        return seg[idx][0];
    }
    int mid = (lo+hi)/2;
    seg[idx][0] = change(idx*2,lo,mid,l,r) + change(idx*2+1,mid+1,hi,l,r);
    return seg[idx][0];
}
int get(int idx, int lo ,int hi, int l , int r){
    propagate(idx,lo,hi);
    if(hi < l || r < lo) return 0;
    if(l <= lo && hi <= r) return seg[idx][0];
    int mid = (lo+hi)/2;
    int ret = get(idx*2,lo,mid,l,r) + get(idx*2+1,mid+1,hi,l,r);
    return ret;
}
void input(){
    int n1,n2,n3;
    for(int i =0 ; i < M; i++){
        cin>>n1>>n2>>n3;
        n2 -= 1;
        n3 -= 1;
        if(n1 == 0){
            change(1,0,N-1,n2,n3);
        }
        else{
            cout<<get(1,0,N-1,n2,n3)<<"\n";
        }
    }
}
int main(void) {
    FASTIO;
    cin>>N>>M;
    memset(seg,0,sizeof(seg));
    input();
}