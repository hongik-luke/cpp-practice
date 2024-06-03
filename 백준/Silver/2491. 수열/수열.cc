#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int N;
int arr[100010];
int ret = 0;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}
void get_smaller(int idx, int now){
    if(idx == N-1){
        ret = max(ret, now);
        return;
    }
    
    if(arr[idx] >= arr[idx+1]) get_smaller(idx+1,now+1);
    else{
        ret = max(ret, now);
        get_smaller(idx+1,1);
    }
    return;
}

void get_bigger(int idx, int now){
    if(idx == N-1){
        ret = max(ret, now);
        return;
    }
    
    if(arr[idx] <= arr[idx+1]) get_bigger(idx+1,now+1);
    else{
        ret = max(ret, now);
        get_bigger(idx+1,1);
    }
    return;
}



int main(void){
    input();
    get_smaller(0,1);
    get_bigger(0,1);
    cout<<ret;
}