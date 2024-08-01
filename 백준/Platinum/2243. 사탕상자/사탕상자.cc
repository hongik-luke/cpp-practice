#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N;
int seg[3000010];
void insert(int lo ,int hi, int idx, int findidx, int num){
    if(lo == hi){
        seg[idx] += num;
        return;
    }
    int mid = (lo+hi)/2;
    if(findidx <= mid)
        insert(lo,mid,idx*2+1,findidx,num);
    else
        insert(mid+1,hi,idx*2+2,findidx,num);
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
}
void get_n_delete(int lo ,int hi, int idx, int num){
    if(lo == hi){
        seg[idx]--;
        cout<<lo<<"\n";
        return;
    }
    int mid = (lo+hi)/2;
    if(num <= seg[idx*2+1])
        get_n_delete(lo,mid,idx*2+1,num);
    else
        get_n_delete(mid+1,hi,idx*2+2,num-seg[idx*2+1]);
    seg[idx] = seg[idx*2+1]+seg[idx*2+2];
    
}
void get_result(){
    int N;
    cin>>N;
    int n1,n2,n3;
    for(int i = 1 ; i <= N ; i++){
        cin>>n1;
        if(n1 == 1){
            cin>>n2;
            get_n_delete(1,1000000,0,n2);
        }
        else{
            cin>>n2>>n3;
            insert(1,1000000,0,n2,n3);
        }
    }
}

int main(){
    FastIO;
    get_result();
}