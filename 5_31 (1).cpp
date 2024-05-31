#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int N,K;
int arr[100000];
int mingap = 200000;
void input(){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++)
        cin>>arr[i];
    
}
void getresult(){
    int lo = 0; int hi = 1;
    int hap = arr[1];
    while(1){
        if(hap >= K){
            mingap = min(mingap,hi-lo+1);
            hap -= arr[lo];
            lo++;
        }
        else{
            if(hi == N) break;
            hi++;
            hap += arr[hi];
        }
    }
    return ;
}
int main(void){
    input();
    getresult();
    if(mingap >= 100000) cout<<0;
    else cout<<mingap;
}
