#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N;
int64_t arr[100010];
const int64_t M = 1000000000;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}

int64_t get(int64_t num){
    int64_t returnnum = 0;
    for(int i = 1 ; i < N ; i++){
        returnnum += abs(arr[i]-num*i);
    }
    return returnnum;
}

void result(){
    int64_t lo = 1; int64_t hi = M;
    int64_t mida,midb;
    for(int i = 0 ; i < 300 ; i++){
        mida = (2*lo + hi)/3;
        midb = (lo + 2*hi)/3;
        //cout<<lo<<" "<<mida<<" "<<midb<<" "<<hi<<"\n";
        if(get(mida) < get(midb)){
            hi = midb;
        }
        else{
            lo = mida;
        }
    }
    
    int64_t result = min(get(lo),get(mida));
    result = min(result, get(midb));
    result = min(get(midb), get(hi));
    cout<<result;
}
int main(void){
    input();
    result();
}

