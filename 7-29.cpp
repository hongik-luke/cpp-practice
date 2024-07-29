#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);

using namespace std;
int N;
int64_t arr[100010];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>arr[i];
}
int64_t maxret =  0;
void print(int lo ,int hi){
    if(lo == hi){
        maxret = max(maxret, arr[lo]*arr[lo]);
        return;
    }
    int mid = (lo+hi)/2;
    
    int l = mid-1; int r = mid+1;
    int64_t hap = arr[mid]; int64_t nowmin = arr[mid];
    while(1){
        maxret = max(maxret,hap*nowmin);
        if(l < lo || hi < r) break;

        if(arr[l] >= arr[r]){
            nowmin = min(nowmin,arr[l]);
            hap += arr[l];
            l--;
        }
        else{
            nowmin = min(nowmin,arr[r]);
            hap += arr[r];
            r++;
        }
    }
    
    if(l < lo){
        while(1){
            if(hi < r) break;
            nowmin = min(nowmin,arr[r]);
            hap += arr[r];
            r++;
            maxret = max(maxret,hap*nowmin);
        }
    }
    else{
        while(1){
            if(l < lo) break;
            nowmin = min(nowmin,arr[l]);
            hap += arr[l];
            l--;
            maxret = max(maxret,hap*nowmin);
        }
    }
    
    print(lo,mid);
    print(mid+1,hi);
    return;
}
int main(){
    FastIO;
    input();
    print(0,N-1);
    cout<<maxret;
}