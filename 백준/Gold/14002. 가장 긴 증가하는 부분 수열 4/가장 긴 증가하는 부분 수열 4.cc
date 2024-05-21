#include <iostream>
#include <algorithm>
#include <cstring>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int arr[1010];
int cashe[1010];
int N;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++)
        cin>>arr[i];
    memset(cashe,-1,sizeof(cashe));
}

int getlis(int start){
    int& ret = cashe[start+1];
    if(ret != -1) return ret;
    ret = 1;
    for(int next = start+1 ; next < N ; next++){
        if(start == -1 || arr[start] < arr[next]){
            ret = max(ret, getlis(next) + 1);
        }
    }
    return ret;
}


void getresult(){
    int result = getlis(-1)-1;
    int resultidx;
    
    cout<<result<<"\n";

    for(int i = 1 ; i <= N ; i++)
        if(result == cashe[i]) resultidx = i-1;
        
    cout<<arr[resultidx]<<" ";
    result--;
    for(int i = resultidx ; i < N ; i++){
        if(result == cashe[i+1] && arr[resultidx] < arr[i]){
            resultidx = i;
            result--;
            cout<<arr[resultidx]<<" ";
        }
    }
}

int main(void){
    input();
    getresult();
}
