#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
int arr[100001];
int minseg[400001];
int maxseg[400001];

void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N; i++){
        cin>>arr[i];
    }
}
int make_minseg(int idx, int lo, int hi){
    if(lo == hi){
        minseg[idx] = arr[lo];
        return minseg[idx];
    }
    int mid = (lo+hi)/2;
    minseg[idx] = min( make_minseg(idx*2,lo,mid), make_minseg(idx*2+1,mid+1,hi) );
    
    return minseg[idx];
}

int make_maxseg(int idx, int lo, int hi){
    if(lo == hi){
        maxseg[idx] = arr[lo];
        return maxseg[idx];
    }
    int mid = (lo+hi)/2;
    maxseg[idx] = max( make_maxseg(idx*2,lo,mid), make_maxseg(idx*2+1,mid+1,hi) );
    
    return maxseg[idx];
}

int n1,n2;
int get_min(int idx, int lo, int hi){
    if(n1 <= lo && hi <= n2){
        return minseg[idx];
    }
    else if(hi < n1 || n2 < lo){
        return 1000000001;
    }
    else{
        int mid = (lo+hi)/2;
        return min(get_min(idx*2,lo,mid),get_min(idx*2+1,mid+1,hi));
    }
}

int get_max(int idx, int lo, int hi){
    if(n1 <= lo && hi <= n2){
        return maxseg[idx];
    }
    else if(hi < n1 || n2 < lo){
        return 0;
    }
    else{
        int mid = (lo+hi)/2;
        return max(get_max(idx*2,lo,mid),get_max(idx*2+1,mid+1,hi));
    }
}
void result(){
    for(int i = 0 ; i < M; i++){
        cin>>n1>>n2;
        n1 = n1-1;
        n2 = n2-1;
        cout<<get_min(1,0,N-1)<<" "<<get_max(1,0,N-1)<<"\n";
    }
}
int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    make_minseg(1,0,N-1);
    make_maxseg(1,0,N-1);
    result();
}




