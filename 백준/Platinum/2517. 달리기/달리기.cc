#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
pair<int,int> arr[500001];
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
bool cmp1(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
} 
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    sort(arr+1,arr+N+1,cmp);
}
int seg[2000001];
int plus_seg(int idx, int lo , int hi , int c_idx){
    if(c_idx < lo || hi < c_idx){
        return seg[idx];
    }
    if(lo == hi){
        seg[idx] += 1;
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    seg[idx] = plus_seg(idx*2,lo,mid,c_idx) + plus_seg(idx*2+1,mid+1,hi,c_idx);
    return seg[idx];
}
int get_seg(int idx, int lo , int hi, int l , int r){
    if(lo == hi){
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    if(mid < r){
        return seg[idx*2] + get_seg(idx*2+1,mid+1,hi,l,r);
    }
    else{
        return get_seg(idx*2,lo,mid,l,r);
    }
}
pair<int,int> ret[500001];
void get(){
    memset(seg,0,sizeof(seg));
    for(int i = 1 ; i <= N ; i++){
        plus_seg(1,1,N,arr[i].second);
        int idx = get_seg(1,1,N,1,arr[i].second);
        
        ret[i] = make_pair(arr[i].second,min(i,idx));
    }
    sort(ret+1,ret+N+1,cmp1);
    for(int i = 1 ; i <= N ; i++){
        cout<<ret[i].second<<"\n";
    }
}
int main(void) {
    input();
    get();
}