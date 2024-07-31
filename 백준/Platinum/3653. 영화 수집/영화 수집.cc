//3653

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int arr[100010];
int seg[800010];

void make_segtree(int lo, int hi, int idx){
    if(lo == hi){
        if(lo <= N) seg[idx] = 1;
        else seg[idx] = 0;
        return;
    }
    int mid = (lo+hi)/2;
    make_segtree(lo, mid, idx*2+1);
    make_segtree(mid+1, hi, idx*2+2);
    
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
}

int find_segtree(int lo, int hi, int idx, int l, int r){
    if(hi < l || r < lo) return 0;
    if(l <= lo && hi <= r) return seg[idx];
    
    int mid = (lo+hi)/2;
    return find_segtree(lo, mid, idx*2+1, l, r)+find_segtree(mid+1,hi, idx*2+2, l, r);
}

void remove_segtree(int lo, int hi, int idx, int findidx){
    if(lo == hi){
        seg[idx] = 0;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx < mid+1){
        remove_segtree(lo,mid,idx*2+1,findidx);
    }
    else{
        remove_segtree(mid+1,hi,idx*2+2,findidx);
    }
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
    return;
}

void insert_segtree(int lo, int hi, int idx, int findidx){
    if(lo == hi){
        seg[idx] = 1;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx < mid+1){
        insert_segtree(lo,mid,idx*2+1,findidx);
    }
    else{
        insert_segtree(mid+1,hi,idx*2+2,findidx);
    }
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
    return;
}

int main(){
    FastIO;
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        cin>>N>>M;
        make_segtree(1,N+M,0);
        for(int i = 1 ; i <= N ; i++)
            arr[i] = N-i+1;

        int n1;
        for(int j = 1 ; j <= M ; j++){
            cin>>n1;
            cout<<find_segtree(1,N+M,0,arr[n1]+1,N+M)<<" ";
            remove_segtree(1,N+M,0,arr[n1]);
            insert_segtree(1,N+M,0,N+j);
            arr[n1] = N+j;
        }
        cout<<"\n";
    }
}