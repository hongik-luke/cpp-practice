#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
int n1,n2,n3,n4;
int arr[100001];
int64_t seg[400000];
void input(){
    int a1,a2;
    cin>>N>>M;
    for(int i = 0 ; i < N; i++){
        cin>>arr[i];
    }
}
int64_t get_seg(int idx, int lo, int hi){
    if(lo == hi){
        seg[idx] = arr[lo];
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    seg[idx] = get_seg(idx*2,lo,mid) + get_seg(idx*2+1,mid+1,hi);
    return seg[idx];
}


int64_t get(int idx, int lo, int hi){
    if(n1 <= lo && hi <= n2){
        return seg[idx];
    }
    else if(hi < n1 || n2 < lo){
        return 0;
    }
    else{
        int mid = (lo+hi)/2;
        return (get(idx*2,lo,mid) + get(idx*2+1,mid+1,hi));
    }
}

int64_t change(int idx, int lo, int hi){
    if(lo == hi){
        seg[idx] = n4;
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    
    if(lo <= n3 && n3 <= mid){
        seg[idx] = change(idx*2,lo,mid) + seg[idx*2+1];
    }
    else{
        seg[idx] = seg[idx*2] + change(idx*2+1,mid+1,hi);
    }
    
    return seg[idx];
}

void problem(){
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3>>n4;
        if(n1 > n2){
            swap(n1,n2);
        }
        n1 = n1-1;
        n2 = n2-1;
        n3 = n3-1;
        cout<<get(1,0,N-1)<<"\n";
        change(1,0,N-1);
    }
}
int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    get_seg(1,0,N-1);
    problem();
}




