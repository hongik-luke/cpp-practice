#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int main(void){
    int64_t N,M;
    cin>>N>>M;
    if(N == M) cout<<-1;
    else{
        int t = (M*100) / N;
        int64_t lo = 0; 
        int64_t hi = 10000000000;
        int64_t mid;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(((M+mid)*100) / (N+mid) != t )
                hi = mid-1;
            else
                lo = mid+1;
        }
        if(((M+lo)*100) / (N+lo) != t ) cout<<lo;
        else cout<<-1;
    }
}