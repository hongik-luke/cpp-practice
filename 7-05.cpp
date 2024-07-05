#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int arr[1000001];
int man[1000001];
int N,M;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < M ; i++)
        cin>>arr[i];
    sort(arr,arr+M);
}

bool check(int num){
    int cnt = 0;
    for(int i = 0 ; i < M ; i++)
        cnt += arr[i]/num;
    if(cnt >= N) return true;
    else return false;
}

int get(){
    int lo = 1; int hi = 1000000000;
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