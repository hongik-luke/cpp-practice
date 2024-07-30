#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int64_t arr[100010];
int64_t seg[400010];
int64_t diff[400010];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++)
        cin>>arr[i];
    cin>>M;
}

void make_segtree(int lo, int hi, int idx){
    if(lo == hi){
        seg[idx] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    make_segtree(lo, mid, idx*2+1);
    make_segtree(mid+1, hi, idx*2+2);
    
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
}
void update(int lo, int hi, int idx){
    if(diff[idx] != 0){
        seg[idx] += (hi-lo+1)*diff[idx];
        if(lo != hi){
            diff[idx*2+1] += diff[idx];
            diff[idx*2+2] += diff[idx];
        }
        diff[idx] = 0;
    }
}
void plus_segtree(int lo, int hi, int idx, int l, int r, int num){
    if(hi < l || r < lo) return;
    if(l <= lo && hi <= r){
        diff[idx] += num;
        update(lo,hi,idx);
        return;
    }
    
    int mid = (lo+hi)/2;
    plus_segtree(lo, mid, idx*2+1, l, r, num);
    plus_segtree(mid+1, hi, idx*2+2, l, r, num);
    return;
}

int64_t find_segtree(int lo, int hi, int idx, int findidx){
    update(lo,hi,idx);
    
    if(lo == hi) return seg[idx];
    
    int mid = (lo+hi)/2;
    if(lo <= findidx && findidx <= mid)
        return find_segtree(lo,mid,idx*2+1,findidx);
    else
        return find_segtree(mid+1,hi,idx*2+2,findidx);
}
void print(){
    memset(diff,0,sizeof(diff));
    int n1,n2,n3,n4;
    for(int i = 0 ; i < M ; i++){
        cin>>n1;
        if(n1 == 1){
            cin>>n2>>n3>>n4;
            plus_segtree(1,N,0,n2,n3,n4);
        }
        else{
            cin>>n2;
            cout<<find_segtree(1,N,0,n2)<<"\n";
        }
    }
}
int main(){
    FastIO;
    input();
    make_segtree(1,N,0);
    print();
}