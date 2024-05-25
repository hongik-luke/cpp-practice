#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int N;
int arr[100010];
const int64_t M = 1000000000;
void input(){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
}

int64_t get(int num){
    int64_t returnnum = 0;
    
    for(int i = 1 ; i < N ; i++){
        returnnum += abs(arr[i]-num*i);
    }
    return returnnum;
}

int result(){
    int lo = 1; int hi = M/N+1;
    int mida,midb;
    for(int i = 0 ; i < 100 ; i++){
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
    
    return get(midb);
}
int main(void){
    input();
    cout<<result();
}