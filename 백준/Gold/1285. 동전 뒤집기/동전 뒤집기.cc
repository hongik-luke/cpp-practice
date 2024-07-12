#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
int ori[20];
void input(){
    cin>>N;
    string str;
    for(int i = 0 ; i < N ; i++){
        cin>>str;
        for(int j = 0 ; j < N ; j++){
            if(str[j] == 'T') ori[i] += (1<<j);
        }
    }
    
}
int get(){
    int arr[20];
    int min_cnt = 9876543;
    for(int i = 0 ; i < (1<<N) ; i++){
        for(int j = 0 ; j < N ; j++){
            arr[j] = ori[j];
        }
        
        for(int j = 0 ; j < N ; j++){
            if((i & (1<<j)) != 0){
                arr[j] = (1<<N) -1 -arr[j];
                
            }
        }
        
        int cnt = 0;
        for(int j = 0 ; j < N ; j++){
            int in_cnt = 0;
            for(int k = 0 ; k < N ; k++){
                if((arr[k] & (1<<j)) != 0){
                    in_cnt++;
                }
            }
            cnt += min(N-in_cnt,in_cnt);
        }
        min_cnt = min(min_cnt,cnt);
    }
    return min_cnt;
}
int main(void){
    input();
    cout<<get();
}