#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
char c_arr[13];
void input(){
    cin>>N;
    for(int i = 0 ; i < N;  i++)
        cin>>c_arr[i];
}
bool check[12];


int max_arr[12];
bool getmax(int idx, int before){
    if(idx == N+1) return true;
    
    if(idx == 0){
        for(int i = 9 ; i >= 0 ; i--){
            max_arr[idx] = i;
            check[i] = true;
            if(getmax(idx+1,i)) return true;
            check[i] = false;
        }
    }
    
    if(c_arr[idx-1] == '>'){
        for(int i = 9 ; i >= 0 ; i--){
            if(check[i] || max_arr[idx-1] <= i) continue;
            max_arr[idx] = i;
            check[i] = true;
            if(getmax(idx+1,i)) return true;
            check[i] = false;
        }
        return false;
    }
    else{
        for(int i = 9 ; i >= 0 ; i--){
            if(check[i] || max_arr[idx-1] >= i) continue;
            max_arr[idx] = i;
            check[i] = true;
            if(getmax(idx+1,i)) return true;
            check[i] = false;
        }
        return false;
    }
    
}

int min_arr[12];
bool getmin(int idx, int before){
    if(idx == N+1) return true;
    
    if(idx == 0){
        for(int i = 0 ; i <= 9 ; i++){
            min_arr[idx] = i;
            check[i] = true;
            if(getmin(idx+1,i)) return true;
            check[i] = false;
        }
    }
    
    if(c_arr[idx-1] == '>'){
        for(int i = 0 ; i <= 9 ; i++){
            if(check[i] || min_arr[idx-1] <= i) continue;
            min_arr[idx] = i;
            check[i] = true;
            if(getmin(idx+1,i)) return true;
            check[i] = false;
        }
        return false;
    }
    else{
        for(int i = 0 ; i <= 9 ; i++){
            if(check[i] || min_arr[idx-1] >= i) continue;
            min_arr[idx] = i;
            check[i] = true;
            if(getmin(idx+1,i)) return true;
            check[i] = false;
        }
        return false;
    }
    
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    getmax(0,-1);
    for(int i = 0 ; i <= N;  i++)
        cout<<max_arr[i];
    
    cout<<"\n";
    memset(check,false,sizeof(check));
    getmin(0,-1);
    for(int i = 0 ; i <= N;  i++)
        cout<<min_arr[i];
}