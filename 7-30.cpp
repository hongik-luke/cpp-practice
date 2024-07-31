//12844

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int arr[500010];
int seg[2000010];
int diff[2000010];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
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
    
    seg[idx] = seg[idx*2+1]^seg[idx*2+2];
}
void update(int lo, int hi, int idx){
    if(diff[idx] != 0){
        if(((hi - lo + 1) % 2) == 1) seg[idx] ^= diff[idx];
        if(lo != hi){
            diff[idx*2+1] = diff[idx*2+1]^diff[idx];
            diff[idx*2+2] = diff[idx*2+2]^diff[idx];
        }
        diff[idx] = 0;
    }
}
void change_segtree(int lo, int hi, int idx, int l, int r, int num){
    update(lo,hi,idx);
    if(hi < l || r < lo) return;
    if(l <= lo && hi <= r){
        diff[idx] = diff[idx]^num;
        update(lo,hi,idx);
        return;
    }
    
    int mid = (lo+hi)/2;
    change_segtree(lo, mid, idx*2+1, l, r, num);
    change_segtree(mid+1, hi, idx*2+2, l, r, num);
    
    seg[idx] = seg[idx*2+1]^seg[idx*2+2];
    return;
}

int find_segtree(int lo, int hi, int idx, int l, int r){
    update(lo,hi,idx);
    if(hi < l || r < lo) return 0;
    if(l <= lo && hi <= r) return seg[idx];
    
    int mid = (lo+hi)/2;

    return find_segtree(lo, mid, idx*2+1, l, r)^find_segtree(mid+1,hi, idx*2+2, l, r);
}
void print(){
    int n1,n2,n3,n4;
    for(int i = 0 ; i < M ; i++){
        cin>>n1;
        if(n1 == 1){
            cin>>n2>>n3>>n4;
            change_segtree(0,N-1,0,n2,n3,n4);
        }
        else{
            cin>>n2>>n3;
            cout<<find_segtree(0,N-1,0,n2,n3)<<"\n";
        }
    }
}
int main(){
    FastIO;
    input();
    memset(diff,0,sizeof(diff));
    make_segtree(0,N-1,0);
    print();
}