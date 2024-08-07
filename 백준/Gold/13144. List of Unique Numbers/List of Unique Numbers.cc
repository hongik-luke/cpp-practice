#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;
int N;
int arr[100100];
int check[100100];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}

int main() {
    FastIO;
    input();
    memset(check,0,sizeof(check));
    int64_t cnt = 0;
    int lo = 0;
    for(int hi = 0 ; hi < N ; hi++){
        if(check[arr[hi]] != 0){
            while(check[arr[hi]] != 0){
                check[arr[lo]]--;
                lo++;
            }
        }
        check[arr[hi]] = true;
        cnt += hi-lo+1;
    }
    cout<<cnt;
}