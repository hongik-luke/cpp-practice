#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N;
int arr[1010];
int cashe[1010];

void input(){
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
}
int get(int idx){
    int& ret = cashe[idx+1];
    if(ret != -1) return ret;
    
    ret = 1;
    
    for(int next = idx+1; next < N; next++){
        if(idx == -1 || arr[next] > arr[idx])
            ret = max(ret, get(next)+1);
    }   
    
    return ret;
}

int main(void){
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<get(-1)-1;
}