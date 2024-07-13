#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};
int N;
int bit[20];
void input(){
    cin>>N;
    
    int n1;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>n1;
            if(n1 == 1) bit[i] += (1<<j);
        }
    }
    
}
void press(int arr[], int x, int y){
    for(int i = 0; i < 5 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > N-1 || ny < 0 || ny > N-1) continue;
        if((arr[nx]&(1<<ny)) != 0) arr[nx] -= (1<<ny);
        else arr[nx] += (1<<ny);
    }
}
int get_else(int idx, int arr[]){
    if(idx == N){
        for(int i = 0 ; i < N ; i++){
            if(arr[i] != 0) return 98765;
        }
        return 0;
    }
    int cnt = 0;
    for(int i = 0 ; i < N ; i++){
        if((arr[idx-1] & (1<<i)) != 0){
            press(arr,idx,i);
            cnt++;
        }
    }
    return cnt + get_else(idx+1,arr);
}
int get(){
    int len = (1<<N);
    int min_ret = 98765;
    int arr[20];
    for(int i = 0 ; i < len ; i++){
        for(int j = 0; j < N ; j++){
            arr[j] = bit[j];
        }
        int cnt = 0;
        for(int j = 0; j < N ; j++){
            if( (i&(1<<j)) != 0 ){
                press(arr,0,j);
                cnt++;
            }
        }
        min_ret = min(min_ret, get_else(1,arr)+cnt);
    }
    
    return min_ret;
}

int main(void){
    input();
    int ret = get();
    if(ret > 500) cout<<-1;
    else cout<<ret; 
}