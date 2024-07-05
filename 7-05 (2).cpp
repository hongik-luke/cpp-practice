#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
uint64_t arr[100001];
uint64_t N,M;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++)
        cin>>arr[i];

}

bool check(uint64_t num){
    uint64_t cnt = 0;
    for(int i = 0 ; i < N ; i++){
        cnt += num/arr[i];
    }
    if(M <= cnt) return true;
    else return false;
}

uint64_t get(){
    uint64_t lo = 0; uint64_t hi = 8000000000000000000;
    uint64_t mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return lo;
}

int main(void){
    input();
    cout<<get();
}