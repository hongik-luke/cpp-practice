#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;
int N,M;
int arr[1000100];
void input(){
    N = N*10000000;
    cin>>M;
    for(int i = 0 ; i < M ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+M);
}

int main() {
    FastIO;
    while(cin>>N){
        N = N*10000000;
        cin>>M;
        for(int i = 0 ; i < M ; i++){
            cin>>arr[i];
        }
        sort(arr,arr+M);
        
        int lo = 0 ; int hi = M-1;
        bool success = false;
        while(lo < hi){
            if(arr[lo] + arr[hi] == N){
                success = true;
                break;
            }
            else if(arr[lo] + arr[hi] > N)
                hi--;
            else
                lo++;
        }   
        if(!success) cout<<"danger"<<"\n";
        else cout<<"yes "<<arr[lo]<<" "<<arr[hi]<<"\n";
    }
}