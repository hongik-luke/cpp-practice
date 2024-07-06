#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
int arr[100001];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N;  i++){
        cin>>arr[i];
    }
}
bool check(int num){
    int now = 0;
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        now += arr[i];
        
        if(now >= num){
            now = 0;
            cnt++;
        }
    }
    if(cnt >= M) return true;
    else return false;
}
int get(){
    int lo = 0; int hi = 2000001;
    int mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(check(mid)){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    return lo-1;
    
}
int main(void){
    input();
    cout<<get();
    
}