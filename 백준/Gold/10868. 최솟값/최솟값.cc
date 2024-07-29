#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int arr[100010];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}
int min_segtree[400000];
void make_min_segtree(int lo ,int hi , int idx){
    if(lo == hi){
        min_segtree[idx] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    make_min_segtree(lo,mid,idx*2);
    make_min_segtree(mid+1,hi,idx*2+1);

    min_segtree[idx] = min(min_segtree[idx*2],min_segtree[idx*2+1]);
    return ;
}

int get_min(int lo , int hi ,int l ,int r , int idx){
    if(l <= lo && hi <= r){
        return min_segtree[idx];
    }
    else if(hi < l || r < lo){
        return 2000000000;
    }
    int mid = (lo+hi)/2;
    return min(get_min(lo,mid,l,r,idx*2), get_min(mid+1,hi,l,r,idx*2+1));
    
}

void print(){
    int n1,n2;
    for(int i = 1 ; i <= M ; i++){
        cin>>n1>>n2;
        n1--;
        n2--;
        cout<<get_min(0,N-1,n1,n2,1)<<"\n";
    }
}
int main(){
    FastIO;
    input();
    make_min_segtree(0, N-1, 1);
    print();
}