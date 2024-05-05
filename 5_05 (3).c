#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;


int N;
int numarr[20010];

void get(){
    
    cin>>N;
    numarr[0] = -1;
    for(int i = 1 ; i <= N ; i++)
        cin>>numarr[i];
    numarr[N+1] = -1;
}

int getresult(int startidx, int lastidx){
    if(startidx == lastidx)
        return numarr[startidx];
        
    int mididx = (startidx+lastidx)/2;
    int ret = max(getresult(startidx,mididx),getresult(mididx+1,lastidx));
    
    int nowmin = min(numarr[mididx], numarr[mididx+1]);
    int nowstartidx = mididx;
    int nowlastidx = mididx+1;
    
    while(nowstartidx > 0 && nowlastidx < N+1){
        
        if(numarr[nowstartidx-1] > numarr[nowlastidx+1]){
            nowmin = min(nowmin,numarr[--nowstartidx]);
        }
        else{
            nowmin = min(nowmin,numarr[++nowlastidx]);
        }
        if(nowstartidx == 0 || nowlastidx == N+1) break;
        
        ret = max(ret, (nowlastidx - nowstartidx +1)*nowmin);
    }
    
    return ret;
}

int main(void){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int TESTCASE; 
    cin>>TESTCASE;
    for(int i = 0; i < TESTCASE ; i++){
        get();
        cout<<getresult(1,N)<<"\n";
    }
}







