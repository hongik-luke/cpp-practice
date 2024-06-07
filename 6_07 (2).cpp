#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int N,M,K;
int64_t arr[1000010];
int64_t check[20020][3];
int64_t segtree[4000000];
void input(){
    cin>>N>>M>>K;
    for(int i = 1 ; i <= N ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < M+K ; i++){
        cin>>check[i][0]>>check[i][1]>>check[i][2];
    }
}
int64_t make_seg(int lo, int hi, int idx){
    if(lo == hi) return segtree[idx] = arr[lo];
    int mid = (lo+hi)/2;
    return segtree[idx] = make_seg(lo,mid,idx*2) + make_seg(mid+1,hi,idx*2+1);
}

int64_t get(int getf, int getl, int lo, int hi, int idx){
    
    if(hi < getf || getl < lo) return 0;
    if(getf <= lo && hi <= getl) return segtree[idx];
    
    int mid = (lo+hi)/2;
    int64_t l = get(getf,getl,lo,mid,idx*2);
    int64_t r = get(getf,getl,mid+1,hi,idx*2+1);
    return l+r;
    
}
void change(int c_idx, int64_t dif, int lo, int hi, int idx){
    if(c_idx < lo || hi < c_idx) return;
    segtree[idx] += dif;
    
    if(lo != hi){
        int mid = (lo+hi)/2;
        change(c_idx, dif, lo, mid, idx*2);
        change(c_idx, dif, mid+1, hi, idx*2+1);
    }
    return;
}
int main(void){
    
    input();
    make_seg(1,N,1);
    for(int i = 0 ; i < M+K ; i++){
        if(check[i][0] == 2){
            cout<<get(check[i][1],check[i][2],1,N,1)<<"\n";
        }
        if(check[i][0] == 1){
            int64_t dif = check[i][2]-arr[check[i][1]];
            arr[check[i][1]] = check[i][2];
            change(check[i][1],dif,1,N,1);
        }
        
    }
}
