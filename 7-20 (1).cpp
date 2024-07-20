#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int N,M;
int64_t cashe[17][(1<<15)][17];

int64_t get(int start, int bit, int layer){
    if(layer == 0)
        cout<<bit<<" "<<layer<<"\n";
    if(layer > M-1) return 0;
    if(bit == 0 && layer == M-1) return 1;
    
    if(cashe[start+1][bit][layer] != -1) return cashe[start+1][bit][layer];
    int64_t& ret = cashe[start+1][bit][layer];
    ret = 0;

    for(int i = start+1 ; i < N-1 ; i++){
        if((bit& (1<<i)) != 0 && (bit& (1<<(i+1))) != 0){
            ret += get(i+1,bit-(1<<i)-(1<<(i+1)), layer);
        }
    }
    
    ret += get(-1,(1<<N)-1 - bit ,layer+1);
    ret = ret % 9901;
    return ret;
}



int main() {
    cin>>N>>M;
    memset(cashe,-1,sizeof(cashe));
    cout<<get(-1,(1<<N)-1,0);
}