#include <iostream>
#include <algorithm>
#include <cstring>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int IMF = -9876543;
int N,M;
int cashe[1005][1005];
int num[1005];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        cin>>num[i];
    }
}
int getresult(int idx, int remainspace){
    if(idx == N) return 0;
    
    int& ret = cashe[idx][remainspace];
    if(ret != -1) return ret;
    
    ret = remainspace*remainspace + getresult(idx+1,M-num[idx]);
    if(remainspace >= num[idx]+1)
        ret = min(ret, getresult(idx+1,remainspace-(1+num[idx])));
    
    return ret;
}

int main(void){
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<getresult(1,M-num[0]);
}