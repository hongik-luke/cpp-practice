#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N,K;
int64_t seg[4000000]; 
void change_seg(int lo, int hi, int idx, int findidx, int64_t num){
    if(lo == hi){
        seg[idx] += num;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx <= mid)
        change_seg(lo,mid,idx*2+1,findidx,num);
    else
        change_seg(mid+1,hi,idx*2+2,findidx,num);
    seg[idx] = seg[idx*2+1] + seg[idx*2+2];
}
int64_t get_seg(int lo, int hi, int idx, int l ,int r){
    if(hi < l || r < lo){
        return 0;
    }
    if(l <= lo && hi <= r){
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    return get_seg(lo,mid,idx*2+1,l,r) + get_seg(mid+1,hi,idx*2+2,l,r);
}
void print(){
    int n1,n2,n3;
    for(int i  = 0 ; i < K ; i++){
        cin>>n1;
        if(n1 == 1){
            cin>>n2>>n3;
            change_seg(1,N,0,n2,n3);
        }
        else{
            cin>>n2>>n3;
            cout<<get_seg(1,N,0,n2,n3)<<"\n";
        }
    }
}
int main(){
    FastIO;
    cin>>N>>K;
    print();
}