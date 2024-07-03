#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N,M;
char arr[16];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < M ; i++)
        cin>>arr[i];
    sort(arr,arr+M);
}

char n_arr[16];
void make(int idx, int remain){
    if(idx == N){
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            if(n_arr[i] == 'a' || n_arr[i] == 'e' || n_arr[i] == 'i' || n_arr[i] == 'o' || n_arr[i] == 'u' ) cnt++;
        }
        if(cnt < 1 || N-cnt < 2) return;
        
        for(int i = 0 ; i < N ; i++){
            cout<<n_arr[i];
        }
        cout<<"\n";
        return ;
    }
    
    for(int i = remain+1 ; i < M ; i++){
        n_arr[idx] = arr[i];
        make(idx+1,i);
    }
}
int main(void){
    input();
    make(0,-1);
}