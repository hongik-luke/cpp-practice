#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N;
int arr[500010];
map <int,int> m;
int64_t seg[2000010];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++){
        cin>>arr[i];
        m.insert({arr[i],i});
    }
    
}

void insert_seg(int lo ,int hi, int idx, int findidx){
    if(lo == hi){
        seg[idx] = 1;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx <= mid)
        insert_seg(lo,mid,idx*2+1,findidx);
    else
        insert_seg(mid+1,hi,idx*2+2,findidx);
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
}
int64_t find_seg(int lo ,int hi, int idx, int l ,int r){

    if(hi < l || r < lo){
        return 0;
    }
    if(l <= lo && hi <= r){
        return seg[idx];
    }
    int mid = (lo+hi)/2;
    return find_seg(lo,mid,idx*2+1,l,r)+find_seg(mid+1,hi,idx*2+2,l,r);
}
int64_t get_result(){
    int64_t ret = 0;
    int n1;
    for(int i = 1 ; i <= N ; i++){
        cin>>n1;
        int now = m.find(n1)->second;
        insert_seg(1,N,0,now);
        ret += find_seg(1,N,0,now+1,N);
    }
    return ret;
}

int main(){
    FastIO;
    input();
    cout<<get_result();
}