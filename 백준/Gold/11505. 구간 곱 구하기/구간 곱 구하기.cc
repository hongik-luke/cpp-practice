#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int64_t mod = 1000000007;
int64_t arr[1000010];
void input(){
    int n1,n2;
    cin>>N>>n1>>n2;
    M = n1+n2;
    for(int i = 1 ; i <= N ; i++)
        cin>>arr[i];
}
int64_t seg[4000010];
void make_segtree(int lo, int hi, int idx){
    if(lo == hi){
        seg[idx] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    make_segtree(lo, mid, idx*2+1);
    make_segtree(mid+1, hi, idx*2+2);
    
    seg[idx] = seg[idx*2+1]*seg[idx*2+2]%mod;
    
    return;
}
void change_segtree(int lo, int hi ,int idx, int findidx, int num){
    if(lo == hi && lo == findidx){
        seg[idx] = num;
        return;
    }
    int mid = (lo+hi)/2;
    if(lo <= findidx && findidx <= mid)
        change_segtree(lo, mid, idx*2+1, findidx, num);
    else
        change_segtree(mid+1, hi, idx*2+2, findidx, num);
    
    seg[idx] = seg[idx*2+1]*seg[idx*2+2]%mod;
    
    return;
}
int64_t find_segtree(int lo, int hi ,int l, int r, int idx){
    if(l <= lo && hi <= r) return seg[idx];
    if(r < lo || hi < l) return 1;
    int mid = (lo+hi)/2;
    return find_segtree(lo,mid,l,r,idx*2+1)*find_segtree(mid+1,hi,l,r,idx*2+2)%mod;
}
void print(){
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        if(n1 == 1){
            change_segtree(1,N,0,n2,n3);
        }
        else{
            cout<<find_segtree(1,N,n2,n3,0)<<"\n";
        }
    }
}
int main(){
    FastIO;
    input();
    make_segtree(1,N,0);
    print();
}