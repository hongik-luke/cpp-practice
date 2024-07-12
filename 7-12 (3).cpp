#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int dx[] = {0,0,0,-1,1};
int dy[] = {0,-1,1,0,0};
int bitarr[10];
int min_press = 9876;
void input(){
    string str;
    for(int i = 0 ; i < 10 ; i++){
        cin>>str;
        for(int j = 0 ; j < 10 ; j++){
            if(str[j] == 'O') bitarr[i] += (1<<j);
        }
    }
}
void press(int arr[] ,int x, int y){
    for(int i = 0 ; i < 5 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > 9 || ny < 0 || ny > 9) continue;
        
        if((arr[nx] & (1<<ny)) != 0) arr[nx] -= (1<<ny);
        else arr[nx] += (1<<ny);
    }
}
void get_else(int arr[], int idx, int cnt){
    if(idx == 10){
        for(int i = 0 ; i < 10 ; i++){
            if(arr[i] != 0) return;
        }
        min_press = min(min_press, cnt);
        return;
    }
    
    int n_cnt = 0;
    for(int i = 0 ; i < 10 ; i++){
        if((arr[idx-1] & (1<<i)) != 0){
            press(arr,idx,i);
            n_cnt++;
        }
    }
    get_else(arr,idx+1,cnt+n_cnt);
}

void get_first(){
    int arr[10];
    for(int i = 0 ; i < (1<<10) ; i++){
        for(int j = 0 ; j < 10 ; j++){
            arr[j] = bitarr[j];
        }

        int cnt = 0;
        for(int j = 0 ; j < 10 ; j++){
            if((i & (1<<j)) != 0){
                press(arr,0,j);
                cnt++;
            }
        }
        get_else(arr,1,cnt);
    }
}
int main(void){
    input();
    get_first();
    if(min_press > 100) cout<<-1;
    else cout<<min_press;
}