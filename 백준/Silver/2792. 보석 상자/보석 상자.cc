#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int arr[1000001];

int N,M;
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < M ; i++)
        cin>>arr[i];

}

bool check(int num){
    int cnt = 0;
    for(int i = 0 ; i < M ; i++){
        if(arr[i]%num == 0){
            cnt += arr[i]/num;
        }
        else{
            cnt += (arr[i]/num +1);
        }
    }
    if(N >= cnt) return true;
    else return false;
}

int get(){
    int lo = 1; int hi = 1000000000;
    int mid;
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