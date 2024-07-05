#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int arr[100010];
int animal[100010][2];
int N,M,L;
void input(){
    cin>>N>>M>>L;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    for(int i = 0 ; i < M ; i++){
        cin>>animal[i][0]>>animal[i][1];
    }
}
int get(){
    int ret = 0;
    int nowL = L;
    for(int i = 0 ; i < M ; i++){
        nowL = L - animal[i][1];
        if(nowL < 0) continue;
        
        int lo = 0;
        int hi = N-1;
        int mid;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if(arr[mid] == animal[i][0]){
                lo = mid;
                break;
            }
            else if(arr[mid] > animal[i][0]){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        int nowmin = 1000000001;
        if(lo-1 >= 0 && lo-1 < N) nowmin = min(nowmin,abs(animal[i][0]-arr[lo-1]));
        if(lo >= 0 && lo < N) nowmin = min(nowmin,abs(animal[i][0]-arr[lo]));
        if(lo+1 >= 0 && lo+1 < N) nowmin = min(nowmin,abs(animal[i][0]-arr[lo+1]));
        
        if(nowL >= nowmin){
            ret++;
        }
    }
    return ret;
}
int main(void){
    input();
    cout<<get();
}