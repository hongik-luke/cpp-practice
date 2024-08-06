#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

using namespace std;
int N,d,k,c;
int arr[3000100];
int cnt[3010];
void input(){
    cin>>N>>d>>k>>c;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}

int main() {
    FastIO;
    input();
    int max_ret = 1;
    int now = 1;
    for(int i = 0 ; i < k ; i++){
        if(cnt[arr[i]] == 0 && arr[i] != c){
            now++; 
            max_ret++;
        }
        cnt[arr[i]]++;
    }
    for(int i = k ; i < N+k ; i++){
        if(cnt[arr[i-k]] == 1 && arr[i-k] != c){
            now--;
        }
        cnt[arr[i-k]]--;
        if(cnt[arr[(i)%N]] == 0 && arr[(i)%N] != c){
            now++;
        }
        cnt[arr[(i)%N]]++;
        
        max_ret = max(now, max_ret);
    }
    cout<<max_ret;
}