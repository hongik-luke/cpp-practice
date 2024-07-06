#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
int arr[1000001];
int seg[4000000];
void input(){
    int a1,a2;
    cin>>N>>a1>>a2;
    M = a1+a2;
    for(int i = 0 ; i < N; i++){
        cin>>arr[i];
    }
}
int get_seg(int idx, int lo, int hi){
    if(lo == hi){
        seg[idx] = arr[lo];
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    int64_t num = get_seg(idx*2,lo,mid);
    num = (num*get_seg(idx*2+1,mid+1,hi)) % 1000000007;
    seg[idx] = num;
    return seg[idx];
}
int n1,n2,n3;
int change(int idx, int lo, int hi){
    if(lo == n2 && hi == n2){
        seg[idx] = n3;
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    int64_t num;
    if(lo <= n2 && n2 <= mid){
        num = change(idx*2,lo,mid);
        num = (num*seg[idx*2+1]) % 1000000007;
    }
    else if(mid+1 <= n2 && n2 <= hi){
        num = seg[idx*2];
        num = (num*change(idx*2+1,mid+1,hi)) % 1000000007;
    }
    seg[idx] = num;
    return seg[idx];
}
int get(int idx, int lo, int hi){
    
    if(n2 <= lo && hi <= n3) return seg[idx];
    else if(hi < n2 || n3 < lo) return 1;
    else{
        int mid = (lo+hi)/2;
        int64_t num;
        num = get(idx*2,lo,mid);
        num = (num*get(idx*2+1,mid+1,hi)) % 1000000007;
        return num;
    }
}

void problem(){
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        if(n1 == 1){
            n2 = n2-1;
            change(1,0,N-1);
        }
        else{
            n2 = n2-1;
            n3 = n3-1;
            cout<<get(1,0,N-1)<<"\n";
        }
    }
}
int main(void){
    input();
    get_seg(1,0,N-1);
    problem();
}




