#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
int N;
int arr[10];
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}
int allmax = 0;
int getarr[10];
bool check[10];
void get(int nowidx){
    if(nowidx == N){
        int nowmax = 0;
        for(int i = 0 ; i < N-1 ; i++)
            nowmax += abs(getarr[i] - getarr[i+1]);
        
        allmax = max(allmax,nowmax);
        return;
    }
    for(int i = 0 ; i < N ; i++){
        if(check[i]) continue;
        getarr[nowidx] = arr[i];
        check[i] = true;
        get(nowidx+1);
        check[i] = false;
    }
    
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    get(0);
    cout<<allmax;
}