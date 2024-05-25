#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int64_t N,K;
int arr[10010];

void input(){
    cin>>N>>K;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}
int64_t howmany(int n){
    int64_t returnnum = 0;
    if(n == 0) return 1000001;
    for(int i = 0 ; i < N ; i++){
        returnnum += arr[i]/n;
    }
    return returnnum;
}


int find(){
    int64_t lo = 1; int64_t hi = 100000000000;
    int64_t mid;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(howmany(mid) < K)
            hi = mid;
        else
            lo = mid+1;
    }
    return lo-1;
}


int main(void){
    input();
    cout<<find();
}