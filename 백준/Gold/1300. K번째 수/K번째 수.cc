#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N,K;

int getone(int now){
    int result = 0;
    for(int j = 1 ; j <= N ; j++) 
        result += min(N, now/j);

    return result;
}

int getresult(){
    int lo = 0; int hi = 1e9+1;
    int mid;
    
    while(lo < hi){
        mid = (lo + hi) / 2;

        if(getone(mid) >= K)
            hi = mid;
        else
            lo = mid+1;
        
    }
    return lo;
}

int main(void){
    cin>>N>>K;
    cout<<getresult();
}